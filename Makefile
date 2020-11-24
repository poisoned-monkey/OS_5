CC = gcc
FLAGS = -std=c99 -w -O2 -Wextra -Werror -Wall -Wno-sign-compare -pedantic

all: run

run: libvector.so main_static.o main_dynamic.o
	$(CC) $(FLAGS) -o run-stat main_static.o -L. -lvector -Wl,-rpath,. 
	$(CC) $(FLAGS) -o run-dyn main_dynamic.o -ldl

main_static.o: main_static.c
	$(CC) -c $(FLAGS) main_static.c

main_dynamic.o: main_dynamic.c
	$(CC) -c $(FLAGS) main_dynamic.c

libvector.so: vector.o
	$(CC) $(FLAGS) -shared -o libvector.so vector.o

vector.o: vector.c
	$(CC) -c $(FLAGS) vector.c

clean:
	rm -f *.o run-stat run-dyn *.so 