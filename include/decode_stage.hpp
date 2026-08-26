#ifndef DECODER_H_ 
#define DECODER_H_

enum class Format {
    R_TYPE , 
    I_TYPE , 
    J_TYPE , 
    B_TYPE , 
    IN_VALID 
}; 


struct DecodedInstr {
    int opcode = (int)Format::IN_VALID ; 
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