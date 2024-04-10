#include <iostream>
using namespace std;

void mergeSort(int *a, int left, int right)
{
    if (left >= right) return;
    int mid = (left + right) / 2;
    int *mangtrai = new int[mid - left + 1];
    int *mangphai = new int[right - mid];
    for (int i = 0; i < mid - left + 1; i++)
        mangtrai[i] = a[left + i];
    for (int i = 0; i < right - mid; i++)
        mangphai[i] = a[mid + 1 + i];
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    hop(a, left, mid, right, mangtrai, mangphai);
}

void hop(int *a, int left, int mid, int right, int *mangtrai, int *mangphai)
{
    int trai = mid - left + 1;
    int phai = right - mid;
    int i = 0, j = 0, k = left;
    while (i < trai && j < phai)
    {
        if (mangtrai[i] <= mangphai[j])
        {
            a[k] = mangtrai[i];
            i++;
        }
        else
        {
            a[k] = mangphai[j];
            j++;
        }
        k++;
    }
    while (i < trai)
    {
        a[k] = mangtrai[i];
        i++;
        k++;
    }
    while (j < phai)
    {
        a[k] = mangphai[j];
        j++;
        k++;
    }
}

int main()
{
    int a[10000], n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergeSort(a, 0, n - 1);
    cout << "sapxep ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}