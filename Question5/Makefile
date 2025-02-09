CC = gcc
CFLAGS = -Wall -Wextra -I./include
TARGET = path_finder
SRC_DIR = src
SRCS = main.c $(SRC_DIR)/shortest_path.c
OBJS = $(SRCS:.c=.o)
HEADERS = include/shortest_path.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
	rm -f $(SRC_DIR)/*.o

init:
	mkdir -p include src
