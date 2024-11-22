# Define compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

# Define source and object files
SRCS = main.c src/logger.c
OBJS = main.o logger.o

# Define target executable
TARGET = untitled

# Target to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)