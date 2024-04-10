#include <stdio.h>
#include <string.h>

void reverse(char str[], int length) {
    if (length == 1)
        return;
    else {
        printf("%c", str[length - 1]);
        reverse(str, length - 1);
    }
}

int main() {
    char str[100];

    printf("Nhap mot chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0'; 
    printf("Chuoi dao nguoc la: ");
    reverse(str, strlen(str));

    return 0;
}
