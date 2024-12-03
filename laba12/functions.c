#include "header.h"

// Функция для подсчета количества прямых, параллельных оси OX
int countLinesOX(struct Line lines[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (lines[i].a == 0) {
            count++;
        }
    }
    return count;
}

// Функция для подсчета количества прямых, параллельных оси OY
int countLinesOY(struct Line lines[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (lines[i].a != 0 && lines[i].b == 0) {
            count++;
        }
    }
    return count;
}
