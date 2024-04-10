#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 101
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[N];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=a[k-1]&&a[i]!=0)
        count++;
    }
    cout<<count;
}
