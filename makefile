all: rand.o
	gcc -o hello rand.o

rand.o: rand.c
	gcc -c rand.c

run:
	./hello

clear:
	rm *.o
