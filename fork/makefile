CC=gcc
CFLAGS=-Wall -O2 -g
TARGET=demo
SRCS :=$(wildcard *.c)
OBJS :=$(patsubst %c,%o,$(SRCS))
all:$(TARGET)
$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
%.o:%.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm -f *.o $(TARGET)
