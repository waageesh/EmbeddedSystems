OBJ :=$(patsubst %.c, %.o, $(wildcard *.c))
queue_using_array : $(OBJ)
	gcc -o $@ $^
clean:
	rm *.o
