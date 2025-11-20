#include <stdio.h>

typedef unsigned long long ULL;
ULL exel[102]={0};
int top=0;

void pop(ULL num){
    exel[top] = num;
    // printf("%lld ", exel[top]);
    top++;
}

int main(){
    ULL a, b;
    int c;
    while(scanf("%lld%lld%d", &a, &b, &c) != EOF)
    {
        top = 0;
        pop(a / b);
    
        for(int i=1; i<=c; i++){
            a %= b;
            a *= 10;
            pop(a / b);
        }
        
        a %= b;
        a *= 10;
        pop(a / b);

        if(exel[top-1]>=5)
            exel[top-2] += 1;
        
        for(int i=top-2; i>0; i--){
            if(exel[i] >= 10){
                exel[i-1] += 1;
                exel[i] -= 10;
            }
        }
        // printf("check\n");
        printf("%lld", exel[0]);
        if(c>0){
            printf(".");
            for(int i=1;i<top-1;i++)
                printf("%lld", exel[i]);
        }
        printf("\n");
    }
    
    return 0;
}