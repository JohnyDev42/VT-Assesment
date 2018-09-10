all:alloc.a


alloc.a:malloc.o calloc.o
	ar rs liballoc.a malloc.o calloc.o
malloc.o:
	gcc -fPIC -c malloc.c

calloc.o:
	gcc -fPIC -c calloc.c


