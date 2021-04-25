CC = gcc
CFLAGS = -Wall
LDFLAGS =
OBJ = main.o model.o search.o insert.o mainUI.o
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) $(LDFLAGS)

open: ./$(EXEC)

clean:
	rm $(wildcard *.c)
	rm $(EXEC)