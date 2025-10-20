// by Austin

#include "vreg.hh"
#include "vcsr_vtype.hh"
#include "vcsr_vl_vstart.hh"
#include "vcsr_vlenb.hh"
#include "vcsr_vxrm.hh"
#include "vcsr_vxsat.hh"
#include "vcsr_vcsr.hh"


#include <cstddef>
#include <cstdint>
#include <iostream>

using xlen_t = uint32_t; // RV32 system
// using xlen_t = uint64_t; // RV64 system

template <typename T>
struct VCSRs {
    vcsr_vtype<T> vtype;
    vcsr_vl_vstart<T>    vl;
    vcsr_vl_vstart<T>    vstart;
    vcsr_vlenb<T> vlenb;
    vcsr_vxrm<T> vxrm;
    vcsr_vxsat<T> vxsat;
    vcsr_vcsr<T> vcsr;

    VCSRs<T>(T vlen_bits) : vlenb(vlen_bits) {};

};

int main() {
    // Parameters left open for the implementor in the RVV standarad
    size_t xlen_bits = sizeof(xlen_t) * 8;
    xlen_t vlen_bits = 128; // Vector register width

    // Initialise VCSRs
    VCSRs<xlen_t> vcsrs(vlen_bits);

    // Initialise vreg
    std::vector<vreg> vregs;
    vregs.reserve(NUM_VREGS);
    for (size_t i = 0; i < NUM_VREGS; i++) {
        vregs.push_back(vreg(vlen_bits));
    }

    return 0;
}