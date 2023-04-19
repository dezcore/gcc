all: main
	./main
clean:
	rm -f main *.o

main: main.o list.o
	gcc -o main main.o list.o

main.o: main.c list.h
	gcc -c -Wall -g main.c

list.o : list.c list.h
	gcc -c -Wall -g list.c