#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>

struct Line {   //структура для представления прямой y = a * x + b
    float a; 
    float b; 
};

int countLinesOX(struct Line lines[], int size);
int countLinesOY(struct Line lines[], int size);

#endif 

