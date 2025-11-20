#include <stdio.h>

int a, b, c;

int main() {
    while(scanf("%d%d%d", &a, &b, &c) != EOF)
    {
        printf("%d %d %d\n", a, b, c);
    }
    
    return 0;
}