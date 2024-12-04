#include <stdio.h>

int main() {
    int A[10] = {3, 7, 2, 8, 5, 9, 1, 4, 6, 10}; 
    int s = 0;  //максимальное значение
    int i; 
    
    for (i = 0; i < 10; i++) {     //
        if (A[i] > s) {            //
            s = A[i];             //
        }
    }

    printf("Максимальное значение элемента в массиве A: %d\n", s);

    return 0;
}
