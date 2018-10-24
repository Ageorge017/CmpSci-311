# Yanling Wang Fall 2018
CC := gcc
CFLAGS := -Wall
PROGS := main mainlink

.PHONY:all

all: $(PROGS)

main: main.o list.o
	$(CC) $(CFLAGS) -o $@ main.o list.o

mainlink: main.o list.o mymalloc.c
	$(CC) $(CFLAGS) -DLINKTIME -c mymalloc.c
	$(CC) $(CFLAGS) -Wl,--wrap,malloc -Wl,--wrap,free -o mainlink main.o list.o mymalloc.o

runl:
	./mainlink

main.o: list.h
list.o: list.h

.PHONY:clean

clean:
	rm -f $(PROGS) *.o
