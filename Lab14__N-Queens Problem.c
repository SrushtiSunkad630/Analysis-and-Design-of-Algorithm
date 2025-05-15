#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x[20], count = 1;

void queens(int, int);
int place(int, int);

int main() {
    int n, k = 1;
    printf("Enter the number of queens to be placed: ");
    scanf("%d", &n);
    queens(k, n);
    return 0;
}

void queens(int k, int n) {
    int j, i;
    for (j = 1; j <= n; j++) {
        if (place(k, j)) {
            x[k] = j;
            if (k == n) {
                printf("\n%d solution", count++);
                for (i = 1; i <= n; i++)
                    printf("\n\t%d row <--> %d column", i, x[i]);
                printf("\n");
            } else {
                queens(k + 1, n);
            }
        }
    }
}

int place(int k, int j) {
    int i;
    for (i = 1; i < k; i++) {
        if (x[i] == j || abs(x[i] - j) == abs(i - k))
            return 0;
    }
    return 1;
}

OUTPUT
Enter the number of queens to be placed: 4

1 solution
    1 row <--> 2 column
    2 row <--> 4 column
    3 row <--> 1 column
    4 row <--> 3 column

2 solution
    1 row <--> 3 column
    2 row <--> 1 column
    3 row <--> 4 column
    4 row <--> 2 column
