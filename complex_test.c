#include "complex_declars.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>


void test()
{
    Complex a = {3, 4}; 
    Complex b = {1, 2};
    Complex c = {0, 0};
    Complex d = {1, 0};
    Complex e = {0, 1};

    printf("Исходные данные a = %.2f + %.2fi\n", a.re, a.im);
    printf("Исходные данные b = %.2f + %.2fi\n", b.re, b.im);
    printf("Исходные данные c = %.2f + %.2fi\n", c.re, c.im);
    printf("Исходные данные d = %.2f + %.2fi\n", d.re, d.im);
    printf("Исходные данные e = %.2f + %.2fi\n", e.re, e.im);

    Complex sum = add(a, b);
    assert(sum.re == 4 && sum.im == 6);
    

    Complex diff = subtract(a, b);
    assert(diff.re == 2 && diff.im == 2);
    

    Complex prod1 = multiply(a, b);
    assert(prod1.re == -5 && prod1.im == 10);

    Complex prod2 = multiply(c, d);
    assert(prod2.re == 0 && prod2.im == 0);

    Complex prod3 = multiply(c, e);
    assert(prod3.re == 0 && prod3.im == 0);
    

    Complex quot1 = divide(a, b);
    assert(quot1.re == 2.2 && quot1.im == -0.4);

    Complex quot2 = divide(c, d);
    assert(quot2.re == 0 && quot2.im == 0);

    Complex quot3 = divide(c, e);
    assert(quot3.re == 0 && quot3.im == 0);
    

    double radius1, angle1;
    toPolar(a, &radius1, &angle1);
    assert(fabs(radius1 - 5) < 0.01);
    assert(fabs(angle1 - atan2(4, 3)) < 0.01);
    
    double radius2, angle2;
    toPolar(b, &radius2, &angle2);
    assert(fabs(radius2 - 2.236) < 0.01);
    assert(fabs(angle2 - atan2(2, 1)) < 0.01);

    double radius3, angle3;
    toPolar(c, &radius3, &angle3);
    assert(fabs(radius3 - 0) < 0.01);
    assert(fabs(angle3 - 0) < 0.01);

    double radius4, angle4;
    toPolar(d, &radius4, &angle4);
    assert(fabs(radius4 - 1) < 0.01);
    assert(fabs(angle4 - 0) < 0.01);

    double radius5, angle5;
    toPolar(e, &radius5, &angle5);
    assert(fabs(radius5 - 1) < 0.01);
    assert(fabs(angle5 - 1.57) < 0.01);

    double mod1 = abs(a);
    assert(mod1 == 5);

    double mod2 = abs(b);
    assert(fabs(mod2 - 2.236) < 0.01);

    double mod3 = abs(c);
    assert(mod3 == 0);

    double mod4 = abs(d);
    assert(mod4 == 1);  

    double mod5 = abs(e);
    assert(mod5 == 1);    
   

    Complex conj1 = conjugate(a);
    assert(conj1.re == 3 && conj1.im == -4);

    Complex conj2 = conjugate(b);
    assert(conj2.re == 1 && conj2.im == -2);

    Complex conj3 = conjugate(c);
    assert(conj3.re == 0 && conj3.im == 0);

    Complex conj4 = conjugate(d);
    assert(conj4.re == 1 && conj4.im == 0);

    Complex conj5 = conjugate(e);
    assert(conj5.re == 0 && conj5.im == -1);
    
    double exponent1 = 2; 
    Complex result1 = power(a, exponent1);
    assert(fabs(result1.re - (-7)) < 0.01);
    assert(fabs(result1.im - 24) < 0.01);

    double exponent2 = 0; 
    Complex result2 = power(b, exponent2);
    assert(fabs(result2.re - 1) < 0.01);
    assert(fabs(result2.im - 0) < 0.01);

    // Complex comp_exponent1 = {2, 3};  
    // Complex complex_pow1 = complex_power(a, comp_exponent1);
    // assert(fabs(complex_pow1.re - 1.48) < 0.01);
    // assert(fabs(complex_pow1.im - (-0.43)) < 0.01);

    // Complex comp_exponent2 = {0, 0};
    // Complex complex_pow2 = complex_power(b, comp_exponent2);
    // assert(fabs(complex_pow2.re - 1) < 0.01);
    // assert(fabs(complex_pow2.im - 0) < 0.01);

    // Complex comp_exponent3 = {0, 1};
    // Complex complex_pow3 = complex_power(e, comp_exponent3);
    // assert(fabs(complex_pow3.re - 0) < 0.01);
    // assert(fabs(complex_pow3.im - 0.2) < 0.01);

}

int main()
{
    test();
    printf("Все тесты прошли успешно! \n");
    return 0;
}
