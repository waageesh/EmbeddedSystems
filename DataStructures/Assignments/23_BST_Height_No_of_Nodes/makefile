SRC:=$(wildcard *.c)
OBJ:=$(patsubst %.c,%.o,$(SRC))
CFLAGS:=-g
bst_height_no_of_nodes : $(OBJ)
	gcc -o $@ $(OBJ)
clean :
	rm *.o
