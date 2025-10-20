// by Austin

#ifndef VCSR_VLENB_HH
#define VCSR_VLENB_HH

#include <cstddef>
#include <cstdint>

#include "vcsr.hh"

template<typename T>
class vcsr_vlenb: private vcsr<T> {
public:

    vcsr_vlenb(T _m_vlenb_bits) : vcsr<T>() {
        this->setValue(_m_vlenb_bits / 8);
    };

    // // Sets VLENB value
    // void setVL(T _vlenb) {
    //     this->setValue(_vl);
    // }

    // Gets VLENB value
    T getVL() {
        return this->getValue();
    }

};





#endif // VCSR_VLENB_HH