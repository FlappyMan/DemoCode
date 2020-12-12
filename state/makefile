CC=g++
CFLAGS=-Wall -O2 -g
TARGET=stateModule
SRCS :=$(wildcard *.cpp)
OBJS :=$(patsubst %cpp,%o,$(SRCS))
all:$(TARGET)
$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
%.o:%.cpp
	$(CC) $(CFLAGS) -c $<
clean:
	rm -f *.o $(TARGET)