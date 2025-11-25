#pragma once
#include <cassert>

using byte = unsigned char;

namespace TinyCpu {
    constexpr byte MemorySize = 255;

    enum OpCodes {
        ADD,
        SUB,
        JMP,
        STO,
        LOD,
        JPZ,
        JNZ,
        HALT=0xff,
    };

    struct CPU {
        byte Memory[MemorySize];

        byte PC{0x00};
        byte ACC{0x00};
        byte IR{HALT};

        void run();
        void fetch();
        void execute();
    };
}
