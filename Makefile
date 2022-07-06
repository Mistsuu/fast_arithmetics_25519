# Settings for folders
OBJECT_DIR  = obj
LIBRARY_DIR = lib
SOURCE_DIR  = src

# Compilers options
CC          = gcc
CFLAGS      = -I$(LIBRARY_DIR) -O3 -ggdb
LIBS		= 

# Requirements and stuffs
OBJS        = main.o mul25519.o sqr25519.o inv25519.o sqrt25519.o pow25519.o add25519.o sub25519.o
DEPS        = fast_arithmetics_25519.h local_asm.h
FULLDEPS    = $(patsubst %,$(LIBRARY_DIR)/%, $(DEPS))
FULLOBJS    = $(patsubst %,$(OBJECT_DIR)/%,  $(OBJS))

$(OBJECT_DIR):
	mkdir -p $(OBJECT_DIR)

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c $(FULLDEPS) | $(OBJECT_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(FULLOBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)


# For commands
.PHONY: clean run dbg gdb
clean:
	rm -f $(OBJECT_DIR)/*.o ./main

run: main
	./main

dbg: main
	gdb-pwndbg ./main

gdb: main
	gdb ./main
