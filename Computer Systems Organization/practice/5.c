#include<stdio.h>
typedef long long ll;
extern ll factorial(ll n);
int main()
{
    ll n;scanf("%lld",&n);
    printf("%lld\n",factorial(n));
    return 0;
}