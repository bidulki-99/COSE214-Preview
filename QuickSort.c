#define SWAP(a, b, type) do { \
    type temp = a;  \
    a = b;          \
    b = temp;       \
} while (0)

int HoarePartition(int a[], int l, int r) {
    int p = a[l];
    int i = l, j = r+1;
    do {
        do i++; while (a[i] < p);
        do j--; while (a[j] > p);
        SWAP(a[i], a[j], int);
    } while (i < j);
    SWAP(a[i], a[j], int);
    SWAP(a[l], a[j], int);
    return j;
}

void QuickSort(int a[], int l, int r) {
    if (l < r) {
        int s = HoarePartition(a, l, r);
        QuickSort(a, l, s-1);
        QuickSort(a, s+1, r);
    }
}
