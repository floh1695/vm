#!/usr/bin/make

CC=gcc
CFLAGS=-Wall -g

.PHONY:
all: build

.PHONY:
debug: CFLAGS+=-DDEBUG
debug: build

.PHONY:
build: bin bin/vm

bin/vm: bin/main.o bin/debug.o
	$(CC) $^ -o $@

bin:
	mkdir -p bin

bin/%.o: src/%.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY:
clean:
	rm -rf bin

