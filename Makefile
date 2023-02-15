CPPFLAGS:= 
CFLAGS:= 
LDFLAGS:=

SRCS:=$(wildcard *.c)
OBJS:=$(SRCS:.c=.o)

LIB_DIR:=./lib
SRC_DIR:=./src


.PHONY: all clean
all: launch

launch: create-lib create-src
	export LD_LIBRARY_PATH=$(LIB_DIR):$$LD_LIBRARY_PATH ; ./src/main
create-src:
	cd $(SRC_DIR) ; make
create-lib:
	cd $(LIB_DIR) ; make



clean: clean-lib clean-src

clean-src:
	cd $(SRC_DIR) ; make clean
clean-lib:
	cd $(LIB_DIR) ; make clean
