#include<stdio.h>
typedef long long ll;
// #define int long long 
extern void q1(ll arr[],int n,ll arr2[]);
/* for(int i=n-1;i>=0;--i){
    while(!s.empty()&&s->top() <= arr[i])
    s.pop();
    arr2[i]  = (s.empty)?-1:s.top();
    s.push();
 } */
int main()
{
    int  n ;
    scanf("%d",&n);
    ll arr[n],arr2[n];
    for(int i=0;i<n;++i) scanf("%lld",&arr[i]);
    q1(arr,n,arr2);
    for(int i=0;i<n;++i)
    printf("%lld ",arr2[i]);
    printf("\n");
    return 0;
}