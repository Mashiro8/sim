#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int n;
    string a;
    cin>>n;
    while (n>0)
    {
        cin>>a;
        if(a.length()-1 < 10) cout<<a;
        else cout<<a[0]<<a.length()-2<<a[a.length()-1] ;
        n--;
        cout<<endl;
    }
}