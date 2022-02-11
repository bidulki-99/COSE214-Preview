int r[100][100];

double OptimalBST(double p[], int n) {
    double dp[100][100];
    for (int i = 1; i <= n; i++) {
        dp[i][i-1] = 0;
        dp[i][i] = p[i];
        r[i][i] = i;
    }
    dp[n+1][n] = 0;

    int j, kmin = 0;
    double minval, sum = 0;
    for (int d = 1; d <= n-1; d++)
        for (int i = 1; i <= n-d; i++) {
            j = i+d;
            minval = 999999999;
            for (int k = i; k <= j; k++)
                if (dp[i][k-1] + dp[k+1][j] < minval) {
                    minval = dp[i][k-1] + dp[k+1][j];
                    kmin = k;
                }
            r[i][j] = kmin;
            sum = p[i];
            for (int s = i+1; s <= j; s++)
                sum += p[s];
            dp[i][j] = minval + sum;
        }
    return dp[1][n];
}
