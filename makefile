CC = gcc
FLAG = -Wall
all: bin/rkmatcher

bin/rkmatcher: build/main.o
	$(CC) $(FLAG) build/main.o -o bin/rkmatcher
build/main.o: src/main.c
	$(CC) $(FLAG) -c src/main.c -o build/main.o
dir:
	mkdir build
	mkdir bin
clean:
	rm build/*.o


