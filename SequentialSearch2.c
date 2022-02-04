int SequentialSearch2(int a[], int k, int n) {
    a[n] = k;
    int i = 0;
    while (a[i] != k)
        i++;
    return i < n ? i : -1;
}
