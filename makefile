#Usage:
#make		#complie all binaries
#make clean #remove all binaries and objects

TARGET = fire_app

$(TARGET): fire_app.o fire.a
	@echo "building the fire application.."
	gcc $^ -o $@

fire_app.o: fire_app.c
	gcc -c $< -o $@

fire.a: fire.o
	ar rcs $@ $^

fire.o: fire.c fire.h
	gcc -g -c -o $@ $<

clean:
	@echo "cleaning up.."
	rm -f *.o *.a $(TARGET)