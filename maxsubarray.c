#include <stdio.h>
#include <limits.h>

// Function to find max crossing subarray sum
int maxCrossingSum(int arr[], int left, int mid, int right) {
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0; 
    int right_sum = INT_MIN;
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}
 
// Recursive function to find maximum subarray sum
int maxSubArraySum(int arr[], int left, int right) {
    if (left == right)
        return arr[left];

    int mid = (left + right) / 2;

    int left_max = maxSubArraySum(arr, left, mid);
    int right_max = maxSubArraySum(arr, mid + 1, right);
    int cross_max = maxCrossingSum(arr, left, mid, right);

    // Return the maximum of the three
    if (left_max >= right_max && left_max >= cross_max)
        return left_max;
    else if (right_max >= left_max && right_max >= cross_max)
        return right_max;
    else
        return cross_max;
}

int main() {
    int arr[] = {2, -4, 3, -1, 2, -4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_sum = maxSubArraySum(arr, 0, n - 1);
    printf("Maximum Subarray Sum: %d\n", max_sum);

    return 0;
}