void InsertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int v = a[i];
        int j = i-1;
        while (j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            j--;
        }
    a[j+1] = v;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
