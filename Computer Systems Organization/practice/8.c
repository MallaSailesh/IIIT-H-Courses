#include<stdio.h>
typedef long long ll;
extern ll matrix(ll m,ll n,ll p,ll a[m][n] ,ll b[n][p],ll c[m][p]);
// {
//      for(int i=0;i<m;++i){
//          for(int j=0;j<p;++j){
//              int sum = 0;
//              for(int k=0;k<n;++k)
//              sum += a[i][k]*b[k][j];
//              c[i][j] = sum;
//          }  
//      } 
// }
int main()
{
    ll m,n,p;
    scanf("%lld %lld %lld",&m,&n,&p);
    ll a[m][n],b[n][p],c[m][p];
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j)
        scanf("%lld",&a[i][j]);
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<p;++j)
        scanf("%lld",&b[i][j]);
    }
    matrix(m,n,p,a,b,c);
    for(int i=0;i<m;++i){
        for(int j=0;j<p;++j){
            printf("%lld ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}