#include <stdio.h>
#include <math.h>


typedef struct Complex 
{
    double re; 
    double im; 
} Complex;


Complex add(Complex a, Complex b) 
{
    Complex result;
    result.re = a.re + b.re;
    result.im = a.im + b.im;
    return result;
}


Complex subtract(Complex a, Complex b) 
{
    Complex result;
    result.re = a.re - b.re;
    result.im = a.im - b.im;
    return result;
}


Complex multiply(Complex a, Complex b) 
{
    Complex result;
    result.re = a.re * b.re - a.im * b.im;
    result.im = a.re * b.im + a.im * b.re;
    return result;
}


Complex divide(Complex a, Complex b) 
{
    Complex result;
    double denominator = b.re * b.re + b.im * b.im;
    result.re = (a.re * b.re + a.im * b.im) / denominator;
    result.im = (a.im * b.re - a.re * b.im) / denominator;
    return result;
}


void toPolar(Complex z, double *radius, double *angle) 
{
    *radius = sqrt(z.re * z.re + z.im * z.im);
    *angle = atan2(z.im, z.re); 
}


Complex power(Complex z, int n) 
{
    Complex result = {1.0, 0.0}; 
    for (int i = 0; i < n; i++) {
        result = multiply(result, z); 
    }
    return result;
}


double modulus(Complex z) 
{
    return sqrt(z.re * z.re + z.im * z.im);
}


Complex conjugate(Complex z) 
{
    Complex result;
    result.re = z.re;
    result.im = -z.im; 
    return result;
}



void printComplex(Complex z) 
{
    printf("%f + %fi\n", z.re, z.im);
}

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