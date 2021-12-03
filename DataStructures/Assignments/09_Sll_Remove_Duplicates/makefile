OBJ :=$(patsubst %.c, %.o, $(wildcard *.c))
sll_remove_duplicates : $(OBJ)
	gcc -o $@ $^
clean:
	rm *.o
