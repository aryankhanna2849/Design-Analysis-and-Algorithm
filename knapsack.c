#include <stdio.h>

void sortItems(int n, int value[], int weight[], double ratio[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratios
                double tempR = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = tempR;

                // Swap values
                int tempV = value[i];
                value[i] = value[j];
                value[j] = tempV;

                // Swap weights
                int tempW = weight[i];
                weight[i] = weight[j];
                weight[j] = tempW;
            }
        }
    }
}

double fractionalKnapsack(int capacity, int value[], int weight[], int n) {
    double ratio[n];
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)value[i] / weight[i];
    }

    sortItems(n, value, weight, ratio);

    double totalValue = 0.0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (weight[i] <= capacity) {
            capacity -= weight[i];
            totalValue += value[i];
        } else {
            totalValue += value[i] * ((double)capacity / weight[i]);
            break;
        }
    }

    return totalValue;
}

int main() {
    int value[] = {100, 60, 120};
    int weight[] = {20, 10, 30};
    int capacity = 50;
    int n = sizeof(value) / sizeof(value[0]);

    double maxValue = fractionalKnapsack(capacity, value, weight, n);
    printf("Maximum value in knapsack = %.2f\n", maxValue);

    return 0;
}