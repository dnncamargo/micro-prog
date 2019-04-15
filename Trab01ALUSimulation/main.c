#include <stdio.h>
#include "processorarchitecture.h"

void menu(void);

int main(int argc, char *argv[]) {

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
