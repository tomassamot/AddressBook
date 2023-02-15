CPPFLAGS:= -Wall -Werror -fPIC
CFLAGS:= -shared
LDFLAGS:=

BIN:=liblinkedlist.so
SRCS:=$(wildcard *.c)
OBJS:=$(SRCS:.c=.o)

.PHONY: all clean
all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)
clean:
	$(RM) $(BIN) $(OBJS)
