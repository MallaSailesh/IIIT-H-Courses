#include<stdio.h>
#include<stdlib.h>
int min(int a,int b)
{
    return (a<b)?a:b;
}
int compares(const void *p1 , const void *p2)
{
    const int * a1 = p1;
    const int * a2 = p2;
    return *a1 - *a2;
}
int comparel(const void *p1 , const void *p2)
{
    const int * a1 = p1;
    const int * a2 = p2;
    return *a2 - *a1;
}
int main()
{
    int t ;scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        int n;
        scanf("%d",&n);
        int a1[n];
        for(int i=0;i<n;++i) scanf("%d",&a1[i]);
        qsort(a1,n,sizeof(int),compares);
        int a2[n],cnt=1,cnt2=0;
        for(int i=1;i<n;++i)
        {
           if(a1[i] == a1[i-1])
           cnt++;
           else{
               a2[cnt2++] = cnt;
               cnt = 1;
           }
        }
        a2[cnt2++] = cnt;
        qsort(a2,cnt2,sizeof(int),comparel);
        if(a2[0]==1)
        printf("%d\n",n);
        else
        {
            int cnthf = 1;
            for(int i=1;i<cnt2;++i)
            {
              if(a2[i]==a2[0]) cnthf++;
              else break;
            }
            // printf("%d\n",cnthf);
            int val = (n - (cnthf)*a2[0])/(a2[0] - 1);
            printf("%d\n",(cnthf-1)+val);
        }
    }
}