// by Austin

#include "vreg.hh"
#include "vcsr_vtype.hh"

#include <cstddef>
#include <cstdint>
#include <iostream>

int main() {
    size_t xlen_bits = 32; // RV32 system
    size_t vlen_bits = 128; // Vector register width

    // Initialise CSRs
    if (xlen_bits == 32) {
        vcsr_vtype<uint32_t> vtype = vcsr_vtype<uint32_t>(xlen_bits);
    } else {
        vcsr_vtype<uint64_t> vtype = vcsr_vtype<uint64_t>(xlen_bits);
    }

    // Initialise vreg
    std::vector<vreg> vregs;
    vregs.reserve(NUM_VREGS);
    for (size_t i = 0; i < NUM_VREGS; i++) {
        vregs.push_back(vreg(vlen_bits));
    }

    return 0;
}