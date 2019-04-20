#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "baseconv.h"

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

/* Funcao stroi
 * Recebe uma sequencia de numeros binarios em string e converte para decimal inteiro
 */
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

// inline function to swap two numbers
void swap(char *x, char *y) {
	char t = *x; *x = *y; *y = t;
}

// function to reverse buffer[i..j]
char* reverse(char *buffer, int i, int j)
{
	while (i < j)
		swap(&buffer[i++], &buffer[j--]);

	return buffer;
}

// Iterative function to implement itoa() function in C
char* baseconv(int value, char* buffer, int base)
{
	// invalid input
	if (base < 2 || base > 32)
		return buffer;

	// consider absolute value of number
	int n = abs(value);

	int i = 0;
	while (n)
	{
		int r = n % base;

		if (r >= 10)
			buffer[i++] = 65 + (r - 10);
		else
			buffer[i++] = 48 + r;

		n = n / base;
	}

	// if number is 0
	if (i == 0)
		buffer[i++] = '0';

	// If base is 10 and value is negative, the resulting string
	// is preceded with a minus sign (-)
	// With any other base, value is always considered unsigned
	if (value < 0 && base == 10)
		buffer[i++] = '-';

	buffer[i] = '\0'; // null terminate string

	// reverse the string and return it
	return reverse(buffer, 0, i - 1);
}
