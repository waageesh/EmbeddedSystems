OBJ :=$(patsubst %.c, %.o, $(wildcard *.c))
infix_prefix : $(OBJ)
	gcc -o $@ $^
clean:
	rm *.o
