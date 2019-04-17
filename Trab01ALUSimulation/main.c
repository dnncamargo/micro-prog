#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include "processorarchitecture.h"

#define BINMAX 32
#define INTMAX 10

void menu(void);

int main(int argc, char *argv[]) {

    printf("00:: ");
    char strbin0[BINMAX];
    char strdec0[INTMAX];
    int bin0;
    int dec0 = 0;
    fgets(strbin0, sizeof(strbin0), stdin);

    bin0 = atoi(strbin0);
    printf("String value = %s. Int value = %d\n", strbin0, bin0);
    int i;
    for(i = 0; bin0 > 0; i++)
    {
        dec0 = dec0 + pow(2, i) * (bin0 % 10);
        bin0 = bin0 / 10;
    }
    printf("\nDecimal Equivalent of Binary Number: \t %d\n", dec);

    printf("01:: ");
    char strbin1[BINMAX];
    char strdec1[INTMAX];
    int bin1;
    int dec1 = 0;
    fgets(strbin1, sizeof(strbin1), stdin);

    bin1 = atoi(strbin1);
    printf("String value = %s. Int value = %d\n", strbin1, bin1);
    for(i = 0; bin1 > 0; i++)
    {
        dec1 = dec1 + pow(2, i) * (bin1 % 10);
        bin1 = bin1 / 10;
    }
    printf("\nDecimal Equivalent of Binary Number: \t %d\n", dec1);

    int sum = !bin0*bin1|bin0*!bin1;

    int opt;
    int menuloop;
    printf("PRESSIONE 0 PARA MENU\n");

    menuloop = 1;
    while (menuloop) {
        printf(":> ");
        scanf("%d", &opt);

        if(!opt)
            menu();

        //chooseopt(opt, &menuloop);
    }
    return 0;
}

void menu() {

    printf("Menu Principal da ULA\n\n");
    printf("   1.  Definir registrador A\n");
    printf("   2.  Definir registrador B\n");
    printf("   3.  Ler registrador A (Acc)\n");
    printf("   4.  Ler registrador B\n");
    printf("   5.  Ler registrador de flags\n");
    printf("   6.  Definir operacao\n");
    printf("   7.  Executar ULA\n");
    printf("   8.  Sair\n");

}

/*
int* halfadder(int* a, int* b, int* cout){
    return !a*b|a*!b;;
}
*/
