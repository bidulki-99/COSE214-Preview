int graph[1000][1000];
int visited[1000];

void DFS(int cur, int n) {
    int i;
    visited[cur] = 1;
    for (int i = 1; i <= n; i++) {
        if (graph[cur][i] == 1 && visited[i] == 0) {
            printf("%d ", i);
            DFS(i, n);
        }
    }
}
