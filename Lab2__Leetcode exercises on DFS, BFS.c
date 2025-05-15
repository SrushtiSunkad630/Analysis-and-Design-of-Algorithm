// 1. DFS: Number of Islands (Leetcode #200)
#include <stdio.h>

#define ROWS 4
#define COLS 5

char grid[ROWS][COLS] = {
    {'1', '1', '0', '0', '0'},
    {'1', '1', '0', '0', '0'},
    {'0', '0', '1', '0', '0'},
    {'0', '0', '0', '1', '1'}
};

void dfs(int i, int j) {
    if (i < 0 || i >= ROWS || j < 0 || j >= COLS || grid[i][j] == '0')
        return;
    grid[i][j] = '0'; // mark as visited
    dfs(i+1, j);
    dfs(i-1, j);
    dfs(i, j+1);
    dfs(i, j-1);
}

int numIslands() {
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == '1') {
                dfs(i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
    printf("Number of islands: %d\n", numIslands());
    return 0;
}

OUTPUT
Number of islands: 3



//2. BFS: Shortest Path in Binary Matrix (Leetcode #1091)
#include <stdio.h>
#include <stdlib.h>

#define N 3

int grid[N][N] = {
    {0, 1, 0},
    {1, 0, 0},
    {1, 1, 0}
};

int dx[] = {-1,-1,-1,0,1,1,1,0};
int dy[] = {-1,0,1,1,1,0,-1,-1};

typedef struct {
    int x, y, dist;
} Node;

int isValid(int x, int y, int visited[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && grid[x][y] == 0 && !visited[x][y]);
}

int bfs() {
    if (grid[0][0] != 0) return -1;

    int visited[N][N] = {0};
    Node queue[N*N];
    int front = 0, rear = 0;

    queue[rear++] = (Node){0, 0, 1};
    visited[0][0] = 1;

    while (front < rear) {
        Node current = queue[front++];

        if (current.x == N-1 && current.y == N-1)
            return current.dist;

        for (int i = 0; i < 8; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            if (isValid(nx, ny, visited)) {
                visited[nx][ny] = 1;
                queue[rear++] = (Node){nx, ny, current.dist + 1};
            }
        }
    }
    return -1;
}

int main() {
    int result = bfs();
    if (result == -1)
        printf("No path found.\n");
    else
        printf("Shortest path length is: %d\n", result);
    return 0;
}

OUTPUT
Shortest path length is: 4
