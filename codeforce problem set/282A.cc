#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int X=0;
    cin>>n;
    string s;
    while(n)
    {
        cin>>s;
        if(s=="++X"||s=="X++")
        X++;
        else
        X--;
        n--;
    }
    cout<<X;

}