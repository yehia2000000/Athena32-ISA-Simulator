#include <iostream> 
#include <array> 
#include <vector> 
#include <string> 

#include "../include/memory.hpp" 
#include "../include/decode_stage.hpp"
#include "../include/execute_stage.hpp" 
int Executer::SignExtend (int value , int bit_count)  {
    int shift = 32 - bit_count;
    return static_cast<int>(value << shift) >> shift;

}

STATE Executer::ExecuteStage (DecodedInstr decode_instr , DataMem *Dmem ,RegisterFile *Rmem , int*pc  ) {
    STATE Ex_state = STATE::NONE ; 
    int local_rd , local_rt , local_rs ; 
    int local_off , local_data ; 
    int result ; 
    
    if (decode_instr.opcode == 0 ){ 
        switch (decode_instr.func){
            case (int)FUNC_R_TYPE::ADD : 

            local_rs = (*Rmem).getRegister(decode_instr.rs); 
            local_rt = (*Rmem).getRegister(decode_instr.rt); 
            local_rd = local_rs + local_rt ; 
            (*Rmem).setRegister(decode_instr.rd , local_rd); 
            Ex_state = STATE::DONE ;
            break ; 

            case (int)FUNC_R_TYPE::SUB : 
            local_rs = (*Rmem).getRegister(decode_instr.rs); 
            local_rt = (*Rmem).getRegister(decode_instr.rt); 
            local_rd = local_rs - local_rt ; 
            (*Rmem).setRegister(decode_instr.rd , local_rd); 
            Ex_state = STATE::DONE ;
            break; 

            case (int)FUNC_R_TYPE::AND : 
            local_rs = (*Rmem).getRegister(decode_instr.rs); 
            local_rt = (*Rmem).getRegister(decode_instr.rt); 
            local_rd = local_rs & local_rt ; 
            (*Rmem).setRegister(decode_instr.rd , local_rd); 
            Ex_state = STATE::DONE ;
            break ; 

            case (int)FUNC_R_TYPE::OR : 
            local_rs = (*Rmem).getRegister(decode_instr.rs); 
            local_rt = (*Rmem).getRegister(decode_instr.rt); 
            local_rd = local_rs | local_rt ; 
            (*Rmem).setRegister(decode_instr.rd , local_rd); 
            Ex_state = STATE::DONE ;
            break ; 

            case (int)FUNC_R_TYPE::SLT : 
            local_rs = (*Rmem).getRegister(decode_instr.rs); 
            local_rt = (*Rmem).getRegister(decode_instr.rt); 
            local_rd = (local_rs < local_rt) ; 
            (*Rmem).setRegister(decode_instr.rd , local_rd); 
            Ex_state = STATE::DONE ;
            break ; 

        }
    }
    else if ((decode_instr.opcode>= (int)Op_type:: I_TYPE ) && (decode_instr.opcode < (int)Op_type:: J_TYPE))
    {
        switch (decode_instr.opcode) {
            case (int)FUNC_I_TYPE::ADDI : 
            local_rs = (*Rmem).getRegister(decode_instr.rs); 
            local_rd = local_rs + Executer::SignExtend(decode_instr.imm,18) ; 
            (*Rmem).setRegister(decode_instr.rd , local_rd); 
            Ex_state = STATE::DONE ;
            break ; 

            case (int)FUNC_I_TYPE::ANDI: 
            local_rs = (*Rmem).getRegister(decode_instr.rs); 
            local_rd = local_rs & Executer::SignExtend(decode_instr.imm,18) ; 
            (*Rmem).setRegister(decode_instr.rd , local_rd); 
            Ex_state = STATE::DONE ;
            break; 

            case (int)FUNC_I_TYPE::ORI: 
            local_rs = (*Rmem).getRegister(decode_instr.rs); 
            local_rd = local_rs | Executer::SignExtend(decode_instr.imm,18) ; 
            (*Rmem).setRegister(decode_instr.rd , local_rd); 
            Ex_state = STATE::DONE ;
            break; 

            case (int)FUNC_I_TYPE::LW: 
            local_rs = (*Rmem).getRegister(decode_instr.rs); 
            local_off = (decode_instr.imm) * 4  ; 
            local_data = (*Dmem).getData(local_rs+local_off) ; 
            (*Rmem).setRegister(decode_instr.rd , local_data); 
            Ex_state = STATE::DONE ;
            break; 

            case (int)FUNC_I_TYPE::SW: 
            local_data = (*Rmem).getRegister(decode_instr.rd);
            local_rs = (*Rmem).getRegister(decode_instr.rs); 
            local_off = (decode_instr.imm) *4  ; 
            (*Dmem).setData (local_rs+local_off , local_data) ; 
            Ex_state = STATE::DONE ;
            break; 

            case  (int)FUNC_I_TYPE::SLTI : 
            local_rs = (*Rmem).getRegister(decode_instr.rs); 
            local_rd = (local_rs < Executer::SignExtend(local_rs,18)) ; 
            (*Rmem).setRegister(decode_instr.rd , local_rd); 
            Ex_state = STATE::DONE ;
            break ; 

            case  (int)FUNC_I_TYPE::BEQ : 
            local_rd = (*Rmem).getRegister(decode_instr.rd); 
            local_rs = (*Rmem).getRegister(decode_instr.rs); 
            result = (local_rd == local_rs) ; 
            if (result == 1) {
                std::cout <<"TAKEN" << std::endl ; 
                *pc = (*pc) + Executer::SignExtend(decode_instr.imm,18);
            }
            Ex_state = STATE::DONE ;
            break ; 

        }

    }
    else if  ((decode_instr.opcode== (int)Op_type:: J_TYPE )){
        *pc = (*pc) + Executer::SignExtend(decode_instr.target,23);
        (*Rmem).setRegister(decode_instr.rd , *pc);
        Ex_state = STATE::DONE ;

    }
    else{
        switch (decode_instr.func) {
            case (int)FUNC_EX_TYPE::MUL : 
            local_rs = (*Rmem).getRegister(decode_instr.rs); 
            local_rt = (*Rmem).getRegister(decode_instr.rt); 
            local_rd = (local_rs * local_rt)& 0xFFFFFFFF ; 
            (*Rmem).setRegister(decode_instr.rd , local_rd); 
            Ex_state = STATE::DONE ;
            break ; 

            case (int)FUNC_EX_TYPE::DIV : 
            local_rs = (*Rmem).getRegister(decode_instr.rs); 
            local_rt = (*Rmem).getRegister(decode_instr.rt); 
            if (local_rt == 0){
                Ex_state = STATE::DIV_BY_0 ; 
                local_rd = -1 ; 
            }
            else {
                local_rd = local_rs / local_rt ; 
                Ex_state = STATE::DONE ;
            }
            (*Rmem).setRegister(decode_instr.rd , local_rd); 
            break ; 

            case (int)FUNC_EX_TYPE::REM : 
            local_rs = (*Rmem).getRegister(decode_instr.rs); 
            local_rt = (*Rmem).getRegister(decode_instr.rt);
            if (local_rt == 0 )
            {
                local_rd = local_rs ; 
                Ex_state = STATE::DIV_BY_0 ; 
            } 
            else {
                local_rd = local_rs % local_rt ; 
                Ex_state = STATE::DONE ;
            }
            (*Rmem).setRegister(decode_instr.rd , local_rd); 
            break ; 

        }
    }

return Ex_state ; 
}