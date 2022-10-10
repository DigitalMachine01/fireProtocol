#include "proto.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {

  int *data;
  int c;

  data = (int *)"hello World! This is Sumit Kumar";

  printf("%s\n", (char *) data);

  /* Show the command line options to the user */

  c = commandLineInterface();
  printf("\n%d",c);

  return 0;
}

/* This function reveals different options available to the user
 * under fire protocol and uses it to get the users expectation as
 * an input*/

 int commandLineInterface(void)
 {
   int cmd;
   printf("Welcome to the Fire Protocol.\n\n");
   printf("Press number to choose from below options\n");
   printf("1. Send\n2. Receive\n\n");

   scanf("%d", &cmd);
   switch (cmd)
   {
       case 1:
       {
         return 1;
       }

       case 2:
       {
         return 2;
       }
       default:
       {
         printf("Invalid Command, Try again\n");
         return 0;
       }
    }

}
