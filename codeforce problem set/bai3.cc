#include <bits/stdc++.h>
using namespace std;
long long int f[1000][1000],n;
// quy hoach dong
//tim 
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)      
	f[0][i]=0;
    f[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=n;j++)
        if (i>j) f[i][j]=f[i-1][j];
    else f[i][j]=f[i-1][j]+f[i][j-i];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            {
        cout<<f[i][j]<<" ";
        }cout<<endl;
    }
    cout<<f[n][n];    
    return 0;
}
