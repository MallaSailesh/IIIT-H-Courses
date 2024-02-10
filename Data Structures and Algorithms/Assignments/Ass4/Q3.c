#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef long long ll;
ll arr[1000000][2];
int cmp(const void * x , const void * y){
     const int * a =  x ;
     const int * b = y;
     if(arr[*a][0] < arr[*b][0] ) return -1;
     else if(arr[*a][0] == arr[*b][0]) return 0;
     else return 1;
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    ll a1[n];
    for(int i=0;i<n;++i) scanf("%lld",&a1[i]);
    ll sum=0;
    int b1[n-1];
    for(int i=0;i<n-1;++i)
    {
        sum += a1[i];
        arr[i][0] = sum;
        arr[i][1] = i;
        b1[i] = i;
    }
    if(k==1)
    {
        printf("%lld\n",sum+a1[n-1]);
        return 0;
    }
    qsort(b1,n-1,sizeof(int),cmp);
    
    ll sum1 = 0;
    sum1 += (arr[b1[0]][0]);
    
    for(int i=1;i<k-1;++i)
        sum1 += (i+1)*(arr[b1[i]][0] - arr[b1[i-1]][0]);
    
    sum1 += (k)*(sum + a1[n-1] - arr[b1[k-2]][0]);
    printf("%lld\n",sum1);
    
    return 0;
}