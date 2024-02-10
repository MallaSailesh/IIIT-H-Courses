#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
// #define  int long long 
#define endl "\n"
int sum ;
void djkistra(set<pair<int,int>> &s,int n , vector<pair<int,int>> &distance2,vector<pair<int,int>> distance[])
{
    vector<int> visited(n,false);
    // for(int j = 0;j<n;j++)
    while(!s.empty())
    {
        sum += (*s.begin()).first;
        // cout<<sum<<" ";
        int u = (*s.begin()).second;
        s.erase(*s.begin());
        visited[u] = true ;
        for(auto x : distance[u])
        {
            if(!visited[x.first])
            {
                auto it = s.find(distance2[x.first]);
                distance2[x.first].first = min(distance2[x.first].first,x.second);
                s.erase(*it);
                s.insert({distance2[x.first].first,distance2[x.first].second});
            }
        }  
    }
}
bool cmp1(pair<int,int> &x , pair<int,int> &y)
{
    if(x.first<y.first) return true ;
    return false;
}
bool cmp2(pair<int,int> &x, pair<int,int> &y)
{
    if(x.second<y.second) return true ;
    return false;
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n ; cin>>n;
    vector<pair<int,int>> distance2(n,{INT_MAX,0});
    for(int i=0;i<n;++i)
    distance2[i] = {INT_MAX,i};
    distance2[0] = {0,0};
    set<pair<int,int>> s(distance2.begin(),distance2.end());
    vector<pair<int,int>> weight1,weight2;
    vector<pair<int,int>> distance[n];
    unordered_map<string, int> umap;
    for(int i=0;i<n;++i)
    {
        int x ,y ;cin>>x>>y;
        weight1.push_back({x,y});
        weight2.push_back({x,y});
        umap[to_string(x) + to_string(y)] = i;
    }
    // for(int i=0;i<n;++i)
    // {
    //     for(int j=i+1;j<n;++j)
    //     {
    //         int minv = min(abs((weight[i].first)-(weight[j].first)),abs((weight[i].second)-(weight[j].second)));
    //         distance[i].push_back({j,minv});
    //         distance[j].push_back({i,minv});
    //     }
    // }
    sort(weight1.begin(),weight1.end(),cmp1);
    for(int i=0;i<weight1.size()-1;i++)
    {
        distance[umap[to_string(weight1[i].first)+to_string(weight1[i].second)]].push_back({umap[to_string(weight1[i+1].first)+to_string(weight1[i+1].second)],min(abs(weight1[i].first - weight1[i+1].first),abs(weight1[i].second - weight1[i+1].second))});
        distance[umap[to_string(weight1[i+1].first)+to_string(weight1[i+1].second)]].push_back({umap[to_string(weight1[i].first)+to_string(weight1[i].second)],min(abs(weight1[i].first - weight1[i+1].first),abs(weight1[i].second - weight1[i+1].second))});
    }
    sort(weight2.begin(),weight2.end(),cmp2);
    // for(int i=0;i<weight1.size();++i)
    // cout<<weight2[i].first<<" "<<weight2[i].second<<endl;
    for(int i=0;i<weight2.size()-1;i++)
    {
        distance[umap[to_string(weight2[i].first)+to_string(weight2[i].second)]].push_back({umap[to_string(weight2[i+1].first)+to_string(weight2[i+1].second)],min(abs(weight2[i].first - weight2[i+1].first),abs(weight2[i].second - weight2[i+1].second))});
        distance[umap[to_string(weight2[i+1].first)+to_string(weight2[i+1].second)]].push_back({umap[to_string(weight2[i].first)+to_string(weight2[i].second)],min(abs(weight2[i].first - weight2[i+1].first),abs(weight2[i].second - weight2[i+1].second))});

    }
    // for(int i=0;i<n;++i)
    // {
    //     for(auto x : distance[i])
    //     cout<<i+1<<" "<<x.second+1<<"==>"<<x.first<<endl;
    //     cout<<endl;
    // }
    sum = 0;
    djkistra(s,n,distance2,distance);
    // for(int i=0;i<n;++i)
    // {
    //     sum += distance2[i].first;
    //     // cout<<distance2[i].first<<" ";
    // }
    // cout<<endl;
    cout<<sum<<endl;
    return 0;
}