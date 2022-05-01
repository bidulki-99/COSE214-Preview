#include <stdio.h>
#include <math.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define SWAP(a, b, type) do { \
    type temp = a;  \
    a = b;          \
    b = temp;       \
} while (0)

typedef struct point
{
    double x;
    double y;
} Point;


void copy(Point a[], int s1, int e1, Point b[], int s2, int e2) {
    while (s1 < e1 && s2 < e2) {
        b[s2].x = a[s1].x;
        b[s2++].y = a[s1++].y;
    }
}

double EfficientClosestPair(Point p[], Point q[], int n) {
    if (n <= 3) {
        double d = 1e+10;
        for (int i = 0; i < n-1; i++)
            for (int j = i+1; j < n; j++)
                d = MIN(d, sqrt(pow((p[i].x - p[j].x), 2) + pow((p[i].y - p[j].y), 2)));
        return d;
    }

    Point p_l[1000], q_l[1000], p_r[1000], q_r[1000], s[1000];
    double d_l, d_r;
    copy(p, 0, ceil(n/2), p_l, 0, ceil(n/2));
    copy(q, 0, ceil(n/2), q_l, 0, ceil(n/2));
    copy(p, ceil(n/2), n, p_r, 0, n/2);
    copy(q, ceil(n/2), n, q_r, 0, n/2);
    d_l = EfficientClosestPair(p_l, q_l, ceil(n/2));
    d_r = EfficientClosestPair(p_r, q_r, n/2);
    double d = MIN(d_l, d_r);
    double m = p[ceil(n/2) - 1].x;
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (abs(q[i].x - m) < d) {
            s[num].x = q[i].x;
            s[num++].x = q[i].y;
        }
    }

    double dminsq = pow(d, 2);
    for (int i = 0; i <= num - 2; i++) {
        int k = i+1;
        while (k <= num - 1 && pow((s[k].y - s[i].y), 2) < dminsq) {
            dminsq = MIN(pow((s[k].x - s[i].x), 2) + pow((s[k].y - s[i].y), 2), dminsq);
            k++;
        }
    }

    return sqrt(dminsq);
}

int HoarePartition_x(Point a[], int l, int r) {
    double p = a[l].x;
    int i = l, j = r+1;
    do {
        do i++; while (a[i].x < p);
        do j--; while (a[j].x > p);
        SWAP(a[i].x, a[j].x, double);
        SWAP(a[i].y, a[j].y, double);
    } while (i < j);
    SWAP(a[i].x, a[j].x, double);
    SWAP(a[i].y, a[j].y, double);
    SWAP(a[l].x, a[j].x, double);
    SWAP(a[l].y, a[j].y, double);
    return j;
}

void QuickSort_x(Point a[], int l, int r) {
    if (l < r) {
        int s = HoarePartition_x(a, l, r);
        QuickSort_x(a, l, s-1);
        QuickSort_x(a, s+1, r);
    }
}

int HoarePartition_y(Point a[], int l, int r) {
    double p = a[l].y;
    int i = l, j = r+1;
    do {
        do i++; while (a[i].y < p);
        do j--; while (a[j].y > p);
        SWAP(a[i].x, a[j].x, double);
        SWAP(a[i].y, a[j].y, double);
    } while (i < j);
    SWAP(a[i].x, a[j].x, double);
    SWAP(a[i].y, a[j].y, double);
    SWAP(a[l].x, a[j].x, double);
    SWAP(a[l].y, a[j].y, double);
    return j;
}

void QuickSort_y(Point a[], int l, int r) {
    if (l < r) {
        int s = HoarePartition_y(a, l, r);
        QuickSort_y(a, l, s-1);
        QuickSort_y(a, s+1, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Point p[1000], q[1000];
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &p[i].x, &p[i].y);
    }
    copy(p, 0, n, q, 0, n);

    QuickSort_x(p, 0, n-1);
    QuickSort_y(q, 0, n-1);
    printf("%lf", EfficientClosestPair(p, q, n));
}
