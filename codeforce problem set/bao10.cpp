#include <stdio.h>

long catalan(unsigned int n)
{
    if (n <= 1)
        return 1;

    long res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i) * catalan(n - i - 1);

    return res;
}

int main()
{
    int n = 5;
    printf("So Catalan cua %d la %ld\n", n, catalan(n));
    return 0;
}
