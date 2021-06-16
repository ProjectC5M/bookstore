CC = gcc
CFLAGS = -Wall
LDFLAGS = 
OBJ = main.o model.o search.o insert.o mainUI.o readWriteFiles.o print.o deleteBook.o
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) $(LDFLAGS)


clean:
	del *.o

open: $(EXEC) clean
	$(EXEC).exe

cleanTxt:
	del *.txt