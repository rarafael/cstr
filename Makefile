include config.mk

CC=cc
AR=ar
CFLAGS=-Wall -Wextra -std=c99 -Wpedantic -O3 -I./include/ -fPIC
DEBUGFLAGS=-ggdb
TARGET=./lib
VERSION=1
STATIC=libcstr.a
SHARED=libcstr.so.$(VERSION)

all: $(TARGET) $(TARGET)/$(STATIC) $(TARGET)/$(SHARED)

install: all
	install $(TARGET)/$(STATIC) $(LIBDIR)
	install $(TARGET)/$(SHARED) $(LIBDIR)
	cp ./include/cstr.h $(INCDIR)

uninstall:
	rm -i $(LIBDIR)/$(STATIC)
	rm -i $(LIBDIR)/$(SHARED)
	rm -i $(INCDIR)/cstr.h

$(TARGET)/$(STATIC): src/mem.o src/str.o src/utf.o
	ar rcs $(TARGET)/$(STATIC) $^

$(TARGET)/$(SHARED): src/mem.o src/str.o src/utf.o
	cc -shared $(CFLAGS) -o $@ $^

src/str.o: src/str.c
	$(CC) $(CFLAGS) -c $^ -o $@

src/mem.o: src/mem.c
	$(CC) $(CFLAGS) -c $^ -o $@

src/utf.o: src/utf.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(TARGET):
	mkdir $(TARGET)

clean:
	rm ./src/*.o
	rm ./lib/*
	rmdir ./lib
