#include <stdio.h>
#include <stdbool.h>

#define V 6

void findCluster(int graph[V][V], int v, bool visited[], int clusterID) {
    visited[v] = true;
    printf("%d ", v);

    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            findCluster(graph, i, visited, clusterID);
        }
    }
}

void extractClusters(int graph[V][V]) {
    bool visited[V];
    
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    int clusterCount = 0;
    printf("Graf üzerindeki kümeler:\n");

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            clusterCount++;
            printf("Küme %d: ", clusterCount);
            findCluster(graph, i, visited, clusterCount);
            printf("\n");
        }
    }
    printf("\nToplam bulunan küme sayısı: %d\n", clusterCount);
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    extractClusters(graph);

    return 0;
}
