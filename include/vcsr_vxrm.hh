// by Austin

#ifndef VCSR_VXRM_HH
#define VCSR_VXRM_HH

#include <cstddef>
#include <cstdint>

#include "vcsr.hh"

template<typename T>
class vcsr_vxrm: private vcsr<T> {
public:
    static constexpr T      VXRM_BITMASK   = 0x3;
    static constexpr T      VXRM_OFFSET    = 0x0;

    vcsr_vxrm() {};

    // Sets VXRM value
    void setVXRM(T _vxrm) {
        T temp_value = _vxrm & VXRM_BITMASK;

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

#endif // VCSR_VXRM_HH