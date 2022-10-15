# fireProtocol
Fire Packets (4 bytes):

SOF (8 bits) 	Command (8 bits)	 Payload (16 bytes)	Footer (8 bits)

It gets 1 byte from the upper layer.
It’s a single layer, stateless protocol i.e. complete information is present in every packet that is exchanged between two devices.
A device can be sender or receiver at different points of time.
	
	Header (16bits):
	
			i. SOF (8bits)
			
			CB	CB	CB	CB	CB	CB	CB	CB
			
			CB - Character Bit
			
			Start - Start of the communication - $
			End - End of the communication - !
			Escape - Repeat twice
			
			ii. Command (8bits)
			
			Opcode bit for get() / set() 	Sub Op	Sub Op	Sub Op	LB	LB	LB	LB
			
			Sub Op -> Sub Opcode
			LB -> Length Bit
			
			Bit 0: To define if it’s a get command or set command
			Bit 1,2,3: A total of 7 different Sub opcodes available for each Opcode commands
			Bit 4,5,6,7: Bits to decide the field of interest for the command from the agreed upon data structure.
		
	Data (8 bits)
			
			Data	Data	Data	Data	Data	Data	Data	Data
			
			Data -> Data Bit
	
	Footer (8 bits):
		
			CRC	CRC	CRC	CRC	CRC	CRC	CRC	CRC
		
			CRC -> Error Correction Bit: Empowers the Protocol to detect, correct bit flips.
	

Simplify SOF
More Data bits
Field bits can be length of the data 




Foot Notes:

	- Field Parameter: Get the field and set the field that we are agreed upon
	- Response Packet: For this opcode and this Sub Opcode, I acknowledge that how many packet are done.
	- Bigger Picture : Transaction -> Purpose is to complete it -> Both parties has to know about it -> They must be satisfied with the transaction
	- Both can take sender and receiver role at different times
	- Sender cant send anything and expect the receiver to understand it
	- Both parties are clear about the protocol
	- No Assumptions
	- Loop back , socket
	- No Data can start with $
	- Receiver State Machine 
	- Last bit signifies - okay all things are done
	- ECB -> Checksum / CRC
	

![image](https://user-images.githubusercontent.com/69559993/195980773-dc8f1dd2-2902-4fe2-9aff-c25391ea92a5.png)
