/* Include */
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

/* Global declarations */
typedef struct firePacket_t
{
  char start;
  char command;
  char msg_bytes[16];
  char footer;
} firePacket_st;

/* for a linked list */
typedef struct dataPackets_t
{
  firePacket_st firePacket;
  struct dataPackets_t* next;
}dataPackets_st;

/* Function declarations */
void sendData();