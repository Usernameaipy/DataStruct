CC = gcc
CFLAGS = -Wall -Werror -Wextra -I -pedantic -std=c11
BUILDDIR = ../build/
TESTFLAGS = -lcheck -lm -lpthread -lsubunit -g

all : test start

test : test_queue.o queue.o
	$(CC) $(CFLAGS) test_queue.o queue.o -o $(BUILDDIR)test $(TESTFLAGS)

queue.o : queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c -o queue.o

test_queue.o : test_queue.c test_queue.h
	$(CC) $(CFLAGS) -c test_queue.c -o test_queue.o

start :
	$(BUILDDIR)test

clean :
	rm -rf $(BUILDDIR)*
	rm -rf *.o

rebuild : clean all

style_check :
	find . -name "*.c" -o -name "*.h" | xargs clang-format -style=Google -n

style :
	find . -name "*.c" -o -name "*.h" | xargs clang-format -style=Google -i

valgrind : clean
	make test && valgrind --tool=memcheck --leak-check=yes $(BUILDDIR)test