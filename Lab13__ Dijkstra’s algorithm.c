#include <stdio.h>
#include <conio.h>

void main() {
    int i, j, n, v, k, min, u;
    int c[20][20], s[20], d[20];
    
    clrscr();
    
    printf("\nEnter the no. of vertices: ");
    scanf("%d", &n);
    
    printf("\nEnter the cost adjacency matrix:\n");
    printf("Enter 999 for no edge\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    
    printf("\nEnter the source vertex: ");
    scanf("%d", &v);
    
    // Initialize
    for (i = 1; i <= n; i++) {
        s[i] = 0;
        d[i] = c[v][i];
    }
    d[v] = 0;
    s[v] = 1;
    
    for (k = 2; k <= n; k++) {
        min = 999;
        u = -1;
        
        // Find vertex u with minimum distance not in S
        for (i = 1; i <= n; i++) {
            if (s[i] == 0 && d[i] < min) {
                min = d[i];
                u = i;
            }
        }
        
        s[u] = 1;
        
        // Update distances
        for (i = 1; i <= n; i++) {
            if (s[i] == 0 && d[i] > d[u] + c[u][i]) {
                d[i] = d[u] + c[u][i];
            }
        }
    }
    
    printf("\nThe shortest distance from %d is:\n", v);
    for (i = 1; i <= n; i++) {
        printf("%d --> %d = %d\n", v, i, d[i]);
    }
    
    getch();
}

OUTPUT
Enter the no. of vertices: 5

Enter the cost adjacency matrix:
Enter 999 for no edge
999 7 3 999 999
7 999 2 5 4
3 2 999 4 999
999 5 4 999 6
999 4 999 6 999

Enter the source vertex: 1

The shortest distance from 1 is:
1 --> 1 = 0
1 --> 2 = 5
1 --> 3 = 3
1 --> 4 = 7
1 --> 5 = 9
