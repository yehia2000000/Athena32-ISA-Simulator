#include "Fetch.h"
#include "Memory.h"
#include <cstdint>

uint8_t Fetch::getInstruction(uint32_t address, Memory InstructionMem) {
	InstructionMem.readWord(address);
}