CPPFLAGS:=
CFLAGS:= -Wall -Werror -fPIC
LDFLAGS:= -shared

BIN:=liblinkedlist.so
SRCS:=$(wildcard *.c)
OBJS:=$(SRCS:.c=.o)

.PHONY: all clean
all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)
	
clean:
	$(RM) $(BIN) $(OBJS)
