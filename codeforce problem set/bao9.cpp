#include <stdio.h>

void combinationUtil(int arr[], int data[], int start, int end, int index, int r)
{
    if (index == r)
    {
        for (int i = 0; i < r; i++)
            printf("%d ", data[i]);
        printf("\n");
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i + 1, end, index + 1, r);
    }
}

void combination(int arr[], int n, int r)
{
    int data[r];
    combinationUtil(arr, data, 0, n - 1, 0, r);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int r = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    combination(arr, n, r);
    return 0;
}
