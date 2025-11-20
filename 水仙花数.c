#include <stdio.h>

int flower[1000], m, n, count = 0, tmp;

int cube(int a){
    return a*a*a;
}

int main() {
    int num;
    for(int i=100; i<=999; i++){
        tmp = 0;
        tmp += cube(i % 10);
        tmp += cube(i / 10 % 10);
        tmp += cube(i / 100);
        if(tmp == i){
            flower[count] = i;
            count++;
        }
    }
    while(scanf("%d%d",&m, &n) != EOF)
    {
        num = 0;
        for(int i=0; i<count; i++){
            if(flower[i] >= m && flower[i] <= n){
                if(num == 0){
                    printf("%d", flower[i]);
                    num++;
                }
                else{
                    printf(" %d", flower[i]);
                    num++;
                }
            }
        }
        if(num == 0){
            printf("no");
        }
        printf("\n");
    }
    
    return 0;
}