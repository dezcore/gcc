all: main
	./main
clean:
	rm main.o main

main: main.o
	gcc -o main main.o

main.o: main.c
	gcc -c -Wall main.c