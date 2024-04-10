#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool isPrime(int n) {
   if (n < 2) return false;
  if(n==2||n==3) return true;
   for (int i = 2; i  <= sqrt(n); i ++) {
       if (n % i == 0 ) {
           return false;
       }
   }
   return true;
}
//hàm tính tổng
int sums(int a) {
   int sum = 0;
   while (a > 0) {
       sum += a % 10;
       a /= 10;
   }
   return sum;
}
//hàm đảo số
int reverseNum(int b) {
   int reverse = 0;
   while (b > 0) {
       reverse = reverse * 10 + (b % 10);
       b /= 10;
   }
   return reverse;
}
//hàm tạo các số từ 2,3,5,7
void generate_numbers(int n, vector<int> &result, vector<int> &result2) {
    if (n == 0) {
        int k=0;
        for (int i = 0; i < result.size(); i++) {
            k=k*10+result[i];
        }
        if(isPrime(k))
        result2.push_back(k);
        return;
    }
    for (int digit : {2, 3, 5, 7}) {
        if (n - 1 < 0) {
            continue;
        }
        result.push_back(digit);
        generate_numbers(n - 1, result ,result2);
        result.pop_back();
    }
}

int main() {
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int n,x;
    cin>>x;
    while(x>0)
    {
    cin >> n;
    vector<int> result, result2;
    generate_numbers(n, result, result2);
    int dem =0;
    for(int prime :result2)
    {
     if (isPrime(sums(prime)) && isPrime(reverseNum(prime))) {
            dem++;
    }
    }
    cout<<n<<" "<<dem<<endl;
    x--;
    }
    return 0;
}
