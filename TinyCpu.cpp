#include "TinyCpu.h"

namespace TinyCpu {
        void CPU::run() {
            do {
                assert(PC < MemorySize && "PC Overflow");
                fetch(); 
                execute();
            } while (IR != HALT);
        }

        void CPU::fetch() {
            IR = Memory[PC++];
        }

        void CPU::execute() {
            switch (IR) {
                case ADD:
                    ACC += Memory[PC++];
                    break;
                case SUB:
                    ACC -= Memory[PC++];
                    break;
                case JMP: {
                    byte addr = Memory[PC++];
                    PC = addr;
                    break;
                }
                case LOD:
                    ACC = Memory[PC++];
                    break;
                case STO:
                    Memory[Memory[PC++]] = ACC;
                    break;
                case JPZ: {
                    if (ACC == 0) 
                    {
                        byte addr = Memory[PC++];
                        PC = addr;
                    }
                    break;
                }
                case JNZ: {
                    if (ACC != 0) {
                        byte addr = Memory[PC++];
                        PC = addr;
                    }
                    break;
                }
                default:
                case HALT: 
                    break;
            }
        }
}
