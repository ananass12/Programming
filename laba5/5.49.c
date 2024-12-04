//Код вычисляет 2^(n+1)
#include <stdio.h> 

int main() {
    int s, i, n;
    n = 6; 
    
    for (s = 1, i = 0; i <= n; i++) {     //
        s = s * 2;                        //
    }

    printf("Результат: %d\n", s); //

    return 0;
}
