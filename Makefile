CC = gcc
CPPFLAGS = 
CFLAGS = 
LDFLAGS =
RM = rm -f

c_files := $(wildcard *.c)
o_files := $(foreach c_file,$(c_files),$(subst .c,.o,$(c_file)))

.PHONY: all
all: create
create: $(o_files)
	$(CC) -o program $(LDFLAGS) $^
$(o_files): $(c_files)
	$(CC) -c $(subst .o,.c,$@) $(CPPFLAGS) $@
.PHONY: clean
clean:
	$(RM) program $(o_files)
