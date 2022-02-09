int count[1000];

int* ComparisonCountingSort(int a[], int n) {
    static int s[1000];
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (a[i] < a[j])
                count[j]++;
            else
                count[i]++;
    for (int i = 0; i < n; i++)
        s[count[i]] = a[i];
    return s;
}
