void HeapBottomUp(int h[], int n) {
    for (int i = n/2; i >= 1; i--) {
        int k = i;
        int v = h[k];
        int heap = 0;

        while (heap == 0 && 2*k <= n) {
            int j = 2*k;
            if (j < n)
                if (h[j] < h[j+1])
                    j++;

            if (v >= h[j])
                heap = 1;
            else {
                h[k] = h[j];
                k = j;
            }

            h[k] = v;
        }
    }
}
