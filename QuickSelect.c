int QuickSelect(int a[], int l, int r, int k) {
    int s = LomutoPartition(a, l, r);
    if (s == k-1)
        return a[s];
    else if (s > l+k-1)
        QuickSelect(a, l, s-1, k);
    else
        QuickSelect(a, s+1, r, k);
}
