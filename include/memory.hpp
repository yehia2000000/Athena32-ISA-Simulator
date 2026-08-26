#ifndef MEMORY_H_
#define MEMORY_H_
#include <vector> 
#include <cmath>
#include <array>
#include "../include/STD_TYPES.h"
class InstructionMem {

    private : 
    std::vector<int> mem ; 

    public :
    InstructionMem (std::vector<int> local_mem);
    
    int getInstruction (int address) ; 

};

class DataMem {

    std::vector <u8> mem ;

    public :
    DataMem () ;
    
    int getData (int address) ; 

    void setData (int address, int data) ;

};

class RegisterFile {
    
    std::array<int , 32>mem ; 

    public :

    RegisterFile () ;

    int getRegister (int address) ;

    void setRegister (int address, int data) ;
};



#endif