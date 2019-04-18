#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BINMAX 32
#define INTMAX 10

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

const char * strtoi(char * strbin, int * val, int base) {
    if(strbin != NULL) {
        int binbuffer = atoi(strbin);
        int dec = 0;
        int i;
        for(i = 0; binbuffer > 0; i++)
        {
            dec = dec + pow(base, i) * (binbuffer % 10);
            binbuffer = binbuffer / 10;
        }
        *val = dec;
        char* strdec = malloc (sizeof(INTMAX));
        sprintf(strdec, "%d", dec);
        return strdec;
    } else {
        return NULL;
    }
}
