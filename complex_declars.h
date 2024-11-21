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
void toPolar(Complex z, double *radius, double *angle);
Complex power(Complex z, int n);
double modulus(Complex z);
Complex conjugate(Complex z);
void printComplex(Complex z);
