//Trees
//1. Invert Binary Tree (Leetcode #226)
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

TreeNode* invertTree(TreeNode* root) {
    if (!root) return NULL;
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(9);

    printf("Original Inorder: ");
    inorder(root);
    invertTree(root);
    printf("\nInverted Inorder: ");
    inorder(root);
    return 0;
}

OUTPUT
Original Inorder: 1 2 3 4 6 7 9 
Inverted Inorder: 9 7 6 4 3 2 1 


// GRAPHS
// 2.Detect Cycle in Undirected Graph (DFS) (Leetcode #684 style)
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int adj[MAX][MAX];
int n;

int dfs(int v, int parent) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (dfs(i, v))
                    return 1;
            } else if (i != parent) {
                return 1; // cycle detected
            }
        }
    }
    return 0;
}

int main() {
    n = 5;
    // Edges of undirected graph
    int edges[][2] = {{0,1},{1,2},{2,3},{3,4},{4,1}};
    for (int i = 0; i < 5; i++) {
        adj[edges[i][0]][edges[i][1]] = 1;
        adj[edges[i][1]][edges[i][0]] = 1;
    }

    if (dfs(0, -1))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}

OUTPUT
Cycle detected
