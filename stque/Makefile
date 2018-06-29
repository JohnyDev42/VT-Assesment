all:1.o 2.o main.o
	gcc lib/1.o lib/2.o src/main.o -o bin/exc
main.o:
	make -C src 
1.o:
	make -C lib 
2.o:
	make -C lib
clean:
	rm lib/*.o src/*.o
 
