CC = gcc
CFLAGS = -Wall -I./include

SRCS = main.c src/heap.c
OBJS = $(SRCS:.c=.o)
TARGET = heap_program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
