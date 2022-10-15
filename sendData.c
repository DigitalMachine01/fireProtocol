#include "proto.h"

#define MAXSIZE 256

void sendData()
{
  char* data = malloc(MAXSIZE + 1);

  printf("\nEnter your message: ");
  
  /* flushes the standard input - (clears the input buffer) */
  while ((getchar()) != '\n');

  fgets(data, MAXSIZE, stdin);

  if( strlen(data) > 0 && (data[strlen(data) - 1] == '\n'))
  {
    data[strlen(data) - 1] = '\0';
  }

  /* Write code to frame the fire packet */
}