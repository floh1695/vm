#!/usr/bin/make

CC = gcc
CFLAGS = -Wall -pipe

.PHONY:
all: debug

.PHONY:
release: CFLAGS += -O2 -DDEBUG=LL_WARN -DLOG_FILE=\"log.txt\"
release: .release.lck build 

.PHONY:
debug: CFLAGS += -g -O0 -DDEBUG=LL_DEBUG
debug: debug.lck build

.PHONY:
build: bin bin/vm

%.lck: clean
	touch $@

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
	rm -rf log.txt
	rm -rf *.lck

