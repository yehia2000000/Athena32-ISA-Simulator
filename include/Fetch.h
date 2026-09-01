#pragma once
#include <cstdint>
#include "Memory.h"

class Fetch {
	
	uint8_t instruction;


	uint8_t getInstruction(uint32_t address, Memory InstructionMem);

};