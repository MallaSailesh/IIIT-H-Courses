#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int compare(const void * p1 , const void * p2 )
{
    const int * a1 = p1;
    const int * a2 = p2 ;
    return *a1 - *a2;
}
int main()
{
    int t;scanf("%d",&t);
    for(int test = 0;test<t;test++)
    {
        int n;scanf("%d",&n);
        int a1[n][n], arr[n],arr2[n],index[n];
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
                scanf("%d",&a1[i][j]);
            qsort(a1[i],n,sizeof(int),compare);
        }  
        if(n==1)
        {
            printf("%d ",a1[0][0]);
            continue;
        }
        
        for(int i=0;i<n;++i)
        index[i] = 0;

        for(int i=0;i<n;++i)
        {
            int sum = INT_MAX,ind, c =0;
            for(int j=0;j<n;++j)
            {
                int temp ;
                temp = a1[0][j]+a1[1][index[j]];
                if(temp < sum){
                    sum = temp ;
                    ind = j;
                }
                if(index[j]==0) c=1;
                if(index[j]==0 && c == 1) break;
            }
            index[ind]++;
            arr[i] = sum;
        }
        for(int l=0;l<n;++l) index[l] = 0;
        for(int i=2;i<n;++i)
        {
            for(int j=0;j<n;++j){ 
                int sum = INT_MAX,ind,c=0;
                for(int k=0;k<n;++k){
                    int temp ;
                    temp = arr[k]+a1[i][index[k]];
                    if(temp < sum){
                        sum = temp ;
                        ind = k;
                    }   
                    if(index[k]==0) c=1;
                    if(index[k]==0 && c == 1) break;   
                }
                index[ind]++;
                arr2[j] = sum;
            }
            for(int l=0;l<n;++l) {
                arr[l] = arr2[l];
                index[l] = 0;
            }
        }
        for(int i=0;i<n;++i){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}