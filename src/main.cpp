// by Austin

#include "vreg.hh"

#include <iostream>

int main() {
    size_t vlen_bits = 128;

    // Initialize vreg
    std::vector<vreg> vregs;
    vregs.reserve(NUM_VREGS);
    for (size_t i = 0; i < NUM_VREGS; i++) {
        vregs.push_back(vreg(vlen_bits));
        std::cout << i << ": VLEN size: " << vregs[i].getSize() << std::endl;
    }

    return 0;
}