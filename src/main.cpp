#include <iostream>
#include <vector>
#include <string> 
#include <array>
#include "../include/memory.hpp" 
#include "../include/fetch_stage.hpp" 
#include "../include/decode_stage.hpp"
#include "../include/disassemble_stage.hpp"
#include "../include/execute_stage.hpp"

// test program 
/*
10800064  ADDI R1, R0, 100             R1 = 0x00000064
11000004  ADDI R2, R0, 4               R2 = 0x00000004
41040000  SW R2, 0(R1)                 MEM[100] = 0x00000004
11000011  ADDI R2, R0, 17              R2 = 0x00000011
41040001  SW R2, 1(R1)                 MEM[101] = 0x00000011
11000009  ADDI R2, R0, 9               R2 = 0x00000009
41040002  SW R2, 2(R1)                 MEM[102] = 0x00000009
1100002A  ADDI R2, R0, 42              R2 = 0x0000002A
41040003  SW R2, 3(R1)                 MEM[103] = 0x0000002A
11000008  ADDI R2, R0, 8               R2 = 0x00000008
41040004  SW R2, 4(R1)                 MEM[104] = 0x00000008
11800005  ADDI R3, R0, 5               R3 = 0x00000005
12000000  ADDI R4, R0, 0               R4 = 0x00000000
1A000000  ADDI R20, R0, 0              R20 = 0x00000000
1A800000  ADDI R21, R0, 0              R21 = 0x00000000
02848000  ADD R5, R1, R4               R5 = 0x00000064
53140000  LW R6, 0(R5)                 R6 = 0x00000004  

*/

int main()
{
    //
    std::vector<unsigned int> intr_mem = {0x10800064, 0x11000004, 0x41040000, 0x11000011, 0x41040001, 
0x11000009, 0x41040002, 0x1100002A, 0x41040003, 0x11000008, 0x41040004, 0x11800005, 0x12000000, 
0x1A000000, 0x1A800000, 0x02848000, 0x53140000 };
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

    for (int  i =0 ; i<intr_mem.size();i++)
    {
    fetch_stage.fetchInstruction(i,instrmem); 
    DecodedInstr decoded_instr = decode_stage.decode(fetch_stage.fetchInstruction(i,instrmem)) ;
    std::string user_instr = Diss_stage.Dis_stage (decoded_instr);
    std :: cout << "user instruction : "<< user_instr <<std::endl ;
    exe_stage.ExecuteStage(decoded_instr,&Dmem, &RFmem ,&pc );
    }
    std::cout << "*******************************Data Memory*************************************"<<std::endl;
    Dmem.dispData(); 
    std::cout << "**********************************Register File**********************************"<<std::endl;  
    RFmem.dispData(); 
    
    std::cout << "Data Memory  value : " << Dmem.getData(100) <<std ::endl ;

    
    
    //std::cout<<std::hex<<instrmem.getInstruction(2)<<std::endl;
    //std::cout<<std::hex<<fetch_stage.fetchInstruction(2,instrmem)<<std::endl;
    //DecodedInstr decoded_instr = decode_stage.decode(fetch_stage.fetchInstruction(2,instrmem)) ;
    //std::cout << ((int)decoded_instr.opcode);
    //std::string user_instr = Diss_stage.Dis_stage (decoded_instr); 
    //std :: cout << "user instruction : "<< user_instr <<std::endl ; 

}