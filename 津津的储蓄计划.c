#include <stdio.h>

int main() {
    int n = 0, s = 0, y = 0;
    for (int i = 1; i <= 12; i++) {
        scanf("%d", &y);
        n = n + 300 - y;
        if (n < 0) {
            printf("-%d", i);
            return 0;
        }
        while (n >= 100) {
            n -= 100;
            s += 100;
        }
    }
    printf("%d", s * 6 / 5 + n);
    return 0;
}