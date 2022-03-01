#include <iostream>
#include "globals.h"
#include "riscv.h"

using namespace std;

int32_t mem[MEM_SIZE];

int32_t lw(uint32_t address, int32_t kte) {
    return ((address + kte) % 4 == 0 ? mem[(address + kte) / 4] : !printf("Erro: Endereço não é multiplo de 4.\n"));
}

int32_t lb(uint32_t address, int32_t kte) {
    return (int32_t) *(((int8_t *) &mem[address / 4]) + kte);
}

int32_t lbu(uint32_t address, int32_t kte) {
    return (uint32_t) *(((uint8_t *) &mem[address / 4]) + kte);
}

void sw(uint32_t address, int32_t kte, int32_t dado) {
    return (void) ((address + kte) % 4 == 0 ? mem[(address + kte) / 4] = dado : printf("Erro: Endereço não é multiplo de 4.\n"));
}

void sb(uint32_t address, int32_t kte, int8_t dado) {
    *(((int8_t *) &mem[address / 4]) + kte) = dado;
}



void f_lw() {
    breg[rd] = lw(breg[rs1], imm12_i);
}

void f_lb() {
    breg[rd] = lb(breg[rs1], imm12_i);
}

void f_lbu() {
    breg[rd] = lbu(breg[rs1], imm12_i);
}

void f_sw() {
    sw(breg[rs1], imm12_s, breg[rs2]);
}

void f_sb() {
    sb(breg[rs1], imm12_s, breg[rs2]);
}

void f_add() {
    breg[rd] = breg[rs1] + breg[rs2]; 
}

void f_addi() {
    breg[rd] = breg[rs1] + imm12_i; 
}

void f_sub() {
    breg[rd] = breg[rs1] - breg[rs2]; 
}

void f_and() {
    breg[rd] = breg[rs1] & breg[rs2]; 
}

void f_andi() {
    breg[rd] = breg[rs1] & imm12_i; 
}

void f_or() {
    breg[rd] = breg[rs1] | breg[rs2]; 
}

void f_ori() {
    breg[rd] = breg[rs1] | imm12_i; 
}

void f_xor() {
    breg[rd] = breg[rs1] ^ breg[rs2]; 
}

void f_slli() {
    breg[rd] = breg[rs1] << shamt; 
}

void f_srli() {
    breg[rd] = ((uint32_t)breg[rs1]) >> shamt; 
}

void f_srai() {
    breg[rd] = breg[rs1] >> shamt; 
}

void f_lui() {
    breg[rd] = imm20_u; 
}

void f_auipc() {
    breg[rd] = pc + imm20_u - 4; 
}

void f_nop() {

}

void f_slt() {
    breg[rd] = breg[rs1] < breg[rs2]; 
}

void f_sltu() {
    breg[rd] = ((uint32_t)breg[rs1]) < ((uint32_t)breg[rs2]); 
}

void f_beq() {
    if(breg[rs1] == breg[rs2])
        pc = pc + imm13 - 4;
}

void f_bne() {
    if(breg[rs1] != breg[rs2])
        pc = pc + imm13 - 4;
}

void f_bge() {
    if(breg[rs1] >= breg[rs2])
        pc = pc + imm13 - 4;
}

void f_bgeu() {
    if(((uint32_t)breg[rs1]) >= ((uint32_t)breg[rs2]))
        pc = pc + imm13 - 4;
}

void f_blt() {
    if(breg[rs1] <= breg[rs2])
        pc = pc + imm13 - 4;
}

void f_bltu() {
    if(((uint32_t)breg[rs1]) <= ((uint32_t)breg[rs2]))
        pc = pc + imm13 - 4;
}

void f_jal() {
    breg[rd] = pc;
    pc = pc + imm21 - 4;
}

void f_jalr() {
    breg[rd] = pc;
    pc = breg[rs1] + imm12_i;
}


void f_ecall() {
    if(breg[A7] == 1){
        cout << breg[A0];
    }else if(breg[A7] == 4){
        char *str = (char *) mem + (uint32_t) breg[A0];
        printf("%s", str);
    }else if(breg[A7] == 10){
        stop_prg = true;
    }else{
        cout << "Comando " << breg[A7] << " não implementado.";
    }
}


void init() {
    pc = 0x00000000;
    ri = 0x00000000;
    sp = 0x00003ffc;
    gp = 0x00001800;
    stop_prg = false;
    build_dic();
}

void fetch() {
    ri = lw(pc, 0);
    pc = pc + 4;
}


auto get_bit = [](int word, int index){
    return (word >> index) & 1;
};

auto get_bit_inter = [](int word, int index, int mask){
    return (word >> index) & mask;
};

auto get_mask = [](int bits){
    return (1 << bits) - 1;
};


int extend_sign(int value, int size)
{   // c++ shift is arithmetic
    size = 32 - size;
    return ((value << size) >> size);
}

int get_imm12_i(uint32_t ri)
{
    int imm12_i = get_bit_inter(ri, 20, get_mask(12));
    return extend_sign(imm12_i, 12);
}

int get_imm12_s(uint32_t ri)
{
    int imm12_s = (get_bit_inter(ri, 25, get_mask(7)) << 5) |
                  (get_bit_inter(ri, 7,  get_mask(5)));

    return extend_sign(imm12_s, 12);
}

int get_imm13(uint32_t ri)
{
    int imm13 = (get_bit_inter(ri, 31, get_mask(1))  << 12) |
                (get_bit_inter(ri, 7,  get_mask(1))  << 11) |
                (get_bit_inter(ri, 25, get_mask(6))  << 5)  |
                (get_bit_inter(ri, 8,  get_mask(4))  << 1);

    return extend_sign(imm13, 13);
}

