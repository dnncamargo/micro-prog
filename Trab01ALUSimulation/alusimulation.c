#include<stdio.h>
#include<stdlib.h>
#include "alusimulation.h"

/* Uma unidade logica e aritmética
é um dispositivo capaz de realizar operações lógicas(AND,OR,rotação,shift,etc.) e aritmeticas (soma,subtração,etc.).
Uma ULA recebe como entrada um conjunto de operadores e realiza sobre eles uma de suas operações,
escolhida através de uma entradade controle.
Retorna, na saída, o resultado das operações e um conjunto de bits de ​status​, comumente chamados de ​flags​. */

/*
int* halfadder(int* a, int* b, int* cout){
    return a;
}

int main(){
    int a = 0;
    int b = 0;
    int out;
    int c;
    out = !a*b|a*!b;
    printf("%d\n", out);
    int *ap = &a;


}
*/

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
    int output = 1;
    switch (choosenoper) {
        case 1:
            output = add(regA, regB, flags);
            break;
        case 2:
            output = addi(regA, flags);
            break;
        case 3:
            output = mult(regA, regB, flags);
            break;
        case 4:
            output = and(regA, regB, flags);
            break;
        case 5:
            output = or(regA, regB, flags);
            break;
        case 6:
            output = not(regA, flags);
            break;
        case 7:
            output = shr(regA, flags);
            break;
        case 8:
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
    return 1;
}

int addi(int* regA, int* flags){
    int output = 0;
    int result = *regA + 1;
    if((*regA < 0 && result > 0) || (*regA > 0 && result < 0)){
        flags[0] = 1;
        output = 1;
    }
    *regA = result;
    return output;
}

int mult(int* regA, int* regB, int* flags){

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
