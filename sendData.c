#include "proto.h"

#define MAXSIZE 256

void createDataPacketChain(char*, dataPackets_st**);

void sendData()
{
  dataPackets_st* dataHeadPointer; 
  char* data = malloc(MAXSIZE + 1);

  printf("\nEnter your message: ");
  
  /* flushes the standard input - (clears the input buffer) */
  while ((getchar()) != '\n');

  fgets(data, MAXSIZE, stdin);

  if( strlen(data) > 0 && (data[strlen(data) - 1] == '\n'))
  {
    data[strlen(data) - 1] = '\0';
  }

  /* frame the fire packet */

  createDataPacketChain(data, &dataHeadPointer);
}

void createDataPacketChain(char * data_ptr, dataPackets_st** dataHeadPointer_ptr)
{
    
}