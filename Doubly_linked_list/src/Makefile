CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic
BUILDDIR=../build/

all : test_list_dl

test_list_dl : test_list_dl.o list_dl.o
	$(CC) $(CFLAGS) test_list_dl.o list_dl.o -o $(BUILDDIR)test_list_dl

test_list_dl.o : test_list_dl.c test_list_dl.h
	$(CC) $(CFLAGS) -c test_list_dl.c -o test_list_dl.o

list_dl.o : list_dl.c list_dl.h
	$(CC) $(CFALGS) -c list_dl.c -o list_dl.o

clean :
	rm -rf *o
	rm -rf $(BUILDDIR)*

rebuild : clean all