#include "proto.h"

#define MAXSIZE 256

void createDataPacketChain(char*, dataPackets_st**);

void sendData()
{
  dataPackets_st* dataHeadPointer = 0; 
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

void createDataPacketChain(char* data, dataPackets_st** dataHeadPointer_ptr)
{
    int packet, totalNumberofPackets;
    int array_size, charCounter, holder;

    dataPackets_st *temp, *previous_temp;

    totalNumberofPackets = (((strlen(data))%16) == ((strlen(data))/16) ? ((strlen(data))%16) : (((strlen(data))%16) + 1));

    if(totalNumberofPackets < 1)
    {
        printf("\nNo data to be sent!\n");
        exit(1);
    }

    for(packet = 0; packet < totalNumberofPackets; packet++)
    {
        temp = malloc(sizeof(dataPackets_st));

        array_size = 0;
        charCounter = 0;
        holder = 0;
        
        /* Update the data fields of the temp here*/

        temp->next = 0;

        temp->firePacket.start = '$';
        temp->firePacket.command = 1 + '0'; //Command '1' is for strt of the data packet stream

        for(array_size = 0; array_size < 4; array_size++)
        {
            while((charCounter % 4) < 4)
            {
                holder = ((int)data[packet*16 + charCounter]) << (3-(charCounter%4));
                temp->firePacket.msg[array_size] = holder;
                charCounter++;
            }
        }

        temp->firePacket.footer = '%';

        if(*dataHeadPointer_ptr == 0)
        {
            *dataHeadPointer_ptr = temp;
        }
        else
        {
            previous_temp->next = temp;
        }

        previous_temp = temp;
    }
    
}