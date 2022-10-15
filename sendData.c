#include "proto.h"

void sendData()
{
  char data[16];

  printf("\nEnter your message: ");
  scanf("%s",data);

  printf("%s", data);
}