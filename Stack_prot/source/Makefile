CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic
BUILDDIR=../build/

all : stack

stack : stack.o stack_test.o
	$(CC) $(CFLAGS) stack.o stack_test.o -o $(BUILDDIR)stack

stack.o : stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c -o stack.o

stack_test.o : stack_test.c stack_test.h
	$(CC) $(CFLAGS) -c stack_test.c -o stack_test.o

clean :
	rm -rf *.o
	rm -rf $(BUILDDIR)*

rebuild : clean all