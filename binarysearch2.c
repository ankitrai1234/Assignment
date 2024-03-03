#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[7];
    int length = sizeof(arr) / sizeof(arr[0]);
    for(int i=0;i<length;i++){
        scanf("%d",&arr[i]);
    }
    int target;
    printf("Enter the number that you want to search");
    scanf("%d",&target);
    int result = binarySearch(arr, 0, length - 1, target);
    if (result == -1)
        printf("Element not found");
    else
        printf("Element %d is present at index %d", target, result);
    return 0;
}

