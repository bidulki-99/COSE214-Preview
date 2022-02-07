void copy(int a[], int s1, int e1, int b[], int s2, int e2) {
    while (s1 < e1 && s2 < e2)
        b[s2++] = a[s1++];
}

void Merge(int b[], int p, int c[], int q, int a[]) {
    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
        if (b[i] <= c[j])
            a[k++] = b[i++];
        else
            a[k++] = c[j++];
    }

    if (i == p)
        copy(c, j, q, a, k, p+q);
    else
        copy(b, i, p, a, k, p+q);
}

void MergeSort(int a[], int n) {
    int b[1000], c[1000];

    if (n > 1) {
        copy(a, 0, n/2, b, 0, n/2);
        copy(a, n/2, n, c, 0, ceil(n/2));
        MergeSort(b, n/2);
        MergeSort(c, ceil(n/2));
        Merge(b, n/2, c, ceil(n/2), a);
    }
}
