#include <stdio.h>

int power(int x, int n) {
    if (n == 0)
        return 1;
    else
        return x * power(x, n - 1);
}

int main() {
    int x, n;

    printf("Nhap mot so nguyen duong x: ");
    scanf("%d", &x);

    printf("Nhap mot so nguyen duong n: ");
    scanf("%d", &n);

    printf("Luy thua cua %d la: %d", x, power(x, n));

    return 0;
}
