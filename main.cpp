#include "TinyCpu.h"

int main() {
    using namespace TinyCpu;

    CPU cpu{};
    cpu.Memory[0] = ADD;
    cpu.Memory[1] = 0x01;
    cpu.Memory[2] = ADD;
    cpu.Memory[3] = 0x02;
    cpu.Memory[4] = HALT;

    cpu.run();

    return 0;
}
