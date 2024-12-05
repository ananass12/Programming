#include <stdio.h>
#include <stdlib.h>
#include "search.h"

int main(int argc, char *argv[]) {  
    if (argc != 2) {    //проверяем количество аргументов командной строки
        printf("Использование: %s <имя_файла>\n", argv[0]);
        return 1;
    }    

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return 2;
    }

    int size;       //считываем размер массива из файла
    if (fscanf(file, "%d", &size) != 1) {
        printf("Ошибка чтения размера массива из файла\n");
        fclose(file);
        return 3;
    }

    int *array = (int *)malloc(size * sizeof(int));      //выделяем память под массив
    if (array == NULL) {
        printf("Ошибка выделения памяти для массива\n");
        fclose(file);
        return 4;
    }

    for (int i = 0; i < size; ++i) {      //считываем элементы массива из файла
        if (fscanf(file, "%d", &array[i]) != 1) {
            printf("Ошибка чтения элемента массива из файла\n");
            fclose(file);
            free(array);
            return 5;
        }
    }

    fclose(file);

    int target;
    printf("Введите целевое значение для поиска: ");      //запрашиваем целевое значение у пользователя
    if (scanf("%d", &target) != 1) {
        printf("Ошибка ввода целевого значения\n");
        free(array);
        return 6;
    }

    int result_sequential = sequential_search(array, size, target);   //последовательный поиск
    int result_binary = binary_search(array, size, target);   //бинарный поиска

    if (result_sequential != -1) {       //результаты последовательного поиска
        printf("Последовательный поиск: элемент %d найден на позиции %d\n", target, result_sequential);
    } else {
        printf("Последовательный поиск: элемент %d не найден\n", target);
    }

    if (result_binary != -1) {      //результаты бинарного поиска
        printf("Бинарный поиск: элемент %d найден на позиции %d\n", target, result_binary);
    } else {
        printf("Бинарный поиск: элемент %d не найден\n", target);
    }

    free(array);

    return 0;
}
