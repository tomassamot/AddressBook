CPPFLAGS:= -I../lib
CFLAGS:= -Wall
LDFLAGS:= -L../lib -llinkedlist

BIN:=address_book
SRCS:=$(wildcard *.c)
OBJS:=$(SRCS:.c=.o)

.PHONY: all clean
all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) $(BIN) $(OBJS)
