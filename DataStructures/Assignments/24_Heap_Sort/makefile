SRC:=$(wildcard *.c)
OBJ:=$(patsubst %.c,%.o,$(SRC))
CFLAGS:=-g
heap_sort : $(OBJ)
	gcc -o $@ $(OBJ)
clean :
	rm *.o
