#include<stdio.h>
typedef long long ll;
extern ll gcd(ll n,ll m);
int main()
{
    ll n,m;
    scanf("%lld %lld",&n,&m);
    printf("%lld\n",gcd(n,m));
    return 0;
}