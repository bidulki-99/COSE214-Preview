#include <string.h>

int RightLeftBinaryExponentiation(int a, char b[]) {
    int len = strlen(b);
    int term = a;
    int product = b[len-1] == '1' ? a : 1;
    for (int i = len-2; i >= 0; i--) {
        term *= term;
        if (b[i] == '1')
            product *= term;
    }
    return product;
}
