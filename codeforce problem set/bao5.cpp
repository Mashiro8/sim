#include <stdio.h>

int sumDigits(int num) {
    if (num == 0)
        return 0;
    else
        return (num % 10) + sumDigits(num / 10);
}

int main() {
    int num;

    printf("Nhap mot so nguyen duong: ");
    scanf("%d", &num);

    printf("Tong cac chu so cua so %d la: %d", num, sumDigits(num));

    return 0;
}
