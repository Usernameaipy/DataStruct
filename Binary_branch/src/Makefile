CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic
BUILDDIR=../build/

all : binary_tree

binary_tree : binary.o binary_test.o
	$(CC) $(CFLAGS) binary.o binary_test.o -o $(BUILDDIR)binary_tree

binary.o : binary.c binary.h
	$(CC) $(CFLAGS) -c binary.c -o binary.o

binary_test.o : binary_test.c binary_test.h
	$(CC) $(CFLAGS) -c binary_test.c -o binary_test.o

clean :
	rm -rf *.o
	rm -rf $(BUILDDIR)*

rebuild : clean all
