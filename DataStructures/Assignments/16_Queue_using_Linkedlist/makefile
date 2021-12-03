OBJ :=$(patsubst %.c, %.o, $(wildcard *.c))
queuelist : $(OBJ)
	gcc -o $@ $^
clean:
	rm *.o
