#!/usr/bin/make

CC=gcc
CFLAGS=-Wall -g

.PHONY:
all: build

.PHONY:
build: bin bin/main.o

bin:
	mkdir -p bin

bin/main.o: src/main.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY:
clean:
	rm -rf bin

