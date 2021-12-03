OBJ :=$(patsubst %.c, %.o, $(wildcard *.c))
sll_insert_sorted_find_node : $(OBJ)
	gcc -o $@ $^
clean:
	rm *.o
