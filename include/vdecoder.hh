// by Austin

#ifndef VDECODER_HH
#define VDECODER_HH

#include <cstddef>
#include <cstdint>

#include "decode_utils.hh"

class vdecoder {
public:
    // Opcode major
    static constexpr uint32_t OPCODE_LDFP = 0x07; // Vector load (under FP opcode)
    static constexpr uint32_t OPCODE_STFP = 0x27; // Vector store (under FP opcode)
    static constexpr uint32_t OPCODE_OPV  = 0x67; // Vector arithmetic operations

    // Func3
    static constexpr uint32_t FUNC3_IVV = 0x0; // Integer vector-vector
    static constexpr uint32_t FUNC3_FVV = 0x1; // Floating vector-vector
    static constexpr uint32_t FUNC3_MVV = 0x2; // Masked/bit-wise vector-vector
    static constexpr uint32_t FUNC3_IVI = 0x3; // Integer vector-immediate
    static constexpr uint32_t FUNC3_IVX = 0x4; // Integer vector-scalar (X register)
    static constexpr uint32_t FUNC3_FVF = 0x5; // Floating vector-scalar (F register)
    static constexpr uint32_t FUNC3_MVX = 0x6; // Masked/bitwise vector-scalar
    static constexpr uint32_t FUNC3_CFG = 0x7; // Configuration



    explicit vdecoder(uint32_t vinstr) {
        uint32_t opcode = decode::extract_opcode_major(vinstr);

        switch(opcode) {
            case OPCODE_LDFP:
                break;
            case OPCODE_STFP:
                break;
            case OPCODE_OPV:
                break;
            default:
                break;
        }
    }

// private:

};


#endif // VDECODER_HH