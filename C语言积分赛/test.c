#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int times = 100000;

int main() {
    // freopen("in.txt", "r", stdin);
    freopen("in.txt", "w", stdout);
    printf("%d\n", times);
    for(int i=0 ;i<times; i++){
        printf("3\n");
        printf("2 6 4\n");
        printf("4 5 7\n");
        printf("9 7 6\n");
    }
    
    return 0;
}