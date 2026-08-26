#include "../include/memory.hpp"
#include "../include/fetch_stage.hpp"

#include <iostream>


int Fetcher::fetchInstruction (int address , InstructionMem instrMem) {
        return instrMem.getInstruction(address) ; 
    }

    