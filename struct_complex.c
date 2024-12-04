#include <stdio.h>
#include <math.h>
#include <assert.h>

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
    if (denominator == 0) {
        printf("Ошибка: Деление на ноль.\n");
        result.re = result.im = 0;
        return result;
    }
    result.re = (a.re * b.re + a.im * b.im) / denominator;
    result.im = (a.im * b.re - a.re * b.im) / denominator;
    return result;
}


void toPolar(Complex c, double* radius, double* angle) 
{
    *radius = sqrt(c.re * c.re + c.im * c.im);
    *angle = atan2(c.im, c.re); 
}


double modul(Complex c) 
{
    return sqrt(c.re * c.re + c.im * c.im);
}


Complex conjugate(Complex c) 
{
    Complex result;
    result.re = c.re;
    result.im = -c.im; 
    return result;
}

Complex power(Complex c, double n) {
    
    double radius = sqrt(c.re * c.re + c.im * c.im);
    double angle = atan2(c.im, c.re); 
    
    double newRadius = pow(radius, n);  
    double newAngle = angle * n;
  
    Complex result;
    result.re = newRadius * cos(newAngle);
    result.im = newRadius * sin(newAngle);
    return result;
}


void test() 
{
    Complex a = {3, 4}; 
    Complex b = {1, 2};

    printf("Исходные данные a = %.2f + %.2fi, b = %.2f + %.2fi\n", a.re, a.im, b.re, b.im);

    Complex sum = add(a, b);
    assert(sum.re == 4 && sum.im == 6);
    

    Complex diff = subtract(a, b);
    assert(diff.re == 2 && diff.im == 2);
    

    Complex prod = multiply(a, b);
    assert(prod.re == -5 && prod.im == 10);
    

    Complex quot = divide(a, b);
    assert(quot.re == 2.2 && quot.im == -0.4);
    

    double radius, angle;
    toPolar(a, &radius, &angle);
    assert(fabs(radius - 5) < 0.01);
    assert(fabs(angle - atan2(4, 3)) < 0.01);
    

    double mod = modul(a);
    assert(mod == 5);
    

    Complex conj = conjugate(a);
    assert(conj.re == 3 && conj.im == -4);
    
    
    double exponent = 2; 
    Complex result = power(a, exponent);
    assert(fabs(result.re - (-7)) < 0.01);
    assert(fabs(result.im - 24) < 0.01);
    
}

int main()
{
    test();
    printf("Все тесты прошли успешно! \n");
    return 0;
}