int Binary(int n) {
    int count = 1;
    while (n > 1) {
        count++;
        n /= 2;
    }
    return count;
}
