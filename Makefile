#!/usr/bin/make

CC = gcc
CFLAGS = -Wall -pipe

.PHONY:
all: release

.PHONY:
release: CFLAGS += -O2
release: build

.PHONY:
debug: CFLAGS += -g -O0 -DDEBUG
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

