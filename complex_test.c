#include "complex_declars.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>


int main() 
{
    Complex z1 = {3.0, 4.0};
    Complex z2 = {1.0, 2.0};


    Complex sum = add(z1, z2);
    printf("Сложение: ");
    printComplex(sum);


    Complex dif = subtract(z1, z2);
    printf("Вычитание: ");
    printComplex(dif);


    Complex product = multiply(z1, z2);
    printf("Умножение: ");
    printComplex(product);


    Complex quotient = divide(z1, z2);
    printf("Деление: ");
    printComplex(quotient);


    double radius, angle;
    toPolar(z1, &radius, &angle);
    printf("Полярная форма: Радиус = %f, Угол = %f рад\n", radius, angle);


    Complex powerResult = power(z1, 2);
    printf("Возведение в степень 2: ");
    printComplex(powerResult);

    double mod = modulus(z1);
    printf("Модуль: %f\n", mod);


    Complex conj = conjugate(z1);
    printf("Сопряженное число: ");
    printComplex(conj);

    return 0;
}