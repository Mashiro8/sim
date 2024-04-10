#include <iostream>
#include <vector>
using namespace std;
int n,x[10000];
typedef long long ll;
void tri(int i)
{
     for(int j=0;j<=1;j++)
     {
        x[i]=j;
        if(i==n) {for(int k=1;k<=n;k++) {cout<<x[k];} cout<<endl ;}
        else tri(i+1);
     }
} 
int main()
{
      cin>>n;
      tri(1);
}