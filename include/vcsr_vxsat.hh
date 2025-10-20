// by Austin

#ifndef VCSR_VXSAT_HH
#define VCSR_VXSAT_HH

#include <cstddef>
#include <cstdint>

#include "vcsr.hh"

template<typename T>
class vcsr_vxsat: private vcsr<T> {
public:
    static constexpr T VXSAT_BITMASK = 0x1;

    vcsr_vxsat() : vcsr<T>() {};

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

};

#endif // VCSR_VXSAT_HH