#include <string.h>

int LeftRightBinaryExponentiation(int a, char b[]) {
    int len = strlen(b);
    int product = a;
    for (int i = 1; i < len; i++) {
        product *= product;
        if (b[i] == '1')
            product *= a;
    }
    return product;
}
