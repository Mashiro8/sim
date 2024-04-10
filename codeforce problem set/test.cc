#include <iostream>
using namespace std;

void mergeSort(int arr[], int left, int right) {
    // Base case: If the length of the array is 1 or less, return
    if (left >= right) return;

    // Split the array into two halves
    int mid = (left + right) / 2;
    int leftHalf[] = arr[left];
    int rightHalf[] = arr[mid];

    // Recursively sort each half
    mergeSort(arr, left, mid);
    mergeSort(arr, mid, right);

    // Merge the sorted halves together
    merge(arr, left, mid, right);
}

void merge(int arr[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    int result[leftSize + rightSize];
    int i, j, k;

    // Merge the two sorted arrays together
    for (i = 0; i < leftSize; i++) {
        result[k++] = arr[left + i];
    }
    for (j = 0; j < rightSize; j++) {
        result[k++] = arr[mid + j];
    }

    // Replace the original array with the merged result
    for (i = 0; i < leftSize + rightSize; i++) {
        arr[i] = result[i];
    }
}

int main() {
    int arr[5] = {3, 4, 5, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "After sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}