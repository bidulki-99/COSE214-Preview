int RobotCoinCollection(int c[][100], int n, int m) {
    int dp[100][100];
    dp[1][1] = c[1][1];
    for (int j = 2; j <= m; j++)
        dp[1][j] = dp[1][j-1] + c[1][j];

    for (int i = 2; i <= n; i++) {
        dp[i][1] = dp[i-1][1] + c[i][1];
        for (int j = 2; j <= m; j++)
            dp[i][j] = MAX(dp[i-1][j], dp[i][j-1]) + c[i][j];
    }
    return dp[n][m];
}
