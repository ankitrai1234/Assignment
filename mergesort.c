#include <stdio.h>

void mergeinplace(int arr[], int s, int m, int e);

void mergesort(int arr[], int s, int e) {
    if (e - s == 1) {
        return;
    }
    int m = (e + s) / 2;
    mergesort(arr, s, m);
    mergesort(arr, m, e);
    mergeinplace(arr, s, m, e);
}

void mergeinplace(int arr[], int s, int m, int e) {
    int mix[e - s];
    int i = s;
    int j = m;
    int k = 0;

    while (i < m && j < e) {
        if (arr[i] < arr[j]) {
            mix[k] = arr[i];
            i++;
        } else {
            mix[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i < m) {
        mix[k] = arr[i];
        i++;
        k++;
    }

    while (j < e) {
        mix[k] = arr[j];
        j++;
        k++;
    }

    for (int l = 0; l < sizeof(mix) / sizeof(int); l++) {
        arr[s + l] = mix[l];
    }
}

int main() {
    int arr[] = {4, 7, 3, 2, 1};
    int arr_size = sizeof(arr) / sizeof(int);

    mergesort(arr, 0, arr_size);

    for (int i = 0; i < arr_size; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}

