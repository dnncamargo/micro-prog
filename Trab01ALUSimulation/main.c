#include <stdio.h>
#include <stdlib.h>
#include "processorarchitecture.h"
#include "baseconv.h"
typedef unsigned char byte;
typedef unsigned int uint;

void menu(void);

int strbin_to_dec(const char * str) {
    unsigned int result = 0;
    for (int i = strlen(str) - 1, j = 0; i >= 0; i--, j++) {
        unsigned char k = str[i] - '0';
        k <<= j;
        result += k;
    }
    return result;
}

int main(int argc, char *argv[]) {
    /*char strbin[32];
    int reg;
    fgets(strbin, sizeof(32), stdin);
    strtoi(strbin, &reg, 2);
    printf("%d\n", reg);*/

    char * wbin = "01001001";
    int dec = strbin_to_dec(wbin);
    printf("%s to dziesietnie %d.\n", wbin, dec);
/*

    int  num, binary_val, decimal_val = 0, base = 1, rem;



    printf("Enter a binary number(1s and 0s) \n");

    scanf("%d", &num); /* maximum five digits 

    binary_val = num;

    while (num > 0)

    {

        rem = num % 10;

        decimal_val = decimal_val + rem * base;

        num = num / 10 ;

        base = base * 2;

    }

    printf("The Binary number is = %d \n", binary_val);

    printf("Its decimal equivalent is = %d \n", decimal_val);
/

    /* armazenar em strbin uma sequencia de caracteres de 0 e 1.
    char strbin[BINBUFFER];
    fgets(strbin, sizeof(strbin), stdin);

    int dec;
    int bin = atoi(strbin);

    strtoi(strbin, &dec, 2);

    printf("%d\n", dec);

    itostr(dec, strbin, 2);
    printf("%s\n", strbin);
/*
    int a=54325;
    char buffer[20];
    //itoa(a,buffer,2);   // here 2 means binary
    printf("Binary value = %s\n", buffer);

    //itoa(a,buffer,10);   // here 10 means decimal
    printf("Decimal value = %s\n", buffer);

    //itoa(a,buffer,16);   // here 16 means Hexadecimal
    printf("Hexadecimal value = %s\n", buffer);

    printf("00:: ");
    char strbin0[BINMAX];
    char strdec0[INTMAX];
    int bin0;
    int dec0 = 0;
    fgets(strbin0, sizeof(strbin0), stdin);
    int i;
    //itoa(i, strbin0, 10);
    printf("%d\n", i);

    bin0 = atoi(strbin0);
    printf("String value = %s. Int value = %d\n", strbin0, bin0);
    for(i = 0; bin0 > 0; i++)
    {
        dec0 = dec0 + pow(2, i) * (bin0 % 10);
        bin0 = bin0 / 10;
    }
    printf("\nDecimal Equivalent of Binary Number: \t %d\n", dec0);

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

    //int sum = !bin0*bin1|bin0*!bin1;
*/
    int opt;
    int menuloop;
    printf("PRESSIONE 0 PARA MENU\n");

    menuloop = 1;
    while (menuloop) {
        printf(":> ");
        scanf("%d", &opt);

        if(!opt)
            menu();

        chooseopt(opt, &menuloop);
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
