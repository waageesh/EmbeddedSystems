OBJ :=$(patsubst %.c, %.o, $(wildcard *.c))
hash_table : $(OBJ)
	gcc -o $@ $^
clean:
	rm *.o
