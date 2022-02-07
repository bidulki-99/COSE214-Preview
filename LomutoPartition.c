#define SWAP(a, b, type) do { \
    type temp = a;  \
    a = b;          \
    b = temp;       \
} while (0)

int LomutoPartition(int a[], int l, int r) {
    int p = a[l];
    int s = l;
    for (int i = l+1; i <= r; i++) {
        if (a[i] < p) {
            s++;
            SWAP(a[s], a[i], int);
        }
    }
    SWAP(a[l], a[s], int);
    return s;
}
