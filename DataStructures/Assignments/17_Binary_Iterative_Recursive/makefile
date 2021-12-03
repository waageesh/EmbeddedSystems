OBJ :=$(patsubst %.c, %.o, $(wildcard *.c))
binary_search : $(OBJ)
	gcc -o $@ $^
clean:
	rm *.o
