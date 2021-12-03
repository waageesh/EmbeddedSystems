SRC:=$(wildcard *.c)
OBJ:=$(patsubst %.c,%.o,$(SRC))
CFLAGS:=-g
bst_search_max_node : $(OBJ)
	gcc -o $@ $(OBJ)
clean :
	rm *.o
