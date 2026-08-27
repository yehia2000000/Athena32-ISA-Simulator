
#include <iostream>
#include <string>
#include <array>
#include "../include/decode_stage.hpp"  
#include "../include/disassemble_stage.hpp"
std::string Disassmbler::Dis_stage (DecodedInstr decoded_instr)
{
    std:: string instr = ""; 

    if (decoded_instr.opcode == 0 ){
        instr += R_type_op[decoded_instr.func];
        instr += ", ";
        instr += registers[decoded_instr.rd] ;
        instr += ", " ; 
        instr += registers[decoded_instr.rs] ;
        instr += ", " ; 
        instr += registers[decoded_instr.rt] ;
    }
    else if ((decoded_instr.opcode>= (int)Op_type:: I_TYPE ) && (decoded_instr.opcode < (int)Op_type:: B_TYPE))
    {
        instr += I_type_op[decoded_instr.opcode -  (int)Op_type:: I_TYPE];
        instr += ", ";
        instr += registers[decoded_instr.rd] ;
        instr += ", " ; 
        instr += registers[decoded_instr.rs] ;
        instr += ", " ; 
        instr += std::to_string(decoded_instr.imm) ;
    }
    else if ((decoded_instr.opcode>= (int)Op_type:: B_TYPE ) && (decoded_instr.opcode < (int)Op_type:: J_TYPE))
    {
        instr += I_type_op[decoded_instr.opcode - (int)Op_type:: B_TYPE];
        instr += ", ";
        instr += registers[decoded_instr.rd] ;
        instr += std::to_string(decoded_instr.imm) ;
        instr += "(" ; 
        instr += registers[decoded_instr.rs] ;
        instr += ")" ; 
        
    }
    else {
        instr += I_type_op[decoded_instr.opcode - (int)Op_type:: J_TYPE];
        instr += ", ";
        instr += std::to_string(decoded_instr.target) ;
    }

    return instr ; 

}