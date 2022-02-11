#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int ChangeMaking(int d[], int m, int n) {
    int dp[1000];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int temp = 2147483647;
        int j = 1;
        while (j <= m && i >= d[j]) {
            temp = MIN(dp[i - d[j]], temp);
            j++;
        }
        dp[i] = temp + 1;
    }
    return dp[n];
}
