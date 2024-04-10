#include <stdio.h>

int lengthOfLIS(int* nums, int size) {
    if (size == 0)
        return 0;

    int max = 1;

    for (int i = 1; i < size; i++) {
        if (nums[i] > nums[i - 1]) {
            int sub_max = lengthOfLIS(nums, i) + 1;
            if (sub_max > max)
                max = sub_max;
        }
    }

    return max;
}

int main() {
    int size;

    printf("Nhap so phan tu cua day: ");
    scanf("%d", &size);

    int nums[size];

    printf("Nhap cac so nguyen duong trong day: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }

    int result = lengthOfLIS(nums, size);

    printf("Day con tang dan dai nhat trong day la: %d", result);

    return 0;
}
