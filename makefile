all: rando.o
	gcc -o hello rando.o

rando.o: rand.c
	gcc -c rand.c

run:
	./hello

clear:
	rm *.o
