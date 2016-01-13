#!/usr/bin/make

CC = gcc
CFLAGS = -Wall -pipe

.PHONY: all
all: debug

.PHONY: release
release: CFLAGS += -O2 -DDEBUG=LL_WARN -DLOG_FILE=\"log.txt\"
release: .release.lck build 

.PHONY: debug
debug: CFLAGS += -g -O0 -DDEBUG=LL_DEBUG
debug: .debug.lck build

.PHONY: build
build: bin bin/vm

.%.lck:
	$(MAKE) clean
	touch $@

bin/vm: bin/main.o \
		bin/debug.o \
		bin/machine.o \
		bin/memory.o \
		bin/segment.o \
		bin/mmu.o
	$(CC) $^ -o $@

bin:
	mkdir -p bin

bin/%.o: src/%.c
	$(CC) -c $(CFLAGS) $< -o $@

src/%.c: src/%.h
	@touch $@

.PHONY: clean
clean:
	rm -rf bin
	rm -rf log.txt
	rm -rf .*.lck

