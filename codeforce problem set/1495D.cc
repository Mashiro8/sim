#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#define N 405
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
vector <int, int> edges[N];
queue <int ,int > q;
void bfs (int u, int v)
{

}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
       int a,b;
       cin>>a>>b;
       edges[a].push_back(b);
       edges[b].push_back(a);
    }
    for( auto : )
}