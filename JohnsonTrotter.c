#define SWAP(a, b, type) do { \
    type temp = a;  \
    a = b;          \
    b = temp;       \
} while (0)

void JohnsonTrotter(int n) {
    int num[1000] = {0, };
    int arrow[1000] = {0, };
    for (int i = 1; i <= n; i++) {
        num[i] = i;
        arrow[i] = -1;
    }
    num[0] = 9999;

    int mobile, index;
    while (mobile) {
        mobile = 0;
        index = 0;
        for (int i = 1; i <= n; i++) {
            if (num[i + arrow[i]] < num[i] && mobile < num[i] && num[i + arrow[i]] != 0) {
                mobile = num[i];
                index = i;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (num[i] > mobile)
                arrow[i] = arrow[i] == 1 ? -1 : 1;
        }

        for (int i = 1; i <= n; i++)
            printf("%d", num[i]);
        printf(" ");

        int change_arrow = index + arrow[index];
        SWAP(num[index], num[index + arrow[index]], int);
        SWAP(arrow[index], arrow[change_arrow], int);
    }
}
