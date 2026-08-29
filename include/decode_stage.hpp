#ifndef DECODER_H_ 
#define DECODER_H_

#define OPCODE_SHIFT    28
#define RD_SHIFT        23
#define RS_SHIFT        18
#define RT_SHIFT        13
#define FUNC_SHIFT      10
#define IMM_SHIFT       0
#define OFFEST_SHIFT    0 

#define OPCODE_MASK    0x0F
#define RD_MASK        0x1F
#define RS_MASK        0x1F
#define RT_MASK        0x1F
#define FUNC_MASK      0x07
#define IMM_MASK       0x3FFFF
#define OFFEST_MASK    0x7FFFFF

enum class Op_type {
    R_TYPE, //"ADD", "SUB", "OR", "SLT", 
    I_TYPE =1 ,  //"ADDI", "ORI", "ANDI","SW","LW", "SLTI" ,BEQ
    J_TYPE = 8 ,  // JAL
    EX_TYPE = 9 ,  //"MUL", "DIV", "REM" 
};


struct DecodedInstr {
    int opcode = 0 ; 
    int rs =0   ; 
    int rt =0 ; 
    int rd =0 ; 
    int shamt  =0 ; 
    int func = 0 ; 
    int imm =0  ; 
    int target =0 ; 
};

class decode_stage {
    public : 
    DecodedInstr decode (int instruction) ; 
};   





#endif