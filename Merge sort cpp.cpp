#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
    int len1 = mid - start + 1;  // defining length of two new arrays
    int len2 = end - mid;

    int* arr1 = new int[len1];  // making new arrays
    int* arr2 = new int[len2];

    for (int i = 0; i < len1; i++) {  // copying values of left array (arr1)
        arr1[i] = arr[start + i];
    }

    for (int i = 0; i < len2; i++) {  // copying values of right array (arr2)
        arr2[i] = arr[mid + 1 + i];
    }

    int arr1_index = 0;
    int arr2_index = 0;
    int k = start;  // k = main array index

    while (arr1_index < len1 && arr2_index < len2) {
        if (arr1[arr1_index] < arr2[arr2_index]) {
            arr[k++] = arr1[arr1_index++];
        } else {
            arr[k++] = arr2[arr2_index++];
        }
    }

    while (arr1_index < len1) {
        arr[k++] = arr1[arr1_index++];
    }

    while (arr2_index < len2) {
        arr[k++] = arr2[arr2_index++];
    }

    delete[] arr1;
    delete[] arr2;
}

void mergesort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        mergesort(arr, start, mid);       // sorting left
        mergesort(arr, mid + 1, end);   // sorting right

        merge(arr, start, mid, end);
    }
}

int main() {
    int arr[] = {4, 6, 9, 7, 3, 6, 2, 7, 1, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
