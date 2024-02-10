#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
#define  int long long 
#define endl "\n"
int sum ;
int findSample(int n, vector<int> &powers, int stu[], int con[])
{
    int ans=0;
    for (int i=n-1; i>0; i--)
    {
        if (con[i]==0)
        {
            ans+=powers[i];
            powers[stu[i]] = max(powers[stu[i]]-powers[i] , ll(0));
        }
        else if (con[i]==1)
            powers[stu[i]]+=powers[i];
        else
            powers[stu[i]]=max(powers[stu[i]], powers[i]);
    }
    return ans+powers[0];
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n ; cin>>n ;
    vector<int> adj[n];
    vector<int> powers(n);
    for(int i=0;i<n;++i) cin>>powers[i];
    int stu[n],con[n];
    for(int i=1;i<n;i++)
    {
        cin>>stu[i]>>con[i];
        
    //     if(con == 0)
    //     {
    //        adj[i].push_back(stu);
    //        adj[stu].push_back(i);
    //     }
    //     else if(con == 1)
    //     {
    //        for(auto x : adj[stu])
    //        {
    //            adj[x].push_back(i);
    //            adj[i].push_back(x);
    //        }
    //     }
    //     else 
    //     {
    //        for(auto x : adj[stu])
    //        {
    //            adj[x].push_back(i);
    //            adj[i].push_back(x);
    //        }
    //        adj[stu].push_back(i);
    //        adj[i].push_back(stu);
    //     }
    }
    cout<<findSample(n,powers,stu,con)<<endl;
    // for(int i=0;i<n;++i)
    // {
    //     cout<<i<<"==>";
    //     for(auto x :adj[i])
    //     cout<<x<<" ";
    //     cout<<endl;
    // }
    return 0;
} 