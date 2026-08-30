#include <iostream> 
#include <array>
#include  "../include/decode_stage.hpp"
#include "../include/STD_TYPES.h"
#include "../include/memory.hpp"

DecodedInstr decode_stage::decode (int instruction ) {
    DecodedInstr decoded_instr ; 
    
    decoded_instr.opcode = (instruction>>OPCODE_SHIFT) & OPCODE_MASK ; 
    

    const u8  rd    = (instruction>>RD_SHIFT    )&  RD_MASK;
    const u8  rs    = (instruction>>RS_SHIFT    )&  RS_MASK    ;
    const u8  rt    = (instruction>>RT_SHIFT    )&  RT_MASK    ;
    const u8  funct = (instruction>>FUNC_SHIFT  )&  FUNC_MASK  ;
    const u32  imm  = (instruction>>IMM_SHIFT   )&  IMM_MASK   ;
    const u32 target= (instruction>>OFFEST_SHIFT)&  OFFEST_MASK;

    if (decoded_instr.opcode == 0 ){ 
        decoded_instr.rs = rs; 
        decoded_instr.rt = rt; 
        decoded_instr.rd = rd; 
        decoded_instr.func = funct;
    }
    else if ((decoded_instr.opcode>= (int)Op_type:: I_TYPE ) && (decoded_instr.opcode < (int)Op_type:: J_TYPE))
    {
        decoded_instr.rd = rd; 
        decoded_instr.rs = rs; 
        decoded_instr.imm = imm;
    }
    else if  ((decoded_instr.opcode== (int)Op_type:: J_TYPE )){
        decoded_instr.rd = rd;
        decoded_instr.target = target;

    }
    else{
        decoded_instr.rs = rs; 
        decoded_instr.rt = rt; 
        decoded_instr.rd = rd; 
        decoded_instr.func = funct;

    }

return decoded_instr ; 

}
