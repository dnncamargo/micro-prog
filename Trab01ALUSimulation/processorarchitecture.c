#include<stdio.h>
#include<stdlib.h>
#include "processorarchitecture.h"
#include "alusimulation.h"

int oper;
int regA;
int regB;
int result;

/*  FLAG 1: OVERFLOW
    FLAG 2: DIV/0
    FLAG 3: SHR
    FLAG 4: SHL
*/
int flags[FLAGLEN];

void chooseopt(int opt, int* continuemenu) {
    switch (opt) {
        case 1:
            store(&regA, 'A');
            break;
        case 2:
            store(&regB, 'B');
            break;
        case 3:
            load('A');
            break;
        case 4:
            load('B');
            break;
        case 5:

            break;
        case 6:
            defoperation(&oper);
            break;
        case 7:
            exec(&regA, &regB, &result, &oper);
            break;
        case 8:
            *continuemenu = 0;
            printf("O programa sera encerrado.\n"); break;
        default:
            printf("A opcao digitada nao corresponde a nenhuma acao.\n"); break;
    }
}

void store(int* reg, char identreg) {
    printf("Valor do registrador %c: ", identreg);
    int value;
    scanf("%d", &value);
    *reg = value;
    printf("\n");
}

int load(char identreg) {
    printf("Conteudo do registrador %c: ", identreg);
    int content;
    switch (identreg) {
        case 'A':
            content = regA; break;
        case 'B':
            content = regB; break;
    }
    printf("%d\n", content);
    return content;
}

void defoperation(int* oper) {
    system("cls");
    printf("Operacoes:\n");
    printf("   1. Soma (add)\n");
    printf("   2. Soma imediato (addi)\n");
    printf("   3. Multiplicacao (mult)\n");
    printf("   4. E (and)\n");
    printf("   5. OU (or)\n");
    printf("   6. NAO (not)\n");
    printf("   7. Deslocamento a direita (shr)\n");
    printf("   8. Deslocamento a esquerda (shl)\n");

    *oper = scanf("%d", oper);
}
