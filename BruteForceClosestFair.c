#define MIN(a, b) (((a) < (b)) ? (a) : (b))

typedef struct point
{
    double x;
    double y;
} Point;


double BruteForceClosestFair(Point p[], int n) {
    double d = 1e+10;
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            d = MIN(d, sqrt(pow((p[i].x - p[j].x), 2) + pow((p[i].y - p[j].y), 2)));
    return d;
}
