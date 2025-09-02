# Makefile for the writer application

# Define the source files
SRCS = writer.c

# Define the output executable name
TARGET = writer

# Default compiler. This will be overridden if CROSS_COMPILE is set.
CC = gcc

# Default CFLAGS. Add more as needed.
CFLAGS = -Wall -Wextra

# Conditional compilation for cross-compilation
# If CROSS_COMPILE is set, use it as the compiler prefix
ifdef CROSS_COMPILE
    CC = $(CROSS_COMPILE)gcc
endif

# Default target: builds the writer application
.PHONY: all
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(SRCS:.c=.o)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target: removes the writer application and all .o files
.PHONY: clean
clean:
	rm -f $(TARGET) $(SRCS:.c=.o)