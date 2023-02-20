LIB_DIR:=./lib
SRC_DIR:=./src


.PHONY: all clean bin lib

all: library program

program: $(SRC_DIR)
	$(MAKE) -C $^

library: $(LIB_DIR)
	$(MAKE) -C $^



clean: clean-lib clean-src

clean-src:
	$(MAKE) -C $(SRC_DIR) clean

clean-lib:
	$(MAKE) -C $(LIB_DIR) clean
