// compute factorial function: F(n) = n!
int F(int n) {
    return n == 0 ? 1 : F(n-1) * n;
}
