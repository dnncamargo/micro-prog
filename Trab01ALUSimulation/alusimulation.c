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


int exec(int* regA, int* regB, int* result, int* oper) {
    int choosenoper = *oper;
    int output;
    switch (choosenoper) {
        case 1:
            *result = add(regA, regB);
    }
    //printf("%d\n", result);
}


int add(int* regA, int* regB){
    printf("%d %d\n", *regA, *regB );
    int result = *regA + *regB;
    printf("%d\n", result);
    return result;
}
