CC = gcc
CPPFLAGS ?=
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic
TARGET = prog
OBJ = main.o temp_functions.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c temp_functions.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c main.c

temp_functions.o: temp_functions.c temp_functions.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c temp_functions.c

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
