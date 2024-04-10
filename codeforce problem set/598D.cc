#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <set>
#include <unordered_set>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod=100000000005LL;
int x[N];
vecotr<int> edges[N];

void bfs(int d,int u)
{

}
int main()
{
     int t;
     cin>>t;
     while(t)
     {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=k;i++)
        cin>>x[i];
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        t--;
     }
}