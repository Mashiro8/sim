#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int a[6][6];
    int sw=0;
    for(int i=1;i<=5;i++)
    {
    for(int j=1;j<=5;j++)
    {
        cin>>a[i][j];
        if(a[i][j]==1)
        {
            sw= abs(3-i)+ abs(3-j);
        }
    }
    }
    cout<<sw;
}