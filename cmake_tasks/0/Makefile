# Имя компилятора
CC = gcc

# Флаги компилятора
CFLAGS = -Wall -Wextra -std=c99

# Список исходных файлов
SRC = pipes.c read_pipe.c write_pipe.c

# Список объектных файлов
OBJ = $(SRC:.c=.o)

# Имя исполняемого файла
TARGET = my_program

# Правило сборки всех объектных файлов и связывания их в исполняемый файл
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Правило компиляции каждого .c файла в .o файл
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Правило для очистки сгенерированных файлов
.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET)
