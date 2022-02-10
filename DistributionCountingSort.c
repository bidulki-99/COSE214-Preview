int d[1000];

int* DistributionCountingSort(int a[], int n, int l, int u) {
    static int s[1000];
    for (int i = 0; i < n; i++)
        d[a[i] - l]++;
    for (int i = 1; i <= u-l; i++)
        d[i] += d[i-1];
    for (int i = n-1; i >= 0; i--) {
        int j = a[i] - l;
        s[d[j] - 1] = a[i];
        d[j]--;
    }
    return s;
}
