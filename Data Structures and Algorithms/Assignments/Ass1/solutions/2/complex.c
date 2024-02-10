#include "complex.h"
#include<stdlib.h>
#include<math.h>
#include<assert.h>

Complex add(Complex c1,Complex c2)
{
    int n = c1->n;
    Complex c3;
    c3 = (Complex)malloc(sizeof(struct complex));
    assert(c3!=NULL);
    c3->a=(double *)malloc(sizeof(double)*n);
    assert(c3->a!=NULL);
    for(int i=0;i<n;++i)
    {
      c3->a[i]=c1->a[i]+c2->a[i];
    }
    return c3;
}

Complex sub(Complex c1,Complex c2)
{
    int n = c1->n;
    Complex c3;
    c3 = (Complex)malloc(sizeof(struct complex));
    assert(c3!=NULL);
    c3->a=(double *)malloc(sizeof(double)*n);
    assert(c3->a!=NULL);
    for(int i=0;i<n;++i)
    {
      c3->a[i]=c1->a[i]-c2->a[i];
    }
    return c3;
}
float mod(Complex c1)
{
   float sum = 0;
   for(int i=0;i<(c1->n);++i)
   {
      sum += (c1->a[i])*(c1->a[i]);
   }
   sum = sqrt(sum);
   return sum;
}
float dot(Complex c1,Complex c2)
{
    float val=0;
    for(int i=0;i<(c1->n);++i)
    {
        val += (c1->a[i])*(c2->a[i]);
    }
    return val;
}
float COS(Complex c1,Complex c2)
{
    float val ;
    val = dot(c1,c2)/(mod(c1)*mod(c2));
    return val;
}