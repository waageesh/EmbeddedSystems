SRC:=$(wildcard *.c)
OBJ:=$(patsubst %.c,%.o,$(SRC))
CFLAGS:=-g
bst_delete_node : $(OBJ)
	gcc -o $@ $(OBJ)
clean :
	rm *.o
