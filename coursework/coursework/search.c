#include "search.h"

// Последовательный поиск
int sequential_search(int *array, int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == target) {
            return i; // возвращаем индекс найденного элемента
        }
    }
    return -1; // если элемент не найден
}

// Бинарный поиск
int binary_search(int *array, int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (array[mid] == target) {
            return mid; // возвращаем индекс найденного элемента
        } else if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // если элемент не найден
}

