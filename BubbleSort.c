void BubbleSort(int a[], int n) {
    for (int i = 0; i <= n-2; i++) {
        for (int j = 0; j <= n-2-i; j++) {
            if (a[j+1] < a[j]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
