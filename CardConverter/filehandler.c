#include <stdio.h>
#include <stdlib.h>
#include "filehandler.h"

#define BUFFERLEN 10

int filereader(char * filename) {
   char ch;
   FILE *fp;

   fp = fopen(filename, "r");

   if (fp == NULL) {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

   char buffstr [BUFFERLEN];
   //if ( fgets (buff, 100, pFile) != NULL )
     //puts (buff);

   while((ch = fgetc(fp)) != EOF) {
       while (ch != '\0') {
           buffstr = buffstr + ch;
       }
       printf("%c", buffstr);
   }


   fclose(fp);
   return 0;
}


/* fgets example
#include <stdio.h>

int main()
{
   FILE * pFile;
   char mystring [100];

   pFile = fopen ("myfile.txt" , "r");
   if (pFile == NULL) perror ("Error opening file");
   else {
     if ( fgets (mystring , 100 , pFile) != NULL )
       puts (mystring);
     fclose (pFile);
   }
   return 0;
}
*/
