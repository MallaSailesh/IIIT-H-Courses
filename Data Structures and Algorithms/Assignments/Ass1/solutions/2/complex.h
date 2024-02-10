#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct complex * Complex;

struct complex{
     int n;
     double * a;
};
Complex create(Complex c1,int n);
Complex add(Complex c1,Complex c2);
Complex sub(Complex c1,Complex c2);
float mod(Complex c1);
float dot(Complex c1,Complex c2);
float COS(Complex c1,Complex c2);
#endif