void ForwardElimination(double a[][100], double b[], int n) {
    for (int i = 1; i <= n; i++)
        a[i][n+1] = b[i];

    for (int i = 1; i <= n-1; i++)
        for (int j = i+1; j <= n; j++)
            for (int k = i; k <= n+1; k++)
                a[j][k] -= a[i][k] * a[j][i] / a[i][i];
}
