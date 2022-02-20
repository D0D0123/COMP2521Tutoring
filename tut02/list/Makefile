CC = gcc
CFLAGS = -Wall -Werror -g

.PHONY: all
all: testList

testList: testList.c IList.o List.o

IList.o: IList.c List.h
RList.o: RList.c List.h
List.o: List.c List.h


.PHONY: clean
clean:
	rm -f testList *.o

