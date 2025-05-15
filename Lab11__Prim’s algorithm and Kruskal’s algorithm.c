//Prim’s Algorithm (Minimum Spanning Tree)
#include <stdio.h>

int cost[10][10], n, t[10][2], sum;

void prims(int cost[10][10], int n);

int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    prims(cost, n);

    printf("Edges of the minimal spanning tree:\n");
    for (i = 0; i < n - 1; i++) {
        printf("(%d, %d) ", t[i][0], t[i][1]);
    }
    printf("\nSum of minimal spanning tree: %d\n", sum);
    return 0;
}

void prims(int cost[10][10], int n) {
    int d[10], p[10], s[10] = {0};
    int i, j, u, v, min, k = 0;

    for (i = 0; i < n; i++) {
        d[i] = cost[0][i];
        p[i] = 0;
    }

    s[0] = 1;
    sum = 0;

    for (i = 0; i < n - 1; i++) {
        min = 999;
        u = -1;

        for (j = 0; j < n; j++) {
            if (!s[j] && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        if (u != -1) {
            t[k][0] = u;
            t[k][1] = p[u];
            k++;
            sum += cost[u][p[u]];
            s[u] = 1;

            for (v = 0; v < n; v++) {
                if (!s[v] && cost[u][v] < d[v]) {
                    d[v] = cost[u][v];
                    p[v] = u;
                }
            }
        }
    }
}

OUTPUT
0 1 5 2
1 0 99 99
5 99 0 3
2 99 3 0

Enter the number of vertices: 4
Enter the cost adjacency matrix:
0 1 5 2
1 0 99 99
5 99 0 3
2 99 3 0

Edges of the minimal spanning tree:
(1, 0) (3, 0) (2, 3) 
Sum of minimal spanning tree: 6




//Kruskal’s Algorithm (Minimum Spanning Tree)

#include <stdio.h>

int cost[10][10], n, t[10][2], sum;

void kruskal(int cost[10][10], int n);
int find(int parent[10], int i);

int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    kruskal(cost, n);

    printf("Edges of the minimal spanning tree:\n");
    for (i = 0; i < n - 1; i++) {
        printf("(%d, %d) ", t[i][0], t[i][1]);
    }
    printf("\nSum of minimal spanning tree: %d\n", sum);
    return 0;
}

void kruskal(int cost[10][10], int n) {
    int parent[10], count = 0, k = 0;
    int i, j, min, u = -1, v = -1;

    for (i = 0; i < n; i++) {
        parent[i] = i;
    }

    sum = 0;

    while (count < n - 1) {
        min = 999;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (find(parent, i) != find(parent, j) && cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (u != -1 && v != -1) {
            parent[find(parent, u)] = find(parent, v);
            t[k][0] = u;
            t[k][1] = v;
            k++;
            sum += min;
            count++;
        }
    }
}

int find(int parent[10], int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}


OUTPUT
0 1 5 2
1 0 99 99
5 99 0 3
2 99 3 0
Enter the number of vertices: 4
Enter the cost adjacency matrix:
0 1 5 2
1 0 99 99
5 99 0 3
2 99 3 0

Edges of the minimal spanning tree:
(1, 0) (3, 0) (2, 3) 
Sum of minimal spanning tree: 6

