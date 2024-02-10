#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
#define int long long 
#define endl "\n"
int dfs(vector<bool> &visited,int source,unordered_map<int,vector<int>> &umap,int req)
{
    visited[source] = true ;
    for(auto x : umap[source])
    {
        if(x == req) return 1;
        else if(visited[x] ==false) {
            if(dfs(visited,x,umap,req))
            return 1;
        }
    }
    return 0;
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;cin>>n>>m;
    unordered_map<int,vector<int>> adj[m];
    for(int i=0;i<m;++i)
    {
        int a ,b,c ;cin>>a>>b>>c;
        adj[c-1][a].push_back(b);
        adj[c-1][b].push_back(a);
    }
    int cnt1 = 0;
    for(int i=0;i<m;++i)
    {
        for(auto x : adj[i]){
            cnt1++;
            break;
        }
    }
    // for(int i=0;i<m;++i)
    // {
    //     for(auto x : adj[i]){
    //         cout<<x.first<<" == ";
    //         for(int i=0;i<x.second.size();++i)
    //         cout<<x.second[i]<<" ";
    //         cout<<endl;
    //     }
    //     cout<<endl<<endl;
    // }
    int q ; cin>>q;
    for(int i=0;i<q;++i){
        int u,v;cin>>u>>v;
        int cnt = 0;
        for(int i=0;i<cnt1;i++){
            vector<bool> visited(n,false) ;
            for(auto x : adj[i]){
                if(x.first == u)
                cnt += dfs(visited,u,adj[i],v);
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
// 7 7 
// 1 2 1
// 1 7 2
// 2 3 1
// 2 4 3
// 2 5 3 
// 2 7 2
// 3 5 3
// 4
// 1 2 
// 3 4
// 1 4
//2 6