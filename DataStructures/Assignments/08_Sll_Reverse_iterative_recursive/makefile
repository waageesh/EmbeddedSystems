OBJ :=$(patsubst %.c, %.o, $(wildcard *.c))
sll_linkedlist_reverse : $(OBJ)
	gcc -o $@ $^
clean:
	rm *.o
