#include<stdio.h>
typedef long long ll;
extern ll sum(ll n ,ll k);
int main()
{
    ll n,k;scanf("%lld %lld",&n,&k);
    printf("%lld\n",sum(n,k));
}