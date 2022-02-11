int r[10][10][10];

void Warshall(int a[][10], int n) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            r[0][i][j] = a[i][j];

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                r[k][i][j] = r[k-1][i][j] | (r[k-1][i][j] & r[k-1][k][j]);
}
