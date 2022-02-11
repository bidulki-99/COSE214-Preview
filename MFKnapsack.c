#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int weights[100];
int values[100];
int dp[100][100];

int MFKnapsack(int i, int j) {
    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++)
            dp[i][j] = i+j ? -1 : 0;
    int value;
    
    if (dp[i][j] < 0) {
        if (j < weights[i])
            value = MFKnapsack(i-1, j);
        else
            value = MAX(MFKnapsack(i-1, j), values[i] + MFKnapsack(i-1, j - weights[i]));
        dp[i][j] = value;
    }
    return dp[i][j];
}
