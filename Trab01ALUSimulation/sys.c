#include <stdio.h>
#include <stdlib.h>
#include "sys.h"

void clscr(void)
{
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    system("clear");
//add some other OSes here if needed
#else
    #error "OS not supported."
    //you can also throw an exception indicating the function can't be used
#endif
}

void clbuff(void)
{
    char c;
    while((c=getchar()) != '\n' && c != EOF);
}
