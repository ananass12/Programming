/*Проходим по всем элементам массива A. Если текущий элемент не делится нацело на v, то
уменьшаем значение v на 1 и сбрасываем переменную i до -1, чтобы начать цикл заново 
и проверить все элементы массива ещё раз при новом значении v.*/

#include <stdio.h>

int main() {
    int A[] = {3, 6, 9, 12, 15};
    int n = sizeof(A) / sizeof(A[0]);
    int v = 2;
    
    for (int i = 0; i < n; i++) {     //
        if (A[i] % v != 0) {          //
            v--;
            i = -1;
        }
    }

    
    printf("v = %d\n", v);
    
    return 0;
}