int get_imm20_u(uint32_t ri)
{
    int imm20_u = (get_bit_inter(ri, 12, get_mask(20)) << 12);
    return imm20_u;
}

int get_imm21(uint32_t ri)
{
    int imm21 = (get_bit(ri, 31)                     << 20) |
                (get_bit_inter(ri, 12, get_mask(8))  << 12) |
                (get_bit(ri, 20)                     << 11) |
                (get_bit_inter(ri, 21, get_mask(10)) << 1);

    return extend_sign(imm21, 21);
}

void decode()
{
    opcode = get_bit_inter(ri, 0,  get_mask(7));
    rs1    = get_bit_inter(ri, 15, get_mask(5));
    rs2    = get_bit_inter(ri, 20, get_mask(5));
    rd     = get_bit_inter(ri, 7,  get_mask(5));
    shamt  = get_bit_inter(ri, 20, get_mask(5));
    funct3 = get_bit_inter(ri, 12, get_mask(3));
    funct7 = get_bit_inter(ri, 25, get_mask(7));

    imm12_i = get_imm12_i(ri);
    imm12_s = get_imm12_s(ri);
    imm13   = get_imm13(ri);
    imm20_u = get_imm20_u(ri);
    imm21   = get_imm21(ri);
}

int get_instr_code()
{
    switch (opcode) {

    case AUIPC : return I_auipc;

    case ECALL : return I_ecall;

    case JAL   : return I_jal;

    case JALR  : return I_jalr;

    case LUI   : return I_lui;

    case BType:
        switch (funct3) {
        case BEQ3  : return I_beq;
        case BNE3  : return I_bne;
        case BLT3  : return I_blt;
        case BGE3  : return I_bge;
        case BLTU3 : return I_bltu;
        case BGEU3 : return I_bgeu;
        default    : return I_nop;}

    case ILAType:
        switch (funct3) {
        case ADDI3 : return I_addi;
        case ANDI3 : return I_andi;
        case SLLI3 : return I_slli;
        case ORI3  : return I_ori;
        case SR3:
            switch (funct7) {
            case SRAI7 : return I_srai;
            case SRLI7 : return I_srli;
            default    : return I_nop;}
        default: return I_nop;}

    case ILType:
        switch (funct3) {
        case LW3  : return I_lw;
        case LB3  : return I_lb;
        case LBU3 : return I_lbu;
        default   : return I_nop;}

    case RegType:
        switch (funct3) {
        case XOR3   : return I_xor;
        case AND3   : return I_and;
        case OR3    : return I_or;
        case SLT3   : return I_slt;
        case SLTU3  : return I_sltu;
        case ADDSUB3:
            switch (funct7) {
            case ADD7 : return I_add;
            case SUB7 : return I_sub;
            default   : return I_nop;}
        default: return I_nop;}

    case StoreType:
        switch (funct3) {
        case SW3 : return I_sw;
        case SB3 : return I_sb;
        default  : return I_nop;}

    default: return I_nop;}
}

void execute()
{
    breg[ZERO] = 0;

    switch (get_instr_code()) {
    case I_add   : f_add();   break;
    case I_addi  : f_addi();  break;
    case I_and   : f_and();   break;
    case I_andi  : f_andi();  break;
    case I_auipc : f_auipc(); break;
    case I_beq   : f_beq();   break;
    case I_bge   : f_bge();   break;
    case I_bgeu  : f_bgeu();  break;
    case I_blt   : f_blt();   break;
    case I_bltu  : f_bltu();  break;
    case I_bne   : f_bne();   break;
    case I_ecall : f_ecall(); break;
    case I_jal   : f_jal();   break;
    case I_jalr  : f_jalr();  break;
    case I_lb    : f_lb();    break;
    case I_lbu   : f_lbu();   break;
    case I_lui   : f_lui();   break;
    case I_lw    : f_lw();    break;
    case I_nop   : f_nop();   break;
    case I_or    : f_or();    break;
    case I_ori   : f_ori();   break;
    case I_sb    : f_sb();    break;
    case I_slt   : f_slt();   break;
    case I_slli  : f_slli();  break;
    case I_sltu  : f_sltu();  break;
    case I_srai  : f_srai();  break;
    case I_srli  : f_srli();  break;
    case I_sub   : f_sub();   break;
    case I_sw    : f_sw();    break;
    case I_xor   : f_xor();   break;
    }
}


void step() {
    fetch();
    decode();
    execute();
}


void run() {
    while(!stop_prg and pc < DATA_SEGMENT_START)
        step();
}


void load_mem(const char *fn, int start) {
    FILE *f;
    int *m_p = mem + (start / 4);

    f = fopen(fn, "rb");
    if(!f){ cout << "Arquivo não encontrado.\n"; exit(0); }
    while(!feof(f)){
        fread(m_p, 4, 1, f);
        m_p++;
    }
    fclose(f);
}


void dump_reg(char format){
    if(format == 'h') cout << hex;

    for(int i=0;i<32;i++)
        cout << breg[i] << endl;

    cout << pc << endl;
    cout << sp << endl;
    cout << gp << endl;

    if(format == 'h') cout << dec;
}

void dump_mem(int start_byte, int end_byte, char format){
    if(format == 'h') cout << hex;

    if(start_byte % 4 != 0 or end_byte % 4 != 0){
        cout << "Endereços não divisíveis por 4!\n";
        return;
    }

    start_byte /= 4;
    end_byte /= 4;
    for(int i=start_byte;i<=end_byte;i++)
        cout << mem[i] << endl;

    if(format == 'h') cout << dec;
}