CC = gcc

fire: proto.o sendData.o
	@echo "building fire"
	@gcc -o fire proto.o sendData.o

proto.o: proto.c proto.h
	@echo "building proto.o"
	@gcc -g -c -o proto.o proto.c 

sendData.o: sendData.c proto.h
	@echo "building sendData.o"
	@gcc -g -c -o sendData.o sendData.c

clean:
	@echo "Cleaning up.."
	@rm *.o