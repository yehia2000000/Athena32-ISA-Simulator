#include <iostream>
#include <bit>
#include "Memory.h"
using namespace std;

Memory::Memory(uint32_t size)
    :size(size), mem(size,0) 
{
}

Memory::Memory()
    : size(16 * 1024), mem(size, 0)
{
}

void Memory::setSize(uint32_t size) {
    this->size = size;
    this->mem.reserve(size);
}

uint32_t Memory::getSize() {
    return this->size;
}

void Memory::storeWord(uint32_t address, uint32_t word)
{
    if (address % 4 != 0) {
        throw runtime_error("Wrong word address");
    }

    for (int i = 0; i < 4; i++) {
        this -> mem.at(address + i) =
            (word >> (8 * (3 - i))) & 0xFF;
    }
}


uint32_t Memory::readWord(uint32_t address)
{
    if (address % 4 != 0) {
        throw runtime_error("Wrong word address");
    }

    uint32_t word = 0;

    for (int i = 0; i < 4; i++) {
        word |= static_cast<uint32_t>(this->mem.at(address + i))
            << (8 * (3 - i));
    }

    return word;
}