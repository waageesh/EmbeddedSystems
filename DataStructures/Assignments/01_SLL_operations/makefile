OBJ :=$(patsubst %.c, %.o, $(wildcard *.c))
sll : $(OBJ)
	gcc -o $@ $^
clean:
	rm *.o
