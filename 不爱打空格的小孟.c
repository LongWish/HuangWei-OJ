#include <stdio.h>

int a, b, c;

int main() {
    while(scanf("%3d%2d%5d", &a, &b, &c) != EOF)
    {
        printf("%03d %02d %05d\n", a, b, c);
    }
    
    return 0;
}