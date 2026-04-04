#include <stdio.h>

int n, W;
int wt[20], val[20];

// -----------------------------
// Bound Calculation Function
// -----------------------------
float calcBound(int lvl, int wtSoFar, int prSoFar) {
    int tw = wtSoFar;
    float ub = prSoFar;

    for (int i = lvl + 1; i < n; i++) {
        if (tw + wt[i] <= W) {
            tw += wt[i];
            ub += val[i];
        } else {
            ub += (W - tw) * (float)val[i] / wt[i];
            break;
        }
    }
    return ub;
}

// -----------------------------
// Main Program
// -----------------------------
int main() {

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);

    printf("Enter Knapsack Capacity: ");
    scanf("%d", &W);

    int level[500], weight[500], profit[500];
    float bound[500];

    int front = 0, rear = 0;
    int bestProfit = 0;

    // Root node
    level[rear] = -1;
    weight[rear] = 0;
    profit[rear] = 0;
    bound[rear] = 99999; 
    rear++;

    // BFS-like simple queue B&B
    while (front < rear) {
        int L = level[front];
        int Wt = weight[front];
        int Pf = profit[front];
        float Bd = bound[front];
        front++;

        if (Bd < bestProfit)
            continue;

        int next = L + 1;
        if (next >= n)
            continue;

        // Left child (include item)
        int lw = Wt + wt[next];
        int lp = Pf + val[next];
        float lb = calcBound(next, lw, lp);

        if (lw <= W && lp > bestProfit)
            bestProfit = lp;

        if (lb > bestProfit) {
            level[rear] = next;
            weight[rear] = lw;
            profit[rear] = lp;
            bound[rear] = lb;
            rear++;
        }

        // Right child (exclude item)
        int rw = Wt;
        int rp = Pf;
        float rb = calcBound(next, rw, rp);

        if (rb > bestProfit) {
            level[rear] = next;
            weight[rear] = rw;
            profit[rear] = rp;
            bound[rear] = rb;
            rear++;
        }
    }

    printf("\nMaximum Profit = %d\n", bestProfit);

    return 0;
}
