#pragma once
#include <stddef.h>


typedef struct Complex
{
    double re;
    double im;
} Complex;


Complex add(Complex a, Complex b);
Complex subtract(Complex a, Complex b);
Complex multiply(Complex a, Complex b);
Complex divide(Complex a, Complex b);
void toPolar(Complex c, double *radius, double *angle);
Complex power(Complex c, double n);
double abs(Complex c);
Complex conjugate(Complex c);
Complex complex_power(Complex z, Complex exponent);
