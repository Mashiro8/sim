#include <iostream>
using namespace std;
float pow(int n)
{
    if (n == 0)
    return 1;
    else 
    return pow(n-1) + 1/pow(n-1);
}
int main()
{
    int n;
    double a;
    cin >> n;
    cout <<  pow(n);
    return 0;
}