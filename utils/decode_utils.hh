// by Austin

#ifndef DECODE_UTILS_HH
#define DECODE_UTILS_HH

#include <cstdint>

namespace decode{

// Extract the bits from hi to low
constexpr uint32_t extract(uint32_t raw, int hi, int lo) {
    return (raw >> lo) & ((1 << (hi - lo + 1)) - 1);
}

// Extract opcode major
constexpr uint32_t extract_opcode_major(uint32_t raw) {
    return extract(raw, 6, 0);
}

// Extract func3/ width
constexpr uint32_t extract_opcode_func3_width(uint32_t raw) {
    return extract(raw, 14, 12);
}

// Extract opcode function6
constexpr uint32_t extract_function6(uint32_t raw) {
    return extract(raw, 31, 26);
}

// Extract opcode RD/VD/VS3
constexpr uint32_t extract_rd_vd_vs3(uint32_t raw) {
    return extract(raw, 11, 7);
}

// Extract opcode RS1/VS2/IMM[4:0]
constexpr uint32_t extract_rs1_vs1_imm5(uint32_t raw) {
    return extract(raw, 19, 15);
}

// Extract opcode RS2/VS2/SUMMOP
constexpr uint32_t extract_rs2_vs2_summop(uint32_t raw) {
    return extract(raw, 24, 20);
}

}
#endif // DECODE_UTILS_HH