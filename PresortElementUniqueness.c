int PresortElementUniqueness(int a[], int n) {
    Sort(a, 0, n-1);
    for (int i = 0; i < n-1; i++)
        if (a[i] == a[i+1])
            return 0;
    return 1;
}
