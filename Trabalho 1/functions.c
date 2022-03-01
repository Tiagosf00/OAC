/*

	Trabalho 1 - OAC - Turma C - 2021/2

	Tiago de Souza Fernandes - 180131818

	Desafio Extra: Todas as funções implementadas em 1 linha!
	(Fica zero legível, mas é divertido)

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MEM_SIZE 4096
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


int main() {

	// Testes

	// 1.
	printf("Testes 1:\n");
	sb(0, 0, 0x04); sb(0, 1, 0x03); sb(0, 2, 0x02); sb(0, 3, 0x01);
	sb(4, 0, 0xFF); sb(4, 1, 0xFE); sb(4, 2, 0xFD); sb(4, 3, 0xFC);
	sw(12, 0, 0xFF);
	sw(16, 0, 0xFFFF);
	sw(20, 0, 0xFFFFFFFF);
	sw(24, 0, 0x80000000);
	printf("Feito.\n");

	// 2.
	printf("\nTestes 2:\n");
	for (int i = 0; i <= 6; i++) {
		printf("mem[%d] = %08X\n", i, mem[i]);
	}

	// 3.
	printf("\n\nTestes 3:\n");
	// a)
	{	
		printf("\na)\n");
		printf("	lb(4, 0) = %d\n", lb(4, 0));
		printf("	lb(4, 1) = %d\n", lb(4, 1));
		printf("	lb(4, 2) = %d\n", lb(4, 2));
		printf("	lb(4, 3) = %d\n", lb(4, 3));
	}

	// b)
	{
		printf("\nb)\n");
		printf("	lbu(4, 0) = %d\n", lbu(4, 0));
		printf("	lbu(4, 1) = %d\n", lbu(4, 1));
		printf("	lbu(4, 2) = %d\n", lbu(4, 2));
		printf("	lbu(4, 3) = %d\n", lbu(4, 3));
	}

	// c)
	{
		printf("\nc)\n");
		printf("	lw(12, 0) = %d\n", lw(12, 0));
		printf("	lw(16, 0) = %d\n", lw(16, 0));
		printf("	lw(20, 0) = %d\n", lw(20, 0));
	}


	// Testes Extras

	sb(0, 0, 0x11); sb(0, 1, 0xAC); sb(0, 2, 0xC0); sb(0, 3, 0x0A);
	sw(4, 0, 0x0AC0AC11);
	sw(8, 0, 0x0AC);
	sb(12, 0, 0xAC); sb(12, 1, 0x00); sb(12, 2, 0x00); sb(12, 3, 0x00);
	// mem 16 = lixo dos últimos testes
	sw(20, 0, 0x0AC0AC);
	sw(20, 0, 0x01234567);
	sw(24, 0, 0x01234567);
	sw(24, 0, 0x89ABCDEF);


	printf("\n\nTestes Extras:\n\n");
	for (int i = 0; i <= 6; i++) {
		printf("mem[%d] = %08X\n", i, mem[i]);
	}

	{	

		printf("\n");
		// lb
		printf("lb(24, 0) = %d\n", lb(24, 0));
		printf("lb(24, 1) = %d\n", lb(24, 1));
		printf("lb(24, 2) = %d\n", lb(24, 2));
		printf("lb(24, 3) = %d\n", lb(24, 3));
		printf("\n");
		// lbu
		printf("lbu(24, 0) = %d\n", lbu(24, 0));
		printf("lbu(24, 1) = %d\n", lbu(24, 1));
		printf("lbu(24, 2) = %d\n", lbu(24, 2));
		printf("lbu(24, 3) = %d\n", lbu(24, 3));
		printf("\n");
		// lw
		printf("lw(12, 0) = %d\n", lw(12, 0));
		printf("lw(16, 0) = %d\n", lw(16, 0));
		printf("lw(20, 0) = %d\n", lw(20, 0));
		printf("\n");
	}
	// error
	{
		int32_t lw1 = lw(0, 1);
		int32_t lw2 = lw(0, 2);
		int32_t lw3 = lw(0, 3);
		printf("lw(0, 1) = %d\n", lw1);
		printf("lw(0, 2) = %d\n", lw2);
		printf("lw(0, 3) = %d\n", lw3);
		sw(0, 1, 0x0);
		sw(0, 2, 0x0);
		sw(0, 3, 0x0);
	}

	return 0;
}