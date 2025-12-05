#include "TinyCpu.h"
#include <string>

int main() {
    using namespace TinyCpu;

    CPU cpu{};

    std::string fp{"test_program.o"};
    cpu.load_program(fp);
    cpu.run();
    cpu.dump();

    return 0;
}
