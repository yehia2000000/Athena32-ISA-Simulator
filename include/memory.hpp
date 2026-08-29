#ifndef MEMORY_H_
#define MEMORY_H_
#include <vector> 
#include <cmath>
#include <array>
#include "../include/STD_TYPES.h"
class InstructionMem {

    private : 
    std::vector<unsigned int> mem ; 

    public :
    InstructionMem (std::vector<unsigned int> local_mem);
    
    unsigned int getInstruction (unsigned int address) ; 

};

class DataMem {

    std::vector <u8> mem ;

    public :
    DataMem () ;
    
    int getData (int address) ; 

    void setData (int address, int data) ;

    void dispData (); 

};

class RegisterFile {
    
    std::array<int , 32>mem ; 

    public :

    RegisterFile () ;

    int getRegister (int address) ;

    void setRegister (int address, int data) ;

    void dispData (); 
};



#endif