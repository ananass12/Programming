#include <stdio.h>
#include <math.h>

double E = pow(10,-3); 

//вычислять факториал числа, уменьшая его на 1 с каждым рекурсивным вызовом, пока число не станет равным 0 или 1
int factorial(int a) {
    if (a == 0 || a == 1)
        return 1;
    return a * factorial(a - 1); 
}

double cosa(double x, int n) {
    // Вычисление очередного члена ряда Тейлора
    double F = pow(x, 2 * n) / factorial(2 * n);  //текущий член ряда    
    if (F < E)      // Если текущий член меньше E, возвращаем его
        return F;
    return pow(-1, n) * F + cosa(x, n + 1);  //значение ряда с учетом знака (-1)^n и суммы предыдущих членов
}

int main() {   
    printf("Введите аргумент для cos: ");
    double x;
    scanf("%lf", &x); 
    printf("%lf \n", cosa(x, 0)); 
    printf("%lf \n", cos(x)); 
}
