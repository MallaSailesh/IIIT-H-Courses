#include<stdio.h>
typedef long long ll;
extern ll binarysearch(ll a[] ,ll m,ll l,ll r);
// {
//     if(l>r) return -1;
//     ll mid = (l+r)/2 ;
//     if(a[mid]==m) return mid ;
//     else if(a[mid] > m) return binarysearch(a,m,l,mid-1);
//     else return binarysearch(a,m,mid+1,r);
// }
int main()
{
    ll n,m;
    scanf("%lld",&n);
    ll a[n];
    for(int i=0;i<n;++i) scanf("%lld",&a[i]);
    scanf("%lld",&m);
    printf("%lld\n",binarysearch(a,m,0,n-1));
    return 0;
}