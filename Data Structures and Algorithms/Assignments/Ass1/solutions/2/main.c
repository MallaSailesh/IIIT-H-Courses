#include "complex.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
    int n;
    char a[150];
    while(1)
    {
       scanf("%s %d",a,&n);
       if(strcmp(a,"MOD")==0)
       {
           double val =0;
           Complex c3;
           c3 = (Complex)malloc(sizeof(struct complex));
           c3->n = n;
           c3->a=(double *)malloc(sizeof(double)*n);
           for(int i=0;i<n;++i)
           {
               scanf("%lf",&c3->a[i]);
           }
           val = mod(c3);
           printf("%.2lf",val);
           continue;
       }
       else
       {
           Complex c1;
           c1 = (Complex)malloc(sizeof(struct complex));
           c1->n = n;
           c1->a=(double *)malloc(sizeof(double)*n);
           for(int i=0;i<n;++i)
           {
               scanf("%lf",&c1->a[i]);
           }
           Complex c2;
           c2 = (Complex)malloc(sizeof(struct complex));
           c2->n = n;
           c2->a=(double *)malloc(sizeof(double)*n);
           for(int i=0;i<n;++i)
           {
               scanf("%lf",&c2->a[i]);
           }
           if(strcmp(a,"ADD")==0)
           {
              Complex c = add(c1,c2);
              for(int i=0;i<n;++i)
              {
                  printf("%.2lf ",c->a[i]);
              }
           }
           else if(strcmp(a,"SUB")==0)
           {
              Complex c = sub(c1,c2);
              for(int i=0;i<n;++i)
              {
                  printf("%.2lf ",c->a[i]);
              }
           }
           else if(strcmp(a,"DOT")==0)
           {
              float n = dot(c1,c2);
              printf("%.2lf\n",n);
           }
           else if(strcmp(a,"COS")==0)
           {
              float n = COS(c1,c2);
              printf("%.2lf\n",n);
           }
           else 
           printf("Invalid Commmand\n");
        }
    }
    return 0;
}