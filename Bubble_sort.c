#include <stdio.h>
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        // Last i elements are already sorted
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n, i;
    // Input size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n]; 
    // Input array elements
    printf("Enter %d positive integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Sort the array
    bubbleSort(arr, n);
    // Output sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}