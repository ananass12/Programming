# Компилятор и флаги компиляции
CC=gcc
CFLAGS=-Wall -Werror
LDFLAGS=-L.
LIBS=-lsearch

# Компиляция всех целей
all: libsearch.so main

# Компиляция динамической библиотеки
libsearch.so: search.o
	$(CC) -shared -o $@ $<

# Компиляция основного исполняемого файла
main: main.o
	$(CC) -o $@ $< $(LDFLAGS) $(LIBS)

# Компиляция объектного файла из исходного кода
%.o: %.c
	$(CC) -c $(CFLAGS) -fpic -o $@ $<

# Очистка скомпилированных файлов
clean:
	rm -f *.o *.so main
