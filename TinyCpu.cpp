#include "TinyCpu.h"
#include <fstream>
#include <iostream>
#include <string>

namespace TinyCpu {

    void CPU::dump()
    {
        std::cout << static_cast<int>(ACC)<< '\n';
    }

    void CPU::load_program(const std::string& file_path)
    {
        using byte = unsigned char;
        std::ifstream inputFile{file_path};
        if(inputFile.is_open())
        {
            std::string line{};
            for(byte pc = 0 ; std::getline(inputFile,line);pc++) {
                Memory[pc] =  static_cast<byte>(std::stoi(line,nullptr,2));
            }

                inputFile.close();
        } else 
        {
            std::cerr << "Error loading program: " << file_path << std::endl;
        }
    }

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
        using byte = unsigned char;
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
