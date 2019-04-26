#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BINMAX 32
#define OFF '0'
#define ON '1'

int scanftob(int*);

int isbin(char*);

int main(){
    typedef unsigned int bit;
    bit reg[BINMAX];
    scanftob(reg);
/*
    reg[0] = 0;
    reg[0] = !reg0[0];
    printf("%d\n", reg[0]);*/
}

int scanftob(int* vbit) {
    char bitarray[BINMAX];
    memset(bitarray, OFF, BINMAX);
    fgets(bitarray, BINMAX, stdin);
    printf("%d\n", strlen(bitarray));
    int i;
    for(i = 0; i < strlen(bitarray); i++) {
        printf("%c", bitarray[i]);
    }


    if(isbin(bitarray)){
        printf("is binary\n");
    } else {
        printf("is not binary\n");
    }
}

int isbin(char* bitarray) {
    int i;
    for (i = 0; i < BINMAX; i++) {
        if((bitarray[i] != ON) && (bitarray[i] != OFF)){
            return 0;
        }
    }
    return 1;
}

/*
int isbin(int bin) {
    int i, j;
    for (i = 0; i < bin; i++) {
        j = bin % 10;
        if((j != 0) || (j != 1)){
            return 0;
        }
        bin = bin/10;
    }
    return 1;
}
*/
