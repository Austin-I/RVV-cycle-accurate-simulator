// by Austin

#ifndef VREG_HH
#define VREG_HH

// 32 vector registers in RVV
#define NUM_VREGS 32

#include <vector>
#include <memory>

class vreg{
public:
    // Constructor
    vreg(size_t _elen) : m_vlen_bytes(_elen / 8), m_data(std::make_unique<uint8_t[]>(m_vlen_bytes))
    {
        // .get() returns a pointer
        std::memset(m_data.get(), 0, m_vlen_bytes);
    }

    // Return pointer to data
    uint8_t* data() {
        return m_data.get();
    }

    const uint8_t* data() const {
        return m_data.get();
    }

    // Return size of the register in bytes
    size_t getSize() {
        return m_vlen_bytes;
    }
    const size_t getSize() const {
        return m_vlen_bytes;
    }

    template<typename T>
    T& at(size_t index) {
        size_t offset = sizeof(T) * index;

        if ((offset + sizeof(T)) > m_vlen_bytes) {
            throw std::out_of_range("Indexing into vector register out of range");
        }

        // Deference to return value instead of pointer
        return *reinterpret_cast<T*>(m_data.get() + offset); // Potentially misaligned?
    }

private:
    // Size of a single vector register in bytes
    size_t m_vlen_bytes;

    // Vector registers
    std::unique_ptr<uint8_t[]> m_data;
};

#endif // VREG_HH