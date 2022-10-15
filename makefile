#Usage:
#make		#complie all binaries
#make clean #remove all binaries and objects

OBJECTS = proto.o sendData.o

fire: $(OBJECTS)
	@echo "building fire"
	@gcc -o fire proto.o sendData.o

proto.o: proto.c proto.h
	@echo "produced proto.o"
	@gcc -g -c -o proto.o proto.c 

sendData.o: sendData.c proto.h
	@echo "produced sendData.o"
	@gcc -g -c -o sendData.o sendData.c

clean:
	@echo "Cleaning up.."
	@rm *.o