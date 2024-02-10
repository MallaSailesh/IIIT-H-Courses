#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 

int cnt = 0;
void dfs(int n,vector<bool> &visited,vector<int> adj[],int source)
{
    cnt++;
    visited[source] = true ;
    for(auto x : adj[source])
    {
        if(visited[x]==false)
        dfs(n,visited,adj,x);
    }
    
} 
int32_t main()
{
    int n,m;cin>>n>>m;
    vector<int> adj[n],adj2[n];
    for(int i=0;i<m;++i)
    {
        int u,v;cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj2[v-1].push_back(u-1);
    }
    vector<bool> visited(n,false);
    // vector<bool> dfsvisited(n,false);
    // for(int i=0;i<n;++i)
    // {
    //     cout<<in[i]<<" "<<out[i]<<endl;
    // }
    // int check = 0;
    // for(int i=1;i<n;++i){
    //     if(in[i]>0&&out[i]>0&&in[i]==out[i]) check++;
    // }
    // int check2 = 1;
    // dfs(n,visited,adj,0);
    // for(int i=0;i<n;++i)
    // {
    //     if(visited[i]==false) check2 = 0;
    // }
    // if(check == n&&check2) cout<<"YES\n";
    dfs(n,visited,adj,0);
    if(cnt!=n) {
        cout<<"NO\n";
        return 0;
    }
    cnt = 0;
    vector<bool> visited2(n,false);
    dfs(n,visited2,adj2,0);
    if(cnt!=n)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    return 0;
}
// 10 10
// 1 2
// 2 3
// 3 4
// 4 5
// 5 6 
// 6 7
// 7 8
// 8 9
// 9 10
// 10 1