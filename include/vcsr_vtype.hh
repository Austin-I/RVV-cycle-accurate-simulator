// by Austin

#ifndef VCSR_VTYPE_HH
#define VCSR_VTYPE_HH

#include <cstddef>
#include <cstdint>

#include "vcsr.hh"

// Class for the vtype CSR for 32b and 64b
//  value[2:0]      = vlmul
//  value[5:3]      = vsew
//  value[6]        = vta
//  value[7]        = vma
//  value[XLEN-2:8] = reserved 
//  value[XLEN-1]   = vill

template<typename T>
class vcsr_vtype: public vcsr<T> {
public:
    static constexpr T      VLMUL_BITMASK   = 0x7;
    static constexpr T      VLMUL_OFFSET    = 0x0;
    static constexpr size_t VLMUL_SIZE_BITS = 3;

    static constexpr T      VSEW_BITMASK   = 0x38;
    static constexpr T      VSEW_OFFSET    = 3;
    static constexpr size_t VSEW_SIZE_BITS = 3;

    static constexpr T      VTA_BITMASK   = 0x40;
    static constexpr T      VTA_OFFSET    = 6;
    static constexpr size_t VTA_SIZE_BITS = 1;

    static constexpr T      VMA_BITMASK   = 0x80;
    static constexpr T      VMA_OFFSET    = 7;
    static constexpr size_t VMA_SIZE_BITS = 1;

    static constexpr size_t VILL_SIZE_BITS = 1;


    vcsr_vtype() : vcsr<T>() {};

    // Sets VLMUL value
    void setVLMUL(T _vlmul) {
        // Get private value
        T temp_value = this->getValue();

        // Range for modulus in case input out of range
        T vlmul_range = 1 << VLMUL_SIZE_BITS;

        // Use mask and offset set value
        temp_value &= ~VLMUL_BITMASK;
        temp_value |= (_vlmul % vlmul_range) << VLMUL_OFFSET;

        // Set private value
        this->setValue(temp_value);
    }
    
    // Gets VLMUL value
    T getVLMUL() {
        // Get private value
        T temp_value = this->getValue();

        // Use mask and offset to extract value
        temp_value = (temp_value & VLMUL_BITMASK) >> VLMUL_OFFSET;

        return temp_value;
    }

    // Sets VSEW value
    void setVSEW(T _vsew) {
        // Get private value
        T temp_value = this->getValue();

        // Range for modulus in case input out of range
        T vsew_range = 1 << VSEW_SIZE_BITS;

        // Use mask and offset set value
        temp_value &= ~VSEW_BITMASK;
        temp_value |= (_vsew % vsew_range) << VSEW_OFFSET;

        // Set private value
        this->setValue(temp_value);
    }

    // Gets VSEW value
    T getVSEW() {
        // Get private value
        T temp_value = this->getValue();

        // Use mask and offset to extract value
        temp_value = (temp_value & VSEW_BITMASK) >> VSEW_OFFSET;

        return temp_value;
    }

    // Sets VTA value
    void setVTA(T _vta) {
        // Get private value
        T temp_value = this->getValue();

        // Range for modulus in case input out of range
        T vta_range = 1 << VTA_SIZE_BITS;

        // Use mask and offset set value
        temp_value &= ~VTA_BITMASK;
        temp_value |= (_vta % vta_range) << VTA_OFFSET;

        // Set private value
        this->setValue(temp_value);
    }

    // Gets VTA value
    T getVTA() {
        // Get private value
        T temp_value = this->getValue();

        // Use mask and offset to extract value
        temp_value = (temp_value & VTA_BITMASK) >> VTA_OFFSET;

        return temp_value;
    }

    // Sets VMA value
    void setVMA(T _vma) {
        // Get private value
        T temp_value = this->getValue();
    
        // Range for modulus in case input out of range
        T vma_range = 1 << VMA_SIZE_BITS;

        // Use mask and offset set value
        temp_value &= ~VMA_BITMASK;
        temp_value |= (_vma % vma_range) << VMA_OFFSET;

        // Set private value
        this->setValue(temp_value);
    }

    // Gets VMA value
    T getVMA() {
        // Get private value
        T temp_value = this->getValue();

        // Use mask and offset to extract value
        temp_value = (temp_value & VMA_BITMASK) >> VMA_OFFSET;

        return temp_value;
    }

    // Sets vill value
    void setVILL(T _vill) {
        // Get private value
        T temp_value = this->getValue();

        // Calculate XLEN - 1
        T vill_offset = (sizeof(T) * 8) - 1;

        // Range for modulus in case input out of range
        T vill_range = 1 << VILL_SIZE_BITS;

        // Use mask and offset set value
        temp_value &= (1 << vill_offset) - 1;
        temp_value |= (_vill % vill_range) << VMA_OFFSET;

        // Set private value
        this->setValue(temp_value);
    }

    // Gets VMA value
    T getVILL() {
        // Get private value
        T temp_value = this->getValue();

        // Calculate XLEN - 1 
        T vill_offset = (sizeof(T) * 8) - 1;

        // Use mask and offset to extract value
        temp_value = temp_value >> VMA_OFFSET;

        return temp_value;
    }

};

#endif // VCSR_VTYPE_HH