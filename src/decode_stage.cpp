#include <iostream> 
#include <array>
#include  "../include/decode_stage.hpp"
#include "../include/STD_TYPES.h"
DecodedInstr decode_stage::decode (int instruction ) {
    DecodedInstr decoded_instr ; 
    decoded_instr.opcode = (instruction>>26)&0x3F ; 
    
    const u8  rs    = (instruction >> 21) & 0x1F;
    const u8  rt    = (instruction >> 16) & 0x1F;
    const u8  rd    = (instruction >> 11) & 0x1F;
    const u8  shamt = (instruction >>  6) & 0x1F;
    const u8  funct =  instruction        & 0x3F;
    const u32  imm   = (s16)(instruction & 0xFFFF);
    const u32 target   =  instruction & 0x03FFFFFF;

    std :: cout <<"decode  function  tracing : "<< (instruction>>26) <<std::endl ;
    switch  ((Format)decoded_instr.opcode) {

        case  Format::R_TYPE : 
        std::cout << "R_TYPE" <<std::endl ; 
        decoded_instr.rs = rs; 
        decoded_instr.rt = rt; 
        decoded_instr.rd = rd; 
        decoded_instr.shamt = shamt; 
        decoded_instr.func = funct;
        break ; 

        case  Format::I_TYPE : 
        std::cout << "I_TYPE" <<std::endl ; 
        decoded_instr.rs = rs; 
        decoded_instr.rt = rt; 
        decoded_instr.imm = imm;

        break ; 

        case Format::B_TYPE : 
        std::cout << "B_TYPE" <<std::endl ; 
        decoded_instr.rs = rs; 
        decoded_instr.rt = rt; 
        decoded_instr.imm = imm;
        break ; 
        
        case Format::J_TYPE :
        std::cout << "J_TYPE" <<std::endl ;  
        decoded_instr.target = target;
        break;

    }

return decoded_instr ; 

}
