CC=gcc
INCDIRS=-I./src
CFLAGS=-Wall -Wextra -pedantic -g $(INCDIRS)

CFILES=$(wildcard src/*.c)
OBJECTS=main.o dll.o

BINARY=bin

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

%.o:src/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(BINARY) $(OBJECTS)

.PHONY: all clean
