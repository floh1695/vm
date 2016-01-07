#!/usr/bin/make

CC=gcc
CFLAGS=-Wall -g

.PHONY:
all: bin build

.PHONY:
build: bin/vm

bin/vm: bin/main.o
	$(CC) $^ -o $@

bin:
	mkdir -p bin

bin/main.o: src/main.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY:
clean:
	rm -rf bin

