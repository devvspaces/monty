# Makefile

CC=gcc -Wall -Werror -Wextra -pedantic -std=gnu89
TARGET=monty
CFILES=*.c
HFILES=*.h

b:
	betty $(CFILES) $(HFILES)

build:
	$(CC) $(CFILES) -o $(TARGET)

test:
	make b
	make build

clean:
	rm -f $(TARGET)