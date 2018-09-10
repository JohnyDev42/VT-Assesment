all:liballoc.so


liballoc.so:malloc.o calloc.o
	gcc -shared -o liballoc.so malloc.o calloc.o	
	sudo cp -f liballoc.so /usr/lib
	sudo ldconfig
malloc.o:
	gcc -Wall -fPIC -c malloc.c

calloc.o:
	gcc -Wall -fPIC -c calloc.c


