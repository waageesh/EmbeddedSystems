OBJ :=$(patsubst %.c, %.o, $(wildcard *.c))
stack : $(OBJ)
	gcc -o $@ $^
clean:
	rm *.o
