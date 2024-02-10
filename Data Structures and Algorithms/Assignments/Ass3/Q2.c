#include<stdio.h>
#include<math.h>
#include<string.h>

typedef long long ll;
ll power(ll n)
{
    ll val = 1;
    for(int i=1;i<n;++i)
    {
        val *= 2;
    }
    return val;
}
ll checklevel(ll n)
{
    ll cnt = 1;
    while(n%2==0)
    {
        n=n/2;
        cnt += 1;
    }
    return cnt;
}
ll operate(ll n)
{
    while(n%2==0)
    {
        n=n/2;
    }
    n = n/2;
    if(n%2==0)
    return 0;//add
    else return 1;//subtract
}
int main()
{
    ll n,t;
    scanf("%lld %lld",&n,&t);
    ll maxlevel = log2(n+1),level;
    for(ll i=0;i<t;++i)
    {
        ll r;
        scanf("%lld",&r);
        char dir[100000];
        scanf("%s",dir);
        level = checklevel(r);
        ll len = strlen(dir);
        for(ll i=0;i<len;++i)
        {
            if(dir[i]=='U'&&level+1<=maxlevel)
            {
            
               if(operate(r))
               r -= power(level);
               else 
               r += power(level);
               level += 1;
            }
            else if(dir[i]=='L'&&level-1>0)
            {
               r -= power(level-1);
               level -= 1;
            }
            else if(dir[i]=='R'&&level-1>0)
            {
               r += power(level-1);
               level -= 1;
            }
        }
        printf("%lld\n",r);
    }
    return 0;
}