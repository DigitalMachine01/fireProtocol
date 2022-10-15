/* Include */
#include <stdio.h>
#include<stdlib.h>

/* Global declarations */
typedef struct firePacket_t
{
  char start;
  char command;
  int data[4];
  char footer;
} firePacket;

/* Function declarations */
void sendData();