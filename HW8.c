#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void DFS(struct Graph* graph, int vertex) {
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("V%d ", vertex + 1);

    while (temp != NULL) {
        int connectedVertex = temp->dest;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

void findConnectedComponents(struct Graph* graph) {
    int componentCount = 0;
    printf("\n--- Bulunan Bilesenler (Clusters) ---\n");

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->visited[i] == 0) {
            componentCount++;
            printf("Cluster %d: { ", componentCount);
            
            DFS(graph, i);
            
            printf("}\n");
        }
    }
    printf("\nToplam %d adet bagli bilesen bulundu.\n", componentCount);
}

int main() {
    struct Graph* graph = createGraph(9);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    addEdge(graph, 5, 6);
    addEdge(graph, 5, 8);
    addEdge(graph, 6, 7);
    addEdge(graph, 6, 8);

    findConnectedComponents(graph);

    return 0;
}
