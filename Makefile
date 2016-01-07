#!/usr/bin/make

CC = gcc
CFLAGS = -Wall -pipe

.PHONY:
all: debug

.PHONY:
release: CFLAGS += -O2
release: build

.PHONY:
debug: CFLAGS += -g -O0 -DDEBUG=LL_DEBUG
debug: build

.PHONY:
build: bin bin/vm

bin/vm: bin/main.o bin/debug.o
	$(CC) $^ -o $@

bin:
	mkdir -p bin

bin/%.o: src/%.c
	$(CC) -c $(CFLAGS) $< -o $@

bin/%.c: bin/%.h

.PHONY:
clean:
	rm -rf bin

