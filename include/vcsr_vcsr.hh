// by Austin

#ifndef VCSR_VCSR_HH
#define VCSR_VCSR_HH

#include <cstddef>
#include <cstdint>

#include "vcsr.hh"

template<typename T>
class vcsr_vcsr: private vcsr<T> {
public:
    static constexpr T      VXSAT_BITMASK  = 0x1;

    static constexpr T      VXRM_BITMASK   = 0x6;
    static constexpr T      VXRM_OFFSET    = 0x1;

    vcsr_vcsr() : vcsr<T>() {};

    // Sets VXSAT value
    void setVXSAT(T _vxsat) {
        T temp_value = _vxsat & VXSAT_BITMASK;

        this->setValue(temp_value);
    }

    // Gets VXSAT value
    T getVXSAT() {
        T temp_value = this->getValue();

        // Use mask and offset to extract value
        temp_value = temp_value & VXSAT_BITMASK;

        return temp_value;
    }

    // Sets VXRM value
    void setVXRM(T _vxrm) {
        T temp_value = this->getValue;

        temp_value &= ~VXRM_BITMASK;
        temp_value |= (_vxrm << VXRM_OFFSET) & VXRM_BITMASK;

        this->setValue(temp_value);
    }

    // Gets VXRM value
    T getVXRM() {
        T temp_value = this->getValue();

        // Use mask and offset to extract value
        temp_value = (temp_value & VXRM_BITMASK) >> VXRM_OFFSET;

        return temp_value;
    }

};

#endif // VCSR_VCSR_HH