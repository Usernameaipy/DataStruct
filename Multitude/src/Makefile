CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c11
BUILDDIR = ../build/
TESTFLAGS = -lcheck -lm -g -lsubunit -lpthread

all : test start

test : multitude.o test_multitude.o
	$(CC) $(CFLAGS) multitude.o test_multitude.o -o $(BUILDDIR)test $(TESTFLAGS)

multitude.o : multitude.c multitude.h
	$(CC) $(CFLAGS) -c multitude.c -o multitude.o

test_multitude.o : test_multitude.c test_multitude.h
	$(CC) $(CFLAGS) -c test_multitude.c -o test_multitude.o

start :
	$(BUILDDIR)test

clean :
	rm -rf $(BUILDDIR)*
	rm -rf *.o

rebuild : clean all

style_check :
	find . -name "*.c" -o -name "*.h" | xargs clang-format style=Google -n

style :
	find . -name "*.c" -o -name "*.h" | xargs clang-format style=Google -i

valgrind :
	make test && valgrind --tool=memcheck --leak-check=yes $(BUILDDIR)test