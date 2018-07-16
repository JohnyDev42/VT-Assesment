LDADD=./lib

all:main.o liballoc.a
	gcc  -L$(LDADD)  src/main.o -lalloc -o bin/malloc

main.o:
	make -C src/
liballoc.a:
	make -C lib/

clean:
	rm -f lib/*.o lib/*.so src/*.o 
