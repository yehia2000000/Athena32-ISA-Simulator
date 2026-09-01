#include "RegFile.h"

RegisterFile::RegisterFile() {
    for (int i = 0; i < 32; i++) {
        mem[i] = 0;
    }
}

int RegisterFile::getRegister(int address) {
    return mem[address];
}

void RegisterFile::setRegister(int address, int data) {
    mem[address] = data;
}

void RegisterFile::dispData() {
    for (int i = 0; i < 32; i++) {
        std::cout << "R" << i << " : " << mem[i] << std::endl;
    }

}