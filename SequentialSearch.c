int SequentialSearch(int a[], int n, int k) {
    int i = 0;
    while (i < n && a[i] != k)
        i++;
    return i < n ? i : -1;
}
