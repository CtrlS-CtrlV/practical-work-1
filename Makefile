# Makefile система збирання для проекту з кількома файлами
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

TARGET = project
SRCS = main.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

run: all
	./$(TARGET)

.PHONY: all clean run
