#include <iostream>
using namespace std;
typedef long long ll;
ll fibonnaci(int n)
{
    ll a[n+1];
    a[0]=0; a[1]=1; a[2]=1;
    for(int i=3;i<=n;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    return a[n];
}
int main()
{
    int n;
    cout<<"Nhap n:"; 
    while(cin>>n)
    {
    cout<<"Fibonacci thu n la: "<<fibonnaci(n)<<"\n"<<"nhap n :";
    }
}