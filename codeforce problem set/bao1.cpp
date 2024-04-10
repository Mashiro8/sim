#include <stdio.h>

long long int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    printf("Nhap vao so nguyen duong n: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("So nhap vao khong hop le.\n");
    } else {
        printf("Giai thua cua %d la %lld.\n", n, factorial(n));
    }
    return 0;
}
