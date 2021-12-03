OBJ :=$(patsubst %.c, %.o, $(wildcard *.c))
infix_postfix : $(OBJ)
	gcc -o $@ $^
clean:
	rm *.o
