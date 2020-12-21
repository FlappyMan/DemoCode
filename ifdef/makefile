CC=g++
CFLAGS=-Wall -O2 -g
TARGET=main
SRCS :=$(wildcard *.c)
OBJS :=$(patsubst %c,%o,$(SRCS))
all:$(TARGET)
$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
%.o:%.cpp
	$(CC) $(CFLAGS) -c $<
clean:
	rm -f *.o $(TARGET)