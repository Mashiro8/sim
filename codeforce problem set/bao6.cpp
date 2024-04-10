#include <stdio.h>
#include <string.h>

int isPalindrome(char str[], int low, int high) {
    if (low >= high)
        return 1;

    if (str[low] != str[high])
        return 0;

    return isPalindrome(str, low + 1, high - 1);
}

int main() {
    char str[100];

    printf("Nhap mot chuoi ky tu: ");
    scanf("%s", str);

    if (isPalindrome(str, 0, strlen(str) - 1))
        printf("Chuoi %s la palindrome.", str);
    else
        printf("Chuoi %s khong phai la palindrome.", str);

    return 0;
}
