#include <stdio.h>
#include "complex_declars.h"
#include <math.h>
#include <assert.h>





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

double abs(Complex z) 
{
    return sqrt(z.re * z.re + z.im * z.im);
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


void toPolar(Complex z, double* radius, double* angle) 
{
    *radius = abs(z);
    *angle = atan2(z.im, z.re); 
}

Complex conjugate(Complex z) 
{
    Complex result;
    result.re = z.re;
    result.im = -z.im; 
    return result;
}

Complex power(Complex z, double n) {
    
    *radius = abs(z);
    *angle = atan2(z.im, z.re); 
    
    double newRadius = pow(radius, n);  
    double newAngle = angle * n;
  
    Complex result;
    result.re = newRadius * cos(newAngle);
    result.im = newRadius * sin(newAngle);
    return result;
}


// Complex complex_power(Complex z, Complex exponent) {
//     Complex compow_res;
    
//     double radius, angle;
//     toPolar(z, &radius, &angle);
   
//     double a = exponent.re;             
//     double b = exponent.im;             

//     double newRadius = pow(radius, a) * exp(-b * angle); 
//     double newAngle = a * log(radius) + b * angle;        

//     compow_res.re = newRadius * cos(newAngle);   
//     compow_res.im = newRadius * sin(newAngle);   

//     return compow_res;
// }



