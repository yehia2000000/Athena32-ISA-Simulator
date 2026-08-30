#ifndef DEASS_H_ 
#define DEASS_H_

class Disassmbler {

    public :    
    std::array<std::string_view, 32> registers = {
        "R0",  "R1",  "R2",  "R3",  "R4",  "R5",  "R6",  "R7",
        "R8",  "R9",  "R10", "R11", "R12", "R13", "R14", "R15",
        "R16", "R17", "R18", "R19", "R20", "R21", "R22", "R23",
        "R24", "R25", "R26", "R27", "R28", "R29", "R30", "R31"
    };

    std::array<std::string_view, 5> J_TYPE_op = {
        "JAL"
    };

    std::array<std::string_view, 8> I_type_op = {
        "ADDI", "ORI", "ANDI","SW", "LW", "SLTI","BEQ"
    };


    std::array<std::string_view, 8> R_type_op = {
        "ADD", "SUB","AND", "OR", "SLT"
    };

     std::array<std::string_view, 8> EX_type_op = {
         "MUL", "DIV", "REM"
    };

    std::string Dis_stage (DecodedInstr decoded_instr); 


};



#endif