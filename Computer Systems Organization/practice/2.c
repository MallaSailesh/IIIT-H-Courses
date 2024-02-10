#include<stdio.h>
typedef long long ll;
extern ll solve(ll n);
//    int cnt = 0;
// while(n!=0)
// {
//     if(n%2) cnt++;
//     n =  n/2 ;
// }
int main()
{
    ll n;
    scanf("%lld",&n);
    // printf("%lld\n",solve(n));
    if(solve(n)%2) printf("TRUE\n");
    else printf("FALSE\n");
    return 0;
}