#include  <iostream> 
#include "../include/memory.hpp" 


InstructionMem :: InstructionMem (std::vector<unsigned int> local_mem) {
        for (int i =0 ; i<local_mem.size(); i++) {
            mem.push_back(local_mem[i]) ; 
        }
    }
    
unsigned int InstructionMem :: getInstruction (unsigned int address) {
        return mem[address] ; 
    }


/****************************************************************************************************** */

DataMem :: DataMem () {
        for (int i =0 ; i<1024; i++) {
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


void DataMem::dispData (){
    for (int i =0 ; i<1024; i=i+4) {
            std::cout << "Dmem[" << i << "] : "<< this->getData(i)<<std::endl   ; 
        }

}
/******************************************************************************************************* */

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

void RegisterFile::dispData (){
    for (int i =0 ; i<32; i++) {
            std::cout << "R" << i << " : "<<  mem[i] <<std::endl  ; 
        }

}