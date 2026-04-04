#include <stdio.h>
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];      // Element to be inserted into the sorted part
        j = i - 1;
        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;  // Place the key in its correct position
    }
}
int main() {
    int n, i;
    // Input size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n]; // Declare array
    // Input array elements
    printf("Enter %d positive integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Sort the array
    insertionSort(arr, n);
    // Output sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}