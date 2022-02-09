int Horner(int a[], int n, int x) {
    int p = a[n];
    for (int i = n-1; i >= 0; i--)
        p = x*p + a[i];
    return p;
}
