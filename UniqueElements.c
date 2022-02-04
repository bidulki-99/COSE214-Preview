void UniqueElements(int a[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (a[i] == a[j]) {
                printf("False");
                return;
            }
    printf("True");
}
