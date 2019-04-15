#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include "alusimulation.h"

/* Uma unidade logica e aritmética
é um dispositivo capaz de realizar operações lógicas(AND,OR,rotação,shift,etc.) e aritmeticas (soma,subtração,etc.).
Uma ULA recebe como entrada um conjunto de operadores e realiza sobre eles uma de suas operações,
escolhida através de uma entradade controle.
Retorna, na saída, o resultado das operações e um conjunto de bits de ​status​, comumente chamados de ​flags​. */


/*
 * Function: exec(int*, int*, int*, int*)
 * -----------------------------------
 *   Executa a operacao na ULA.
 *
 *   @param regA Ponteiro para o registrador A (Acc)
 *   @param regB Ponteiro para o registrador B
 *   @param flags Vetor de Flags
 *   @param oper Operacao selecionada
 *   @returns int flag de execucao bem sucedida
 */
int exec(int* regA, int* regB, int* flags, int* oper) {
    int choosenoper = *oper;
    int output = 0;
    switch (choosenoper) {
        case 0:
        printf("Add\n");
            output = add(regA, regB, flags);
            break;
        case 1:
        printf("Addi\n");
            output = addi(regA, flags);
            break;
        case 2:
        printf("Mult\n");
            output = mult(regA, regB, flags);
            break;
        case 3:
        printf("Div\n");
            output = quoc(regA, regB, flags);
            break;
        case 4:
        printf("Mod\n");
            output = mod(regA, regB, flags);
            break;
        case 5:
            output = and(regA, regB, flags);
            break;
        case 6:
            output = or(regA, regB, flags);
            break;
        case 7:
            output = not(regA, flags);
            break;
        case 8:
            output = shr(regA, flags);
            break;
        case 9:
            output = shl(regA, flags);
            break;
    }
    return output;
}

/*
 * Function: add(int*, int*)
 * -----------------------------------
 *   Executa a operacao de soma. O resultado e armazenado em regA e retorna o ponteiro do vetor de flags
 *
 *   @param regA Ponteiro para o registrador A
 *   @param regB Ponteiro para o registrador B
 *   @returns int* vetor para ponteiro de flags
 */
int add(int* regA, int* regB, int* flags){
    int output = 0;
    int result = *regA + *regB;
    if((*regA < 0 && *regB < 0 && result > 0) || (*regA > 0 && *regB > 0 && result < 0)){
        flags[0] = 1;
        output = 1;
    }
    *regA = result;
    return output;
}

int addi(int* regA, int* flags){
    int output = 0;
    int i = 1;
    output = add(regA, &i, flags);
    return output;
}

int mult(int* regA, int* regB, int* flags){
    int output = 0;
    int result = *regA * *regB;
    if((*regA < 0 && *regB < 0 && result > 0) || (*regA > 0 && *regB > 0 && result < 0)){
        flags[0] = 1;
        output = 1;
    }
    *regA = result;
    return output;
}

int quoc(int* regA, int* regB, int* flags){
    int output = 0;
    if(*regA == INT_MIN && *regB == -1){
        flags[0] = 1;
        output = 1;
        printf("Erro: Estouro de memoria. (verif. flags)\n");
    } else {
        if(*regB == 0){
            flags[1] = 1;
            output = 1;
            printf("Erro: Divisao por zero. (verif. flags)\n");
        } else {
            int result = *regA / *regB;
            *regA = result;
        }
    }
    return output;
}

int mod(int* regA, int* regB, int* flags){
    int output = 0;
    if(*regA == INT_MIN && *regB == -1){
        flags[0] = 1;
        output = 1;
        printf("Erro: Estouro de memoria. (verif. flags)\n");
    } else {
        if(*regB == 0){
            flags[1] = 1;
            output = 1;
            printf("Erro: Divisao por zero. (verif. flags)\n");
        } else {
            int result = *regA % *regB;
            *regA = result;
        }
    }
    return output;
}

int and(int* regA, int* regB, int* flags){

}

int or(int* regA, int* regB, int* flags){

}

int not(int* regA, int* flags){

}

int shr(int* regA, int* flags){

}

int shl(int* regA, int* flags){

}
