int RussianPeasantMultiplication(int n, int m) {
    int result = 0;
    while (n) {
        if (n & 1)
            result += m;
        n >>= 1;
        m <<= 1;
    }
    return result;
}
