#include <stdio.h>
#include <stdlib.h>
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
            output = add(regA, regB, flags);
            break;
        case 1:
            output = addi(regA, flags);
            break;
        case 2:
            output = mult(regA, regB, flags);
            break;
        case 3:
            output = quoc(regA, regB, flags);
            break;
        case 4:
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
            output = shr(regA, regB, flags);
            break;
        case 9:
            output = shl(regA, regB, flags);
            break;
    }
    return output;
}

/*
 * Function: add(int*, int*, int*)
 * -----------------------------------
 *   Executa a operacao de soma. O resultado e armazenado em regA e armazena valores no vetor de flags se houver erro
 *
 *   @param regA Ponteiro para o registrador A
 *   @param regB Ponteiro para o registrador B
 *   @param flags Ponteiro para o vetor de flags
 *   @returns int para sinalizar evento
 */
int add(int* regA, int* regB, int* flags){
    int output = 0;
    int result = *regA + *regB;
    if((*regA < 0 && *regB < 0 && result > 0) || (*regA > 0 && *regB > 0 && result < 0)){
        flags[0] = 1;
        output = 1;
        printf("Erro: Estouro de memoria. (verif. flags)\n");
    }
    *regA = result;
    return output;
}

/*
 * Function: addi(int*)
 * -----------------------------------
 *   Executa a operacao de incremento. O resultado e armazenado em regA e retorna o ponteiro do vetor de flags se houver erro
 *
 *   @param regA Ponteiro para o registrador A
 *   @param flags Ponteiro para o vetor de flags
 *   @returns int para sinalizar evento
 */
int addi(int* regA, int* flags){
    int output = 0;
    int i = 1;
    output = add(regA, &i, flags);
    return output;
}

/*
 * Function: mult(int*, int*, int*)
 * -----------------------------------
 *   Executa a operacao de multiplicacao. O resultado e armazenado em regA e armazena valores no vetor de flags se houver erro
 *
 *   @param regA Ponteiro para o registrador A
 *   @param regB Ponteiro para o registrador B
 *   @param flags Ponteiro para o vetor de flags
 *   @returns int para sinalizar evento
 */
int mult(int* regA, int* regB, int* flags){
    int output = 0;
    int result = *regA * *regB;
    if((*regA < 0 && *regB < 0 && result > 0) || (*regA > 0 && *regB > 0 && result < 0)){
        flags[0] = 1;
        output = 1;
        printf("Erro: Estouro de memoria. (verif. flags)\n");
    }
    *regA = result;
    return output;
}

/*
 * Function: quoc(int*, int*, int*)
 * -----------------------------------
 *   Executa a operacao de divisao. O resultado e armazenado em regA e armazena valores no vetor de flags se houver erro
 *
 *   @param regA Ponteiro para o registrador A
 *   @param regB Ponteiro para o registrador B
 *   @param flags Ponteiro para o vetor de flags
 *   @returns int para sinalizar evento
 */
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

/*
 * Function: mod(int*, int*, int*)
 * -----------------------------------
 *   Executa a operacao de resto da divisao. O resultado e armazenado em regA e armazena valores no vetor de flags se houver erro
 *
 *   @param regA Ponteiro para o registrador A
 *   @param regB Ponteiro para o registrador B
 *   @param flags Ponteiro para o vetor de flags
 *   @returns int para sinalizar evento
 */
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

/*
 * Function: and(int*, int*, int*)
 * -----------------------------------
 *   Executa a operacao de e binario. O resultado e armazenado em regA e armazena valores no vetor de flags se houver erro
 *
 *   @param regA Ponteiro para o registrador A
 *   @param regB Ponteiro para o registrador B
 *   @param flags Ponteiro para o vetor de flags
 *   @returns int para sinalizar evento
 */
int and(int* regA, int* regB, int* flags){
    int output = 0;
    int result = *regA & *regB;
    if((*regA < 0 && *regB < 0 && result > 0) || (*regA > 0 && *regB > 0 && result < 0)){
        flags[0] = 1;
        output = 1;
        printf("Erro: Estouro de memoria. (verif. flags)\n");
    }
    *regA = result;
    return output;
}

/*
 * Function: or(int*, int*, int*)
 * -----------------------------------
 *   Executa a operacao de ou binario. O resultado e armazenado em regA e armazena valores no vetor de flags se houver erro
 *
 *   @param regA Ponteiro para o registrador A
 *   @param regB Ponteiro para o registrador B
 *   @param flags Ponteiro para o vetor de flags
 *   @returns int para sinalizar evento
 */
int or(int* regA, int* regB, int* flags){
    int output = 0;
    int result = *regA | *regB;
    if((*regA < 0 && *regB < 0 && result > 0) || (*regA > 0 && *regB > 0 && result < 0)){
        flags[0] = 1;
        output = 1;
        printf("Erro: Estouro de memoria. (verif. flags)\n");
    }
    *regA = result;
    return output;
}

/*
 * Function: not(int*, int*)
 * -----------------------------------
 *   Executa a operacao de not binario. O resultado e armazenado em regA e armazena valores no vetor de flags se houver erro
 *
 *   @param regA Ponteiro para o registrador A
 *   @param regB Ponteiro para o registrador B
 *   @param flags Ponteiro para o vetor de flags
 *   @returns int para sinalizar evento
 */
int not(int* regA, int* flags){
    int output = 0;
    if(*regA == INT_MIN){
        flags[0] = 1;
        output = 1;
        printf("Erro: Estouro de memoria. (verif. flags)\n");
    } else {
        int result = *regA;
        *regA = !result;
    }
    return output;
}

/*
 * Function: shr(int*, int*, int*)
 * -----------------------------------
 *   Executa a operacao de deslocamento a direita binario. O resultado e armazenado em regA e armazena valores no vetor de flags se houver erro
 *
 *   @param regA Ponteiro para o registrador A
 *   @param regB Ponteiro para o registrador B
 *   @param flags Ponteiro para o vetor de flags
 *   @returns int para sinalizar evento
 */
int shr(int* regA, int* regB, int* flags){
    int output = 0;
    int result = *regA << *regB;
    if((*regA < 0 && *regB < 0 && result > 0) || (*regA > 0 && *regB > 0 && result < 0)){
        flags[0] = 1;
        flags[2] = 0;
        output = 1;
        printf("Erro: Estouro de memoria. (verif. flags)\n");
    }
    *regA = result;
    flags[2] = 1;
    return output;
}

/*
 * Function: shr(int*, int*, int*)
 * -----------------------------------
 *   Executa a operacao de deslocamento a esquerda binario. O resultado e armazenado em regA e armazena valores no vetor de flags se houver erro
 *
 *   @param regA Ponteiro para o registrador A
 *   @param regB Ponteiro para o registrador B
 *   @param flags Ponteiro para o vetor de flags
 *   @returns int para sinalizar evento
 */
int shl(int* regA, int* regB, int* flags){
    int output = 0;
    int result = *regA >> *regB;
    if((*regA < 0 && *regB < 0 && result > 0) || (*regA > 0 && *regB > 0 && result < 0)){
        flags[0] = 1;
        flags[2] = 0;
        output = 1;
        printf("Erro: Estouro de memoria. (verif. flags)\n");
    }
    *regA = result;
    flags[2] = 1;
    return output;
}
