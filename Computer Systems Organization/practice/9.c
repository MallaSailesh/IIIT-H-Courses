#include<stdio.h>
typedef long long ll;
extern ll special(ll n,ll a[]);
//{
    // ll sum = 0;
    // a[0] = 1;
    // a[1] = 1;
    // int i = 1;
    // while(i<10){
    //     i++;
    //     a[i] = i*a[i-1];
    // }
    // while(n!=0)
    // {
    //    sum += a[n%10];
    //    n = n/10;
    // }
    // if(sum == n)
    // return 1 ;
    // return 0;
//}
int main(){
    ll n ; scanf("%lld",&n);
    ll a[11];
    // special(n,a);
    // for(int i=0;i<10;++i){
    //     printf("%lld ",a[i]);
    // }
    if(special(n,a))
    printf("True");
    else 
    printf("False");
}