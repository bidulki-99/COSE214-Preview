int BruteForceStringMatch(char t[], char p[], int n, int m) {
    for (int i = 0; i <= n-m; i++) {
        int j = 0;
        while (j < m && p[j] == t[i+j])
            j++;
        if (j == m)
            return i;
    }
    return -1;
}00
