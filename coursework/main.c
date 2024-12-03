#include <stdio.h>
#include <stdlib.h>
#include "search.h"

int main(int argc, char *argv[]) {
    // Проверяем количество аргументов командной строки
    if (argc != 2) {
        printf("Использование: %s <имя_файла>\n", argv[0]);
        return 1;
    }
    
    // Открываем файл для чтения
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return 2;
    }

    // Считываем размер массива из файла
    int size;
    if (fscanf(file, "%d", &size) != 1) {
        printf("Ошибка чтения размера массива из файла\n");
        fclose(file);
        return 3;
    }

    // Выделяем память под массив
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Ошибка выделения памяти для массива\n");
        fclose(file);
        return 4;
    }

    // Считываем элементы массива из файла
    for (int i = 0; i < size; ++i) {
        if (fscanf(file, "%d", &array[i]) != 1) {
            printf("Ошибка чтения элемента массива из файла\n");
            fclose(file);
            free(array);
            return 5;
        }
    }

    // Закрываем файл
    fclose(file);

    // Запрашиваем целевое значение у пользователя
    int target;
    printf("Введите целевое значение для поиска: ");
    if (scanf("%d", &target) != 1) {
        printf("Ошибка ввода целевого значения\n");
        free(array);
        return 6;
    }

    // Выполняем поиск с использованием последовательного и бинарного поиска
    int result_sequential = sequential_search(array, size, target);
    int result_binary = binary_search(array, size, target);

    // Выводим результаты последовательного поиска
    if (result_sequential != -1) {
        printf("Последовательный поиск: элемент %d найден на позиции %d\n", target, result_sequential);
    } else {
        printf("Последовательный поиск: элемент %d не найден\n", target);
    }

    // Выводим результаты бинарного поиска
    if (result_binary != -1) {
        printf("Бинарный поиск: элемент %d найден на позиции %d\n", target, result_binary);
    } else {
        printf("Бинарный поиск: элемент %d не найден\n", target);
    }

    // Освобождаем выделенную память
    free(array);

    return 0;
}
