CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic
BUILDDIR=../build/
TESTFLAGS = -lcheck -g -lm -lpthread -lsubunit

all : stack start

stack : stack.o stack_test.o
	$(CC) $(CFLAGS) stack.o stack_test.o -o $(BUILDDIR)stack $(TESTFLAGS)

stack.o : stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c -o stack.o

stack_test.o : stack_test.c stack_test.h
	$(CC) $(CFLAGS) -c stack_test.c -o stack_test.o

clean :
	rm -rf *.o
	rm -rf $(BUILDDIR)*

rebuild : clean all

start :
	$(BUILDDIR)stack

style_check :
	find . -name "*.c" -o -name "*.h" | xargs clang-format -style=Google -n

style :
	find . -name "*.c" -o -name "*.h" | xargs clang-format -style=Google -i

valgrind :
	make stack && valgrind --tool=memcheck --leak-check=yes $(BUILDDIR)stack