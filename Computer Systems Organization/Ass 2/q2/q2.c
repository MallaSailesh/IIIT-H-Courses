#include<stdio.h>
typedef long long ll;
extern ll recursion(ll n,ll change);
/*
   if(n<change||n<(-1*change)) return 0;
   else if(n==1&&change==0) return 2;
   else if(n==1&&(change==1||change==-1)) return 1;
   return 2*recursion(n-1,change) + recursion(n-1,change-1) + recursion(n-1,change+1) 
*/
int main(){
    ll n ;
    scanf("%lld",&n);
    printf("%lld\n",recursion(n,0));
}