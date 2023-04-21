CC=cc
AR=ar
CFLAGS=-Wall -Wextra -std=c89 -Wpedantic -O3 -I./include/ -fPIC
DEBUGFLAGS=-ggdb
LIBDIR=./lib
STATIC=$(LIBDIR)/cstr.a
SHARED=$(LIBDIR)/cstr.so

all: $(LIBDIR) $(STATIC) $(SHARED)

$(STATIC): src/mem.o src/str.o src/utf.o
	ar rcs $(STATIC) $^

$(SHARED): src/mem.o src/str.o src/utf.o
	cc -shared $(CFLAGS) -o $@ $^

src/str.o: src/str.c
	$(CC) $(CFLAGS) -c $^ -o $@

src/mem.o: src/mem.c
	$(CC) $(CFLAGS) -c $^ -o $@

src/utf.o: src/utf.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBDIR):
	mkdir $(LIBDIR)

clean:
	rm ./src/*.o
	rm ./lib/*
	rmdir ./lib
