#include <stdio.h>
#include <stdlib.h>
#include "processorarchitecture.h"
#include "alusimulation.h"
#include "baseconv.h"

int oper;
int regA;
int regB;

/*  FLAG 1: OVERFLOW
    FLAG 2: DIV/0
    FLAG 3: SHR
    FLAG 4: SHL
*/

int flags[FLAGLEN];

void chooseopt(int opt, int* continuemenu) {
    switch (opt) {
        case 1:
            store('A', &regA);
            break;
        case 2:
            store('B', &regB);
            break;
        case 3:
            load('A', &regA);
            break;
        case 4:
            load('B', &regB);
            break;
        case 5:
            printarray(flags, FLAGLEN);
            break;
        case 6:
            defoperation(&oper);
            break;
        case 7:
            resetarray(flags, FLAGLEN);
            exec(&regA, &regB, flags, &oper);
            break;
        case 8:
            *continuemenu = 0;
            printf("O programa sera encerrado.\n"); break;
        case 0:break;
        default:
            printf("A opcao digitada nao corresponde a nenhuma acao.\n"); break;
    }
}

void store(char identreg, int* reg) {
    long long l;
    printf("Novo valor para o registrador %c: ", identreg);
    scanf("%lld", &l);
    *reg = lbintoi(l);
    printf("Adicionado o valor %d ao registrador %c\n", *reg, identreg);
}

int load(char identreg, int* reg) {
    printf("Conteudo do registrador %c: ", identreg);
    int content;
    switch (identreg) {
        case 'A':
            content = regA; break;
        case 'B':
            content = regB; break;
    }

    printf("%lld (%d em decimal)\n", itolbin(content), content);
    return content;
}

void defoperation(int* oper) {
    system("cls");
    system("clear");
    printf("Operacoes:\n");
    printf("   0. Soma (add)\n");
    printf("   1. Soma imediato (addi)\n");
    printf("   2. Multiplicacao (mult)\n");
    printf("   3. Divisao (div)\n");
    printf("   4. Modulo (mod)\n");
    printf("   5. E (and)\n");
    printf("   6. OU (or)\n");
    printf("   7. NAO (not)\n");
    printf("   8. Deslocamento a direita (shr)\n");
    printf("   9. Deslocamento a esquerda (shl)\n");
    printf("Operacao :> ");
    scanf("%d", oper);
}

void printarray(int* array, int len) {
    printf("OVERFLOW    %d\n", array[0]);
    printf("DIV/0       %d\n", array[1]);
    printf("SHR         %d\n", array[2]);
    printf("SHL         %d\n", array[3]);
}

void resetarray(int* array, int len){
    int i;
    for(i = 0; i < len; i++) {
        array[i] = 0;
    }
}
