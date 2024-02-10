#include<stdio.h>
// # define int long long 
typedef  long long ll ;
extern ll bubblesort(ll a[],ll n);
    // int cnt = 0;
    // for(int i=0;i<n-1;++i){
    //     if(a[i]>a[i+1])
    //     {
    //         cnt++;
    //         int temp = a[i];
    //         int temp2 = a[i+1];
    //         a[i+1] = temp ;
    //         a[i] = temp2
    //     }
    // }
    // if(cnt > 0)
    // bubblesort(a,n-1);
int main()
{
    ll n;scanf("%lld",&n);
    ll a[n];
    for(int i=0;i<n;++i) scanf("%lld",&a[i]);
    printf("%lld",bubblesort(a,n));
    for(int i=0;i<n;++i) printf("%lld ",a[i]);
    return 0;
}