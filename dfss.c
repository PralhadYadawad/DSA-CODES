#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    struct Node* adjacencyList[MAX_NODES];
    int visited[MAX_NODES];
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

void dfs(struct Graph* graph, int startNode) {
    struct Node* stack[MAX_NODES];
    int top = -1;
    stack[++top] = createNode(startNode);
    graph->visited[startNode] = 1;

    printf("DFS Traversal: ");
    while (top != -1) {
        struct Node* currentNode = stack[top--];
        printf("%d ", currentNode->data);

        struct Node* temp = graph->adjacencyList[currentNode->data];
        while (temp) {
            int adjNode = temp->data;
            if (graph->visited[adjNode] == 0) {
                stack[++top] = createNode(adjNode);
                graph->visited[adjNode] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    int numNodes, numEdges;
    int src, dest;
    int i;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);

    for (i = 0; i < numNodes; i++) {
        graph->adjacencyList[i] = NULL;
        graph->visited[i] = 0;
    }

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    for (i = 0; i < numEdges; i++) {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startNode;
    printf("Enter the starting node for DFS traversal: ");
    scanf("%d", &startNode);

    dfs(graph, startNode);

    return 0;
}
