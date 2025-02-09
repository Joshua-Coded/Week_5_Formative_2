CC = gcc
CFLAGS = -Wall -Wextra -I./include
TARGET = contact_tracer
SRC_DIR = src
SRCS = main.c $(SRC_DIR)/contact_trace.c
OBJS = $(SRCS:.c=.o)
HEADERS = include/contact_trace.h

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
