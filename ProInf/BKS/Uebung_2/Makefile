$ LANG = C
$ CC = gcc
$ CFLAGS= -std=c11 -Wall -Wextra -pedantic

programName := ./bc

srcPath := $(programName).c
outPath := $(programName)

.PHONY: all build run clean

all: build

clean:
	@rm $(programName)

build: $(srcPath)
	@$(CC) $(CFLAGS) $(srcPath) -o $(outPath)

run: build
	@$(outPath)
