#include <stdio.h>
#include <stdlib.h>

int fib(int n);
int** multiply(int** mat1, int** mat2);
int** power(int** mat, int p);

int fib(int n) {
    int **f = (int**)malloc(sizeof(int*) * 2);
    f[0] = (int*)malloc(sizeof(int) * 2);
    f[1] = (int*)malloc(sizeof(int) * 2);
    f[0][0] = 0;
    f[0][1] = 1;
    f[1][0] = 1;
    f[1][1] = 1;

    if (n == 0)
        return 0;

    f = power(f, n);

    return f[0][1];
}

int** multiply(int** mat1, int** mat2) {
    int** ret = (int**)malloc(sizeof(int*) * 2);
    ret[0] = (int*)malloc(sizeof(int) * 2);
    ret[1] = (int*)malloc(sizeof(int) * 2);
    ret[0][0] = mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0];
    ret[0][1] = mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1];
    ret[1][0] = mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0];
    ret[1][1] = mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1];
    return ret;
}

int** power(int** mat, int p) {
    if (p == 1)
        return mat;

    int** temp = (int**)malloc(sizeof(int*) * 2);
    temp[0] = (int*)malloc(sizeof(int) * 2);
    temp[1] = (int*)malloc(sizeof(int) * 2);
    temp = power(mat, p / 2);
    if (p % 2 == 0)
        return multiply(temp, temp);
    else
        return multiply(multiply(temp, temp), mat);
}

int main() {
    int a;
    scanf("%d", &a);
    printf("%d", fib(a));
}
