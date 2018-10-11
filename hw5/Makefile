SRC := good_echo.c
OBJ := good_echo.o
ASM := good_echo.s
PROG := good_echo

CLFAGS := -Wall -O1 -fstack-protector
CC=gcc

.PHONY: all
.PHONY: clean 

all: good_echo good_echo.s

good_echo: good_echo.c
	$(CC) -Wall -Wstack-protector -O1  -fstack-protector -o $@ $<

good_echo.s: good_echo.c 
	$(CC) $(CFLAGS) -fstack-protector -S $<

good_echo.o: good_echo.c
	$(CC) $(CFLAGS) -c $<



.PHONY: clean
clean:
	rm -f good_echo.o good_echo.s good_echo
