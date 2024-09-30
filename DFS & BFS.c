#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for a graph
struct Graph {
    int adj[MAX][MAX];
    int numVertices;
};

// Function to create a graph
void createGraph(struct Graph* g, int vertices) {
    g->numVertices = vertices;

    // Initialize adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph* g, int start, int end) {
    g->adj[start][end] = 1;
    g->adj[end][start] = 1; // For undirected graph
}

// DFS helper function
void DFSUtil(struct Graph* g, int vertex, int visited[]) {
    visited[vertex] = 1; // Mark the current node as visited
    printf("%d ", vertex); // Print the current node

    for (int i = 0; i < g->numVertices; i++) {
        if (g->adj[vertex][i] == 1 && !visited[i]) {
            DFSUtil(g, i, visited);
        }
    }
}

// Function to perform DFS
void DFS(struct Graph* g) {
    int visited[MAX] = {0}; // Initialize visited array
    printf("Depth First Search: ");
    for (int i = 0; i < g->numVertices; i++) {
        if (!visited[i]) {
            DFSUtil(g, i, visited);
        }
    }
    printf("\n");
}

// Function to perform BFS
void BFS(struct Graph* g, int startVertex) {
    int visited[MAX] = {0}; // Initialize visited array
    int queue[MAX], front = -1, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex; // Enqueue the start vertex
    printf("Breadth First Search: ");

    while (front != rear) {
        front++;
        int currentVertex = queue[front];
        printf("%d ", currentVertex);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adj[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1; // Mark as visited
                queue[++rear] = i; // Enqueue
            }
        }
    }
    printf("\n");
}

int main() {
    struct Graph g;
    int vertices, edges, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    createGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    for (int i = 0; i < edges; i++) {
        int start, end;
        printf("Enter edge %d (start end): ", i + 1);
        scanf("%d %d", &start, &end);
        addEdge(&g, start, end);
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    DFS(&g);         // Perform DFS
    BFS(&g, startVertex); // Perform BFS

    return 0;
}
