#include<stdio.h>

typedef long long ll ;

extern long long largest_prime(ll n);

int main()
{
    ll n;
    scanf("%lld",&n);
    printf("%lld\n",largest_prime(n));
    return 0;
}