#include <stdio.h>

#define MAX 10

int adj[MAX][MAX], visited[MAX], n;

void dfs(int v) {
    visited[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[v][i] != 0 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 for no edge):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize the visited array
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }

    // Start DFS from the first vertex
    dfs(1);

    // Check if all vertices are visited
    int connected = 1;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            connected = 0;
            break;
        }
    }

    if (connected) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is disconnected.\n");
    }

    return 0;
}
