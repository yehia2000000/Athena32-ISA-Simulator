#ifndef EXE_H_ 
#define EXE_H_

enum class FUNC_R_TYPE {
    ADD , SUB ,AND ,OR ,SLT 
};

enum class FUNC_I_TYPE {

    ADDI = 1 , ANDI =2 , ORI = 3 ,  SW = 4 ,  LW = 5 ,  SLTI = 6 ,  BEQ = 7
} ;


enum  class FUNC_EX_TYPE { 
    MUL , DIV  , REM 
};

enum class STATE {
    NONE , DONE , DIV_BY_0  

};

class Executer {

    public:

    STATE  ExecuteStage (DecodedInstr decode_instr , DataMem * Dmem ,RegisterFile * Rmem , int*pc ) ; 
    
    static int SignExtend (int value , int bit_count) ; 
};



#endif // !EXE_H_ 
