#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define N 210
#define inf 2e18
#define pb push_back
#define pp pair<int ,int>
#define fi first
#define se second
int adj[N][N];
int k,ans=0;
int vis[N],dist[N],n;
\*int dfs(int s)
{
    int a,b;
    memset(dist,0,sizeof(dist));
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==1&&adj[a][i]==0)
            {
                q.push(i);
                vis[i]=1;
            }
        }
    }
    //bfs
    q.push(a);
    vis[a]=2;
    while(!q.empty())
    {
        b=q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0&&adj[b][i])
            {
                q.push(i);
                vis[i]=2;
                dist[i]=dist[b]+1;
            }
        }
    }
    return dist[b];
}*\
int dfs (int s)
{
    
}
int main()
{
    vector<pp> edges;
    int n;
    vector<int> temp; 
    cin>>n;
    memset (adj ,0 ,sizeof(adj) );
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
        edges.pb({u,v});
    }
    for(pp e : edges)
    {
        adj[e.fi][e.se]=0;
        adj[e.se][e.fi]=0;
        memset(vis, 0, sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                k=dfs(i);
               cout<<k;
                temp.pb(k);
            }
        }
         ans= max (ans ,temp[0]* temp[1]);
        temp.clear();
        adj[e.fi][e.se]=1;
        adj[e.se][e.fi]=1;
    }
      cout<<ans;   
}