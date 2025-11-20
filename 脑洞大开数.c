#include <stdio.h>

char num[300] = {0};
int n;

int main() {
    while(scanf("%d %s", &n, num) != EOF)
    {
        for(int i=0;i < n; i++){
            num[i] -= '0';
        }
        num[0]++;
        for(int i=0; i<n; i++){
            if(num[i]>9){
                num[i+1] += num[i] / 10;
                num[i] %= 10;
            }
        }
        if(num[n] > 0)   n++;
        for(int i=0; i < n; i++){
            printf("%d", num[i]);
        }
        printf("\n");

        for(int i = 0; i<300; i++){
            num[i] = 0;
        }
    }
    
    return 0;
}