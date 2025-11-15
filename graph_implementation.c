#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#define MAX 100   
int adj[MAX][MAX];   
int vertices; 
void addEdge(int edge1, int edge2) { 
    adj[edge1][edge2] = 1; 
    adj[edge2][edge1] = 1; 
}   
void dfs(int adj[MAX][MAX], int V, int start) { 
    bool visited[MAX] = { false };   
    int stack[MAX], top = -1;       
    stack[++top] = start; 
    printf("DFS traversal starting from node %d: ", start + 1); 
    while (top != -1) { 
              int curr = stack[top--]; 
        if (!visited[curr]) { 
            visited[curr] = true; 
            printf("%d ", curr + 1);   
            for (int i = V - 1; i >= 0; i--) {   
                if (adj[curr][i] == 1 && !visited[i]) { 
                    stack[++top] = i; 
                } 
            } 
        } 
    } 
    printf("\n"); 
} 
 
void bfs(int adj[MAX][MAX], int V, int start) { 
    int q[MAX], front = 0, rear = 0; 
    bool visited[MAX] = { false }; 
    visited[start] = true; 
    q[rear++] = start; 
    printf("BFS traversal starting from node %d: ", start + 1); 
    while (front < rear) { 
        int curr = q[front++]; 
        printf("%d ", curr + 1);  
        for (int i = 0; i < V; i++) { 
            if (adj[curr][i] == 1 && !visited[i]) { 
                visited[i] = true; 
                q[rear++] = i; 
            } 
        } 
    } 
    printf("\n"); 
} 
int main() { 
    int edges, edge1, edge2, startVertex; 
    printf("Enter the number of vertices in the graph: "); 
    scanf("%d", &vertices); 
    for (int i = 0; i < vertices; i++) { 
        for (int j = 0; j < vertices; j++) { 
            adj[i][j] = 0; 
        } 
    } 
    printf("Enter the number of edges: "); 
    scanf("%d", &edges); 
    printf("Enter the edges (vertex1 vertex2):\n"); 
    for (int i = 0; i < edges; i++) { 
        scanf("%d %d", &edge1, &edge2); 
        edge1--; 
        edge2--; 
        if (edge1 >= 0 && edge1 < vertices && edge2 >= 0 && edge2 < vertices) { 
            addEdge(edge1, edge2); 
        } else { 
            printf("Invalid edge: (%d, %d)\n", edge1 + 1, edge2 + 1); 
        } 
    } 
    printf("The adjacency matrix is:\n"); 
    for (int i = 0; i < vertices; i++) { 
        for (int j = 0; j < vertices; j++) { 
            printf("%d ", adj[i][j]); 
        } 
        printf("\n"); 
    } 
    printf("Enter the starting vertex for BFS: "); 
    scanf("%d", &startVertex); 
    startVertex--; 
    if (startVertex >= 0 && startVertex < vertices) { 
        bfs(adj, vertices, startVertex); 
    } else { 
        printf("Invalid starting vertex!\n"); 
    } 
    printf("Enter the starting vertex for DFS: "); 
    scanf("%d", &startVertex); 
    startVertex--; 
    if (startVertex >= 0 && startVertex < vertices) { 
        dfs(adj, vertices, startVertex); 
    } else { 
        printf("Invalid starting vertex!\n"); 
    } 
    return 0; 
}
