#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int CoinRow(int c[], int n) {
    int dp[1000];
    dp[0] = 0;
    dp[1] = c[1];

    for (int i = 2; i <= n; i++)
        dp[i] = MAX(c[i] + dp[i-2], dp[i-1]);
    return dp[n];
}
