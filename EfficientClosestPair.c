#include <math.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

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

    Point p_l[1000], q_l[1000], p_r[1000], q_r[1000];
    double d_l, d_r;
    copy(p, 0, ceil(n/2), p_l, 0, ceil(n/2));
    copy(q, 0, ceil(n/2), q_l, 0, ceil(n/2));
    copy(p, ceil(n/2), n, p_r, 0, n/2);
    copy(q, ceil(n/2), n, q_r, 0, n/2);
    d_l = EfficientClosestPair(p_l, q_l, ceil(n/2));
    d_r = EfficientClosestPair(p_r, q_r, n/2);
    double d = MIN(d_l, d_r);
    double m = p[int(ceil(n/2)) - 1].x;

    double dminsq = pow(d, 2);
    for (int i = 0; i < n-1; i++) {
        int k = i+1;
        while (k <= n-1 && pow((q[k].y - q[i].y), 2) < dminsq) {
            dminsq = MIN(pow((q[k].x - q[i].x), 2) + pow((q[k].y - q[i].y), 2), dminsq);
            k++;
        }
    }

    return sqrt(dminsq);
}

// 정렬은 O(nlogn) 알고리즘으로 해야 효율 향상이 있음
// sort하는 방법이 중요한 것이 아니기 때문에 단순히 가장 간단하고 빠르게 생각할 수 있는 방법을 임의로 사용한 것
void sort_x(Point p[], int n) {
    for (int i = 0; i <= n-2; i++) {
        for (int j = 0; j <= n-2-i; j++) {
            if (p[j+1].x < p[j].x) {
                double temp1 = p[j].x;
                p[j].x = p[j+1].x;
                p[j+1].x = temp1;

                double temp2 = p[j].y;
                p[j].y = p[j+1].y;
                p[j+1].y = temp2;
            }
        }
    }
}

void sort_y(Point p[], int n) {
    for (int i = 0; i <= n-2; i++) {
        for (int j = 0; j <= n-2-i; j++) {
            if (p[j+1].y < p[j].y) {
                double temp1 = p[j].x;
                p[j].x = p[j+1].x;
                p[j+1].x = temp1;

                double temp2 = p[j].y;
                p[j].y = p[j+1].y;
                p[j+1].y = temp2;
            }
        }
    }
}
