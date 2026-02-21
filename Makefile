# flags
CFLAGS = -Wall -Wextra -Werror -std=c11 -O2

TARGET = cmdfreq

# Src
SRC = main.c history.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

# Linking
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Compilation
%.o: %.c history.h
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET) ~/.bash_history

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: all clean run
