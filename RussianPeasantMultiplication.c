int RussianPeasantMultiplication(int n, int m) {
    int result = 0;
    while (n) {
        if (n % 2 == 1)
            result += m;
        n /= 2;
        m *= 2;
    }
    return result;
}
