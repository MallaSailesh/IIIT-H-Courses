#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,k;scanf("%d %d",&n,&k);
    int a1[n],cnt = 0;
    for(int i=0;i<n;++i) scanf("%d",&a1[i]);
    for(int i=0;i<n;++i)
    {
        int ch = 1;
        for(int i=0;i<n-1;++i)
        {
            if(a1[i]>a1[i+1]) ch = 0;
        }
        if(ch) break;
        if(k < a1[i]) {
            cnt++;
            int temp = k;
            k = a1[i];
            a1[i] = temp;
        }
    }
    // printf("%d\n",ch);
    int ch = 1;
    for(int i=0;i<n-1;++i)
    {
        // printf("%d\n",a1[i]);
        if(a1[i]>a1[i+1]) ch = 0;
    }
    // printf("%d\n",ch);
    if(ch) printf("%d\n",cnt);
    else printf("-1\n");
    return 0;
}