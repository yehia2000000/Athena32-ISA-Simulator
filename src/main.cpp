#include <iostream>
#include <vector>
#include <string> 
#include <array>
#include "../include/memory.hpp" 
#include "../include/fetch_stage.hpp" 
#include "../include/decode_stage.hpp"
#include "../include/disassemble_stage.hpp"
#include "../include/execute_stage.hpp"

// test 1  program 
/*
PC= 0, 10800064  ADDI R1, R0, 100             R1 = 0x00000064
PC= 1, 11000004  ADDI R2, R0, 4               R2 = 0x00000004
PC= 2, 41040000  SW R2, 0(R1)                 MEM[100] = 0x00000004
PC= 3, 11000011  ADDI R2, R0, 17              R2 = 0x00000011
PC= 4, 41040001  SW R2, 1(R1)                 MEM[101] = 0x00000011
PC= 5, 11000009  ADDI R2, R0, 9               R2 = 0x00000009
PC= 6, 41040002  SW R2, 2(R1)                 MEM[102] = 0x00000009
PC= 7, 1100002A  ADDI R2, R0, 42              R2 = 0x0000002A
PC= 8, 41040003  SW R2, 3(R1)                 MEM[103] = 0x0000002A
PC= 9, 11000008  ADDI R2, R0, 8               R2 = 0x00000008
PC= 10, 41040004  SW R2, 4(R1)                 MEM[104] = 0x00000008
PC= 11, 11800005  ADDI R3, R0, 5               R3 = 0x00000005
PC= 12, 12000000  ADDI R4, R0, 0               R4 = 0x00000000
PC= 13, 1A000000  ADDI R20, R0, 0              R20 = 0x00000000
PC= 14, 1A800000  ADDI R21, R0, 0              R21 = 0x00000000
PC= 15, 02848000  ADD R5, R1, R4               R5 = 0x00000064
PC= 16, 53140000  LW R6, 0(R5)                 R6 = 0x00000004 
 
PC= 17, 0A50C000  ADD R20, R20, R6             R20 = 0x0000004
PC= 18, 03D4D000  SLT R7, R21, R6              R7 = 0x00000001
PC= 19, 73800001  BEQ R7, R0, +1               not taken
PC= 20, 0A980000  ADD R21, R6, R0              R21 = 0x0000004
PC= 21, 12100001  ADDI R4, R4, 1               R4 = 0x00000001
PC= 22, 04106400  SUB R8, R4, R3               R8 = 0xFFFFFFFC
PC= 23, 74000001  BEQ R8, R0, +1               not taken
PC= 24, 7003FFF6  BEQ R0, R0, -10              taken -> PC 15 (infinite loop)
PC= 25, 02848000  ADD R5, R1, R4               R5 = 0x00000068
PC= 26, 53140000  LW R6, 0(R5)                 R6 = 0x00000008  (MEM[104])


*/


int main()
{
    // test case 1 
    std::vector<unsigned int> intr_mem = {0x10800064, 0x11000004, 0x41040000, 0x11000011, 0x41040001, 
    0x11000009, 0x41040002, 0x1100002A, 0x41040003, 0x11000008, 0x41040004, 0x11800005, 0x12000000, 
    0x1A000000, 0x1A800000, 0x02848000, 0x53140000,0x0A50C000 , 0x03D4D000 , 0x73800001, 0x0A980000 , 0x12100001 , 
    0x04106400,0x74000001 ,0x7003FFF6 };
    // Create Components 
    InstructionMem instrmem (intr_mem);
    DataMem Dmem ; 
    RegisterFile RFmem ; 
    
    Fetcher fetch_stage ; 
    decode_stage decode_stage ;
    Disassmbler Diss_stage ;
    Executer exe_stage ; 
    int pc =0  ; 
    

    /******************************************************************************************************* */
    std::cout << "******************************Disassemble*************************************"<<std::endl;
    while (pc < intr_mem.size())
    {
        fetch_stage.fetchInstruction(pc,instrmem); 
        DecodedInstr decoded_instr = decode_stage.decode(fetch_stage.fetchInstruction(pc,instrmem)) ;
        std::string user_instr = Diss_stage.Dis_stage (decoded_instr);
        std :: cout << "PC -> " << pc<< ",  user instruction : "<< user_instr <<std::endl ;
        exe_stage.ExecuteStage(decoded_instr,&Dmem, &RFmem ,&pc );
        pc = pc +1 ; 
    }

    
    std::cout << "*******************************Data Memory*************************************"<<std::endl;
    Dmem.dispData(); 
    std::cout << "**********************************Register File**********************************"<<std::endl;  
    RFmem.dispData(); 
    
    //std::cout << "Data Memory  value : " << Dmem.getData(100) <<std ::endl ;

    
    
    //std::cout<<std::hex<<instrmem.getInstruction(2)<<std::endl;
    //std::cout<<std::hex<<fetch_stage.fetchInstruction(2,instrmem)<<std::endl;
    //DecodedInstr decoded_instr = decode_stage.decode(fetch_stage.fetchInstruction(2,instrmem)) ;
    //std::cout << ((int)decoded_instr.opcode);
    //std::string user_instr = Diss_stage.Dis_stage (decoded_instr); 
    //std :: cout << "user instruction : "<< user_instr <<std::endl ; 

}