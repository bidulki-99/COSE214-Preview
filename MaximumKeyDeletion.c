int MaximumKeyDeletion(int h[], int n) {
    h[1] = h[n];
    HeapBottomUp(h, n--);
    return n;
}
