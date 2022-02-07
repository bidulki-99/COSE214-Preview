int PresortMode(int a[], int n) {
    Sort(a, 0, n-1);
    int i = 0, modefrequency = 0, modevalue;
    while (i <= n-1) {
        int runlength = 1, runvalue = a[i];
        while (i + runlength <= n-1 && a[i + runlength] == runvalue)
            runlength++;
        if (runlength > modefrequency) {
            modefrequency = runlength;
            modevalue = runvalue;
        }
        i += runlength;
    }
    return modevalue;
}
