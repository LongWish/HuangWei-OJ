#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int t, n;
int min, max = -1, tmp, num[101000];
char flag[101000] = {0};

int main() {
    scanf("%d", &t);
    for(int times = 0;times < t;times++){
        scanf("%d", &n);
        if(n == 3)  printf("-1\n");
        else if(n%2 == 0){
            printf("1");
            for(int i = n - 1; i>=2;i--){
                printf(" %d", i);
            }
            printf(" %d\n", n);
        }
        else{
            printf("1");
            for(int i = n - 1; i>=(n+1)/2 + 1;i--){
                printf(" %d", i);
            }
            for(int i = (n+1)/2 - 1; i>=2;i--){
                printf(" %d", i);
            }
            printf(" %d", (n+1)/2);
            printf(" %d\n", n);
        }

    }

    return 0;
}