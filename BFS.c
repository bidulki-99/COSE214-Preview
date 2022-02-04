int graph[1000][1000];
int visited[1000];
int queue[1000];

void BFS(int cur, int n) {
    int front = 0, rear = 0, pop, i;

    printf("%d ", cur);
    queue[rear++] = cur;
    visited[cur] = 1;

    while (front < rear) {
        pop = queue[front++];

        for (int i = 1; i <= n; i++) {
            if (graph[pop][i] == 1 && visited[i] == 0) {
                printf("%d ", i);
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}
