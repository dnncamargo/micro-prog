#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BINMAX 32
#define INTMAX 10

int isbin(int);

const char * strtoi(char *, int*, int);

void swap(char *, char *);

char* reverse(char *, int, int);

char* baseconv(int, char*, int);
