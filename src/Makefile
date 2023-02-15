CPPFLAGS:= -Wall
CFLAGS:= -L../lib
LDFLAGS:= -llinkedlist

BIN:=main
SRCS:=$(wildcard *.c)
OBJS:=$(SRCS:.c=.o)

.PHONY: all clean
all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)
clean:
	$(RM) $(BIN) $(OBJS)
