/* This is a header file for the fire protocol which I start writing on 13th Sep
 * 2022, This header file contains the typedef structures of my protocol packets
 * that I want to form in my send function (given the data byte, I can form this
 * packet and put it on any port to send it across. This protocol sits sandwiche
 * -d in between two layers of any mechanism of sending and receving bytes, wher
 * -e it takes the bytes from the layer and frame fire packet, which gets passed
 * to the layer below for it to get transferred to the receiver. At the receiver
 * side the lower layer gives the packet to my prtocol. My recieve functions tak
 * -es care of the received fire packet. It checks whether the CRC is apt for th
 * -e received packet, then deframes the data based on the length parameter. It
 * also keeps in mind the start and end character, by this it knows that the sen
 * -der wants to start communication and the sender has sent all the data it wan
 * -ted to. It has nothing to say anymore. To get the data, receiver defines a b
 * -uffer*/

typedef struct firePacket_t
{
  char start;
  char command;
  int data[4];
  char footer;
} firePacket;

int commandLineInterface(void);

firePacket *frameMaster(char command, int *data);

int *receiver(firePacket fire_packet_rcvd);
