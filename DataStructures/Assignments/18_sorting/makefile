SRC:=$(wildcard *.c)
OBJ:=$(patsubst %.c,%.o,$(SRC))
CFLAGS:=-g
sort : $(OBJ)
	gcc -o $@ $(OBJ)
clean :
	rm *.o
