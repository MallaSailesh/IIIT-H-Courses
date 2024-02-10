#include<stdio.h>
typedef long long ll;
extern ll sume(ll m,ll n,ll arr[m][n]);
int main()
{
    ll m,n;
    scanf("%lld %lld",&m,&n);
    ll arr[m][n];
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j) 
        scanf("%lld",&arr[i][j]);
    }
    printf("%lld\n",sume(m,n,arr));
    return 0;
}