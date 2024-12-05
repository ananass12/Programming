#include "header.h"

int countLinesOX(struct Line lines[], int size) {    //прямые, параллельных оси OX
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (lines[i].a == 0) {
            count++;
        }
    }
    return count;
}

int countLinesOY(struct Line lines[], int size) {   //прямые, параллельных оси OY
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (lines[i].a != 0 && lines[i].b == 0) {
            count++;
        }
    }
    return count;
}
