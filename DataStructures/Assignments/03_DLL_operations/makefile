OBJ :=$(patsubst %.c, %.o, $(wildcard *.c))
dll : $(OBJ)
	gcc -o $@ $^
clean:
	rm *.o
