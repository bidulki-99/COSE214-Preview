int BinRec(int n) {
    return n == 1 ? 1 : BinRec(n/2) + 1;
}
