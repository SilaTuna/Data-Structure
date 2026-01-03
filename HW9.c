#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n;

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int start) {
    int v;
    for (int i = 0; i < n; i++) visited[i] = 0;

    printf("%d ", start);
    visited[start] = 1;
    enqueue(start);

    while (front <= rear && front != -1) {
        v = dequeue();
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    int edge, u, v;

    printf("Dugum sayisi: ");
    scanf("%d", &n);

    printf("Kenar sayisi: ");
    scanf("%d", &edge);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Kenarlari girin (u v):\n");
    for (int i = 0; i < edge; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("\nDFS: ");
    for (int i = 0; i < n; i++) visited[i] = 0;
    DFS(0);

    printf("\nBFS: ");
    BFS(0);

    return 0;
}
