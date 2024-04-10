#include <stdio.h>

int GCD(int a, int b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

int main() {
    int num1, num2;

    printf("Nhap 2 so nguyen duong: ");
    scanf("%d %d", &num1, &num2);

    printf("Uoc chung lon nhat cua 2 so %d va %d la: %d", num1, num2, GCD(num1, num2));

    return 0;
}
