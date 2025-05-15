#include <stdio.h>
#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int dp[MAX][MAX];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
}

int main() {
    int n, W, val[MAX], wt[MAX];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights of %d items:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter values of %d items:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);

    printf("Enter maximum capacity of knapsack: ");
    scanf("%d", &W);

    int result = knapsack(W, wt, val, n);
    printf("Maximum value in Knapsack = %d\n", result);

    return 0;
}

//OUTPUT
Enter number of items: 3
Enter weights of 3 items:
10 20 30
Enter values of 3 items:
60 100 120
Enter maximum capacity of knapsack: 50
Maximum value in Knapsack = 220
