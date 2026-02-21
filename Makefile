CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = cmdfreq
SRC = src/main.c src/history.c
OBJ = src/main.o src/history.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

src/main.o: src/main.c src/history.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/history.o: src/history.c src/history.h
	$(CC) $(CFLAGS) -c src/history.c -o src/history.o

clean:
	rm -f src/*.o $(TARGET)
