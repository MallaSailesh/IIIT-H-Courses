#include<stdio.h>

typedef long long ll ;

extern int c_prime(ll n);

int main()
{
    ll n;
    scanf("%lld",&n);
    int val = c_prime(n);
    if(val == 1) 
    printf("TRUE");
    else if(val == 0) 
    printf("FALSE");
    else 
    printf("-1\n");
    return 0;
}