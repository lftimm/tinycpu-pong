#pragma once
#include <array>
#include <cassert>
#include <string_view>
#include <vector>


namespace TinyCpu {
    using byte = unsigned char;
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

    class CPU {
        std::array<byte, MemorySize> Memory{};

        byte PC{0x00};
        byte ACC{0x00};
        byte IR{HALT};

        void fetch();
        void execute();

    public:
        void load_program(const std::string& file_path);
        void run();
        void dump();
    };
}
