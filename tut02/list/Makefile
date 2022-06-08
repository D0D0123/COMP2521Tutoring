CC = gcc
CFLAGS = -Wall -Werror -g

.PHONY: all
all: testList

List.o: List.c List.h
testList: testList.c RList.o List.o

# IList.o: IList.c List.h
# SolRList.o: SolRList.c List.h
RList.o: RList.c List.h


.PHONY: clean
clean:
	rm -f testList *.o

