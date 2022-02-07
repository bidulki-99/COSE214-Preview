#include <math.h>
#define SWAP(a, b, type) do { \
    type temp = a;  \
    a = b;          \
    b = temp;       \
} while (0)

void BetterForwardElimination(double a[][100], double b[], int n) {
    for (int i = 1; i <= n; i++)
        a[i][n+1] = b[i];

    for (int i = 1; i <= n-1; i++) {
        int pivotrow = i;

        for (int j = 1; j <= n; j++)
            if (abs(a[j][i]) > abs(a[pivotrow][i]))
                pivotrow = j;

        for (int k = i; k <= n+1; k++)
            SWAP(a[i][k], a[pivotrow][k], double);

        for (int j = i+1; j <= n; j++) {
            double temp = a[j][i] / a[i][i];
            for (int k = i; k <= n+1; k++)
                a[j][k] -= a[i][k] * temp;
        }
    }
}
