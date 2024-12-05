CC=gcc
CFLAGS=-Wall -Werror
LDFLAGS=-L.
LIBS=-lsearch

all: libsearch.so main

libsearch.so: search.o
	$(CC) -shared -o $@ $<

main: main.o
	$(CC) -o $@ $< $(LDFLAGS) $(LIBS)

%.o: %.c
	$(CC) -c $(CFLAGS) -fpic -o $@ $<

clean:
	rm -f *.o *.so main
