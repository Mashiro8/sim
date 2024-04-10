#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int t,count=0;
    cin>>t;
   while(t)
   {
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b==2||b+c==2||c+a==2)
    {
    count++;
    }
    t--;
   }
   cout<<count;
   return 0;
}