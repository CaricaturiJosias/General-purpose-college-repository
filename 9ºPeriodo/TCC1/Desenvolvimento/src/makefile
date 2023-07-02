# My first makefile

all: main

main: main.o pugi.o
	gcc -o printy main.o helloWorld.o

pugi.o: pugixml.c pugiconfig.hpp pugixml.hpp
	gcc -o pugixml.o pugixml.c -c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o *~ printy