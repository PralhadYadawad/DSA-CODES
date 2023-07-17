#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// This struct represents a directed graph using
// adjacency list representation
typedef struct Graph_t {
    // No. of vertices
    int V;
    bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Constructor
Graph* Graph_create(int V)
{
    Graph* g = malloc(sizeof(Graph));
    g->V = V;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = false;
        }
    }

    return g;
}

// Destructor
void Graph_destroy(Graph* g) { free(g); }

// Function to add an edge to graph
void Graph_addEdge(Graph* g, int v, int w)
{
    // Add w to v’s list.
    g->adj[v][w] = true;
}

// Prints BFS traversal from a given source s
void Graph_BFS(Graph* g, int s, int* traversal, int* traversalSize)
{
    // Mark all the vertices as not visited
    bool visited[MAX_VERTICES];
    for (int i = 0; i < g->V; i++) {
        visited[i] = false;
    }

    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue[rear++] = s;

    while (front != rear) {

        // Dequeue a vertex from queue and add it to traversal
        int vertex = queue[front++];
        traversal[(*traversalSize)++] = vertex;

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (int adjacent = 0; adjacent < g->V; adjacent++) {
            if (g->adj[vertex][adjacent] && !visited[adjacent]) {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }
    }
}

// Function to display the BFS traversal
void displayTraversal(int* traversal, int traversalSize)
{
    printf("Breadth First Traversal: ");
    for (int i = 0; i < traversalSize; i++) {
        printf("%d ", traversal[i]);
    }
    printf("\n");
}

// Driver code
int main()
{
    int numVertices;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    // Create a graph
    Graph* g = Graph_create(numVertices);

    int numEdges;
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    printf("Enter the edges in the format (source destination):\n");
    for (int i = 0; i < numEdges; i++) {
        int source, destination;
        scanf("%d %d", &source, &destination);
        Graph_addEdge(g, source, destination);
    }

    int sourceVertex;
    printf("Enter the source vertex for Breadth First Traversal: ");
    scanf("%d", &sourceVertex);

    // Perform BFS and store the traversal
    int traversal[MAX_VERTICES];
    int traversalSize = 0;
    Graph_BFS(g, sourceVertex, traversal, &traversalSize);

    // Display the BFS traversal
    displayTraversal(traversal, traversalSize);

    Graph_destroy(g);

    return 0;
}
