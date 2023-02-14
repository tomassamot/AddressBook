CC = gcc
CPPFLAGS = 
CFLAGS = 

LDFLAGS=

empty=
c_files := $(wildcard *.c)
o_files := $(foreach c_file,$(c_files),$(subst .c,.o,$(c_file)))



all: build_exe
build_exe: build_o_files $(o_files)
	$(CC) -o program $(LDFLAGS) $(foreach o_file,$(o_files),$(o_file) )
build_o_files: $(c_files)
	$(foreach c_file,$(c_files), $(CC) -c $(CPPFLAGS) $(c_file) -o $(subst .c,.o,$(c_file);))
clean:
	rm -f program $(foreach file,$(c_files), $(subst .c,.o,$(file)))
