void HeapSort(int h[], int n) {
    int a[1000];
    int k = n;
    HeapBottomUp(h, n);
    while (n) {
        a[n] = h[1];
        n = MaximumKeyDeletion(h, n);
    }

    for (int i = 1; i <= k; i++)
        printf("%d ", a[i]);
}
