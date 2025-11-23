#include <stdio.h>

typedef long long ll;
ll num;
int is_negative, top;
char deminal[10000];


int main() {
    while(scanf("%lld", &num) != EOF)
    {
        if(num == 0){
            printf("0\n");
            continue;
        }
        top = 0;
        while(num != 0){
            ll tmp = num / -2, remainder = num % -2;
            if(remainder < 0)   tmp++;
            if(remainder != 0)  deminal[top++] = 1;
            else                deminal[top++] = 0;
            num = tmp;
        }
        for(int i = top - 1; i >= 0; i--){
            printf("%d", deminal[i]);
        }
        printf("\n");
    }
    
    return 0;
}