int MaxElement(int a[], int n) {
    int maxval = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > maxval)
            maxval = a[i];
    return maxval;
}
