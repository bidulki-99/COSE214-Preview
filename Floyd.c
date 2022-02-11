#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int d[10][10];

void Floyd(int w[][10], int n) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = w[i][j];

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = MIN(d[i][j], d[i][k] + d[k][j]);
}
