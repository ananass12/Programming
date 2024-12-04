#include <stdio.h>

int main() {
    int s = 0;     //подсчета количества делителей
    int a = 17;      //число, для проверки на простоту

    for (int n = 2; n < a; n++) {
        if (a % n == 0) { 
            s++; 
        }
    }

    if (s == 0) { 
        printf("Good\n"); 
    }

    return 0;
}
