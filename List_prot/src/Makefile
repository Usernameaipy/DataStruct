CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic
BUILDDIR=../build/

all : list

list : list_test.o list.o
	$(CC) $(CFLAGS) list_test.o list.o -o $(BUILDDIR)list

list_test.o : list_test.c list_test.h
	$(CC) $(CFLAGS) -c list_test.c -o list_test.o

list.o : list.c list.h
	$(CC) $(CFLAGS) -c list.c -o list.o

clean : 
	rm -rf *.o
	rm -rf ../build/*

rebuild : clean all