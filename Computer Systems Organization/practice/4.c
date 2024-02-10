#include<stdio.h>
typedef long long ll;
extern ll sum(ll n , ll m);
extern ll prime(ll n);
int main()
{
    ll n,m;scanf("%lld %lld",&n,&m);
    printf("%lld\n",sum(n,m));
    return 0;
}