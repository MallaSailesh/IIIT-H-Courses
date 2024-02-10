#include<stdio.h>
// typedef long long ll ;
extern long long sum_of_square(long long n);
int main()
{
    long long  n;
    scanf("%lld",&n);
    printf("%lld\n",sum_of_square(n));
}