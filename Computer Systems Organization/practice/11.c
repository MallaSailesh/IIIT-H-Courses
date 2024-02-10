#include<stdio.h>
typedef long long ll;
extern void qsort(ll n,ll a[]);
// {
//     ll pivot = a[0];
//     ll i = n;
//     for(int j=n-1;j>0;j--){
//         if(a[j] > pivot)
//         {
//             i--;
//             ll temp = a[i];
//             ll temp2 = a[j];
//             a[i] = temp2;
//             a[j] = temp;
//         }
//     }
//     i--;
//     ll temp = a[i];
//     a[i] = a[0];
//     a[0] = temp;
// }
int main()
{
    ll n;
    scanf("%lld",&n);
    ll a[n];
    for(int i=0;i<n;++i) scanf("%lld",&a[i]);
    qsort(n,a);
    for(int i=0;i<n;++i) printf("%lld ",a[i]);
    return 0;
}