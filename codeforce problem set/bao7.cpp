#include <stdio.h>

int Ackermann(int m, int n) {
    if (m == 0)
        return n + 1;
    else if (m > 0 && n == 0)
        return Ackermann(m - 1, 1);
    else if (m > 0 && n > 0)
        return Ackermann(m - 1, Ackermann(m, n - 1));

    return -1;
}

int main() {
    int m, n;

    printf("Nhap mot so nguyen duong m: ");
    scanf("%d", &m);

    printf("Nhap mot so nguyen duong n: ");
    scanf("%d", &n);

    int result = Ackermann(m, n);

    if (result != -1)
        printf("Gia tri ham Ackermann A(%d, %d) la: %d", m, n, result);
    else
        printf("Gia tri ham Ackermann A(%d, %d) khong xac dinh.", m, n);

    return 0;
}
