void Merge(int b[], int p, int c[], int q, int a[]) {
    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
        if (b[i] <= c[j])
            a[k++] = b[i++];
        else
            a[k++] = c[j++];
    }

    if (i == p)
        while (j < q && k < p+q)
            a[k++] = c[j++];
    else
        while (i < p && k < p+q)
            a[k++] = b[i++];
}

void MergeSort(int a[], int n) {
    int b[1000], c[1000];

    if (n > 1) {
        int i = 0, j = 0, k = 0;
        while (i < n/2 && k < n/2)
            b[k++] = a[i++];
        while (i < n && j < ceil(n/2.0))
            c[j++] = a[i++];
        MergeSort(b, n/2);
        MergeSort(c, ceil(n/2.0));
        Merge(b, n/2, c, ceil(n/2.0), a);
    }
}
