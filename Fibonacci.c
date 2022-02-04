int FibonacciRecursion(int n) {
    return n <= 1 ? n : FibonacciRecursion(n-1) + FibonacciRecursion(n-2);
}

int FibonacciIteration(int n) {
    int F[1000];
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i <= n; i++)
        F[i] = F[i-1] + F[i-2];
    return F[n];
}
