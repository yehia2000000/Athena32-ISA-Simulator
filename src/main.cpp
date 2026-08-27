#include <iostream>
#include <vector>
#include <string> 
#include <array>
#include "../include/memory.hpp" 
#include "../include/fetch_stage.hpp" 
#include "../include/decode_stage.hpp"
#include "../include/disassemble_stage.hpp"

int main()
{
    std::vector<int> intr_mem = {0x058F, 0x0000, 0x00850000,0x0F89};
    InstructionMem instrmem (intr_mem); 
    Fetcher fetch_stage ; 
    decode_stage decode_stage ;
    Disassmbler Diss_stage ; 
    std::cout<<std::hex<<instrmem.getInstruction(2)<<std::endl;
    std::cout<<std::hex<<fetch_stage.fetchInstruction(2,instrmem)<<std::endl;
    DecodedInstr decoded_instr = decode_stage.decode(fetch_stage.fetchInstruction(2,instrmem)) ;
    std::cout << ((int)decoded_instr.opcode);
    std::string user_instr = Diss_stage.Dis_stage (decoded_instr); 
    std :: cout << "user instruction : "<< user_instr <<std::endl ; 

}