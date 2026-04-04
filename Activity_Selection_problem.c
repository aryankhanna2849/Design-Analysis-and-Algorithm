 #include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Sort activities by finish time (Bubble Sort)
void sortByFinishTime(int start[], int finish[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (finish[j] > finish[j + 1]) {
                swap(&finish[j], &finish[j + 1]);
                swap(&start[j], &start[j + 1]);
            }
        }
    }
}

// Greedy Activity Selection
void activitySelection(int start[], int finish[], int n) {
    // Step 1: Sort by finish time
    sortByFinishTime(start, finish, n);

    printf("Selected activities are:\n");

    // Step 2: Pick the first activity
    int lastFinish = finish[0];
    printf("(%d, %d)\n", start[0], finish[0]);

    // Step 3: Iterate and select non-overlapping activities
    for (int i = 1; i < n; i++) {
        if (start[i] >= lastFinish) {
            printf("(%d, %d)\n", start[i], finish[i]);
            lastFinish = finish[i];
        }
    }
}

int main() {
    int start[]  = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(finish) / sizeof(finish[0]);

    activitySelection(start, finish, n);

    return 0;
}
