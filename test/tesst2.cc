#include <bits/stdc++.h>
using namespace std;
// chia de tri
bool BinarySearch(int a[],int x,int left,int right){
	if(left>right)
    {
		return false;
	}
	int mid=(left+right)/2;
	if(x==a[mid])
    {
		return true;
	}
	if(x<a[mid])
    {
		return BinarySearch(a,x,left,mid-1);
	}
    else
	return BinarySearch(a,x,mid+1,right);
}
int main()
{
    int n,x,a[100000];
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    cin>>x;
    sort(a,a+n);
    BinarySearch(a,x,0,n) ? cout<<"true" : cout<<"false";
}