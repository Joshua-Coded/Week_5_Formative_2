CC = gcc
CFLAGS = -Wall -Wextra -I./include
TARGET = mst_program
SRC_DIR = src
SRCS = main.c $(SRC_DIR)/graph.c
OBJS = $(SRCS:.c=.o)
HEADERS = include/graph.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
	rm -f $(SRC_DIR)/*.o

# Create directories if they don't exist
init:
	mkdir -p include src
