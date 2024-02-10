#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,k;scanf("%d %d",&n,&k);
    int a1[n],cnt = 0;
    for(int i=0;i<n;++i) scanf("%d",&a1[i]);
    for(int i=1;i<n;++i)
    {
        if(a1[i]<a1[i-1])
        {
            cnt++;
            if(k <= a1[i])
            {
                int j  = i-1;
                // printf("%d ",j);
                while(j-1>=0&&a1[j-1] > k)
                {
                   cnt += 1;
                   int temp = a1[j- 1];
                   a1[j-1] = a1[j];
                   a1[j] = temp;
                   j--;
                //    for(int i=0;i<n;++i) printf("%d ",a1[i]);
                }
                int temp = a1[j];
                a1[j] = k;
                k = temp;
                // for(int i=0;i<n;++i) printf("%d ",a1[i]);
                // printf("%d ",k);
            }
            else
            {
                printf("-1\n");
                return 0;
            }
        }
    }
    int ch = 1;
    for(int i=0;i<n-1;++i)
    {
        if(a1[i]>a1[i+1]) ch = 0;
    }
    if(!ch) printf("-1\n");
    else printf("%d\n",cnt);
    return 0;
}