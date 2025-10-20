// by Austin

#ifndef VCSR_HH
#define VCSR_HH

#include <cstddef>
#include <cstdint>

// There are 7 different CSR registers for the vector unit.
// The CSR classes will inherit these generic vcsr classes.
// They are of width XLEN, equivalent to system width (32-bit or 64-bit).

template<typename T>
class vcsr {
public:
    vcsr() : value(0)
    {
        m_xlen_bytes = sizeof(T);
    };

    // Returns size of CSR in bytes
    size_t getSize() {
        return m_xlen_bytes;
    }

    // Return value of CSR
    T getValue() {
        return value;
    }

    // Set CSR value
    void setValue(T _value) {
        value = _value;
    }

private:
    // Size of CSR, equivalent to system width in bytes
    size_t m_xlen_bytes;

    // CSR value
    T value;

};

#endif // VCSR_HH