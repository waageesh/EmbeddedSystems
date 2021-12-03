OBJ :=$(patsubst %.c, %.o, $(wildcard *.c))
sll_linkedlist_sort_nodes : $(OBJ)
	gcc -o $@ $^
clean:
	rm *.o
