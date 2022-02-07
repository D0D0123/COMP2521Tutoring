
CC = gcc
CFLAGS = -Wall -Werror -g

all: treeprog

treeprog: treeprog.c BSTree.c BSTree.h
	$(CC) $(CFLAGS) -o treeprog BSTree.c treeprog.c

clean:
	rm treeprog