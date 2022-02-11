int* ShiftTable(char p[], int m) {
    static int table[1000];
    for (int i = 'a'; i <= 'z'; i++)
        table[i] = m;
    for (int i = 0; i < m-1; i++)
        table[p[i]] = m-1-i;
    return table;
}

int HorspoolMatching(char p[], int m, char t[], int n) {
    int* table;
    table = ShiftTable(p, m);
    int i = m-1;
    while (i <= n-1) {
        int k = 0;
        while (k <= m-1 && p[m-1-k] == t[i-k])
            k++;
        if (k == m)
            return i-m+1;
        else
            i += table[t[i]];
    }
    return -1;
}
