#include<stdio.h>
#include<stdlib.h>
typedef long long ll;
ll sum ;
int compares(const void *p1 , const void *p2)
{
    const int *  a1 = p1;
    const int * a2 = p2;
    return *a1 - *a2;
}
void q4(int a1[],int left,int right,ll tsum)
{
    if(left == right)
    return ;

    sum += tsum;
    int i;
    ll sum1 = 0;
    for(i=left;i<=right;++i)
    {
       sum1 += a1[i];
       if(sum1 + a1[i+1] >= tsum/2)
       break;
    }
    if(right - left == 1 || tsum - sum1 < sum1 + a1[i+1] )
    {
        q4(a1,left,i,sum1);
        q4(a1,i+1,right,tsum - sum1);
    }
    else 
    {
        q4(a1,left,i+1,sum1+a1[i+1]);
        q4(a1,i+2,right, tsum - sum1 - a1[i+1]);
    }
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a1[k];
    for(int i=0;i<k;++i) {
        scanf("%d",&a1[i]);
    }
    qsort(a1,k,sizeof(int),compares);
    q4(a1,0,k-1,n);
    printf("%lld\n",sum);
    return 0;
}