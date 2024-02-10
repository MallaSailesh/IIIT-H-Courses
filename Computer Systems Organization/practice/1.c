#include<stdio.h>
typedef long long ll;
extern ll solve(ll m,ll n,ll s);
int main()
{
    ll m,n,s;
    scanf("%lld %lld %lld",&m,&n,&s);
    printf("%lld\n",solve(m,n,s));
    return 0;
}