OBJ :=$(patsubst %.c, %.o, $(wildcard *.c))
sll_merge_list_sorted : $(OBJ)
	gcc -o $@ $^
clean:
	rm *.o
