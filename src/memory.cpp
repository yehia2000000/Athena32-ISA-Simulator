#include  <iostream> 
#include "../include/memory.hpp" 


InstructionMem :: InstructionMem (std::vector<int> local_mem) {
        for (int i =0 ; i<local_mem.size(); i++) {
            mem.push_back(local_mem[i]) ; 
        }
    }
    
int InstructionMem :: getInstruction (int address) {
        return mem[address] ; 
    }

DataMem :: DataMem () {
        for (int i =0 ; i<pow(2,32); i++) {
            mem.push_back(0) ; 
        }
    }
int DataMem :: getData (int address) {
        int data = 0;
        for (int i =0 ; i<4; i++) {
            data |= mem[address + i] << (8 * (3 - i)); 
        }
        return data ;
    }

void DataMem :: setData (int address, int data) {
        for (int i =0 ; i<4; i++) {
            mem[address+i] = (data>>(8*(3-i)))&0xFF ; 
        }
    }


RegisterFile :: RegisterFile () {
        for (int i =0 ; i<32; i++) {
            mem[i] =0  ; 
        }
    }

int RegisterFile :: getRegister (int address) {
        return mem[address] ; 
    }

void RegisterFile :: setRegister (int address, int data) {
        mem[address] = data ; 
    }