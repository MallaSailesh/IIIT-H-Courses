#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
// #define  int long long 
#define endl "\n"

void djkistra(set<pair<int,int>> &s,int n , vector<pair<int,int>> &distance,vector<pair<int,int>> weight[])
{
    vector<int> visited(n,false);
    // for(int j = 0;j<n;j++)
    while(!s.empty())
    {
        // int u = -1;
        // for(int i=0;i<n;++i)
        // {
        //     if(!visited[i]&&(u==-1||distance[i]<distance[u]))
        //     u = i;
        // }
        int u = (*s.begin()).second;
        s.erase(*s.begin());
        // cout<<u<<endl;
        visited[u] = true ;
        for(auto x : weight[u])
        {
            if(!visited[x.first])
            {
                auto it = s.find(distance[x.first]);
                distance[x.first].first = min(distance[x.first].first,distance[u].first+x.second);
                // priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq1(distance.begin(),distance.end());
                // pq = pq1;
                s.erase(*it);
                s.insert({distance[x.first].first,distance[x.first].second});
            }
        }  
    }
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;cin>>n>>m>>k;
    vector<pair<int,int>> distance(n,{INT_MAX,0});
    for(int i=0;i<n;++i)
    distance[i] = {INT_MAX,i};
    for(int i=0;i<k;++i){
        int mess;
        cin>>mess;
        distance[mess-1] = {0,mess-1};
    }
    // priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq(distance.begin(),distance.end());
    set<pair<int,int>> s(distance.begin(),distance.end());
    // while(!s.empty())
    // {
    //     cout<<(*s.begin()).first<<" "<<(*s.begin()).second<<endl;
    //     s.erase(*s.begin());
    // }
    // return 0;
    vector<pair<int,int>> weight[n];
    for(int i=0;i<m;++i)
    {
        int u,v,w;cin>>u>>v>>w;
        weight[u-1].push_back({v-1,w});
        weight[v-1].push_back({u-1,w});
    }
    // for(int i=0;i<n;++i)
    // {
    //     for(auto x : weight[i])
    //     cout<<x.first+1<<" "<<x.second<<endl;
    //     cout<<endl;
    // }
    // for(int i=0;i<n;++i) cout<<distance[i]<<" ";
    // cout<<endl;
    djkistra(s,n,distance,weight);
    for(int i=0;i<n;++i)
    {
        cout<<distance[i].first<<" ";
    }
    cout<<endl;
    return 0;
}