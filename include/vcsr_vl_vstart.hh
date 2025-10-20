// by Austin

#ifndef VCSR_VL_VSTART_HH
#define VCSR_VL_VSTART_HH

#include <cstddef>
#include <cstdint>

#include "vcsr.hh"

template<typename T>
class vcsr_vl_vstart: private vcsr<T> {
public:

    vcsr_vl_vstart() : vcsr<T>() {};

    // Sets VL value
    void setVL(T _vl) {
        this->setValue(_vl);
    }

    // Gets VL value
    T getVL() {
        return this->getValue();
    }

};





#endif // VCSR_VL_VSTART_HH