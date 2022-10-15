/* Name: Fire Protocol
 * Date: 13th September, 2022
 */
#include "proto.h"

int main(int argc, char const *argv[]) {

  // int *data;
  int response = 0, responseCount = 0;

  // data = (int *)"hello World! This is Sumit Kumar";
  // printf("%s\n", (char *) data);

  /* Show the command line options to the user */
  printf("Welcome to the Fire Protocol.\n\n");

  printf("Select (press the number): \n1. Send Data \n2. Receive Data\n$");
  scanf("%d",&response);

  switch (response)
  {
  case 1:
    sendData();
    break;
  
  case 2:
    printf("\nYour response is 2\n");
    break;
  
  default:
    printf("\nEnter a valid command!\n");
    exit(-1);
    break;
  }

  return 0;
}