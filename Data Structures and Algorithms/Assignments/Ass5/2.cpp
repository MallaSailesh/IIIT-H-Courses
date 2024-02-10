#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
#define int long long 
#define endl "\n"

int arr[50001][1001]={0};
int sum;

void dfs(vector<bool> &visited,vector<int> adj[],int source,int target)
{
    arr[source][0]  = 1;
    visited[source] = true ;
    
    for(auto x : adj[source])
    {
        if(visited[x]==false)
        {
            dfs(visited,adj,x,target); 

            for(int i=0;i<target;++i)
            {
                sum += arr[source][target-i-1]*arr[x][i];
                // cout<<sum<<" a"<<endl;
            }
            for(int i=1;i<=target;++i)
            {
                arr[source][i] += arr[x][i-1];
            }
        }
    }
    return ;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> adj[n+1];
        for(int i=0;i<n-1;++i){
            int u,v;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(n<k){
             cout<<"0\n";
             continue ;
        }
        sum  = 0;    
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<k;++j)
            arr[i][j] = 0;
        }   
        // for(int i=1;i<=n;++i){
        //     cout<<i<<"==>"<<" ";
        //     for(auto x : adj[i])
        //     cout<<x<<" ";
        //     cout<<endl;
        // }
        vector<bool> visited(n+1,false);
        dfs(visited,adj,1,k);
        if(k==0) 
        {
            cout<<n<<endl;
            continue;
        }
        cout<<sum<<endl;
    }
    return 0;
}
