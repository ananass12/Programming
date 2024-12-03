#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>

// Структура для представления прямой y = a * x + b
struct Line {
    float a; // Коэффициент a
    float b; // Коэффициент b
};

// Функции для подсчета количества прямых, параллельных осям координат
int countLinesOX(struct Line lines[], int size);
int countLinesOY(struct Line lines[], int size);

#endif // HEADER_H

