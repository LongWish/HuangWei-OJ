#include <stdio.h>
#include <string.h>

typedef long long ll;

int prime[0xffff] = {2L, 3L};   
int top = 2, n;

int is_prime(int num){
    // printf("check\n");
    if(prime[top - 1] >= num){
        for(int i = top - 1; i >= 0; i--){
            if(prime[i] == num)     return 1;
        }
        return 0;
    }
    else{
        int flag;
        for(int i = prime[top-1]; i <= num; i+=2){
            flag = 1;
            for(int j=0; j < top; j++){
                if(prime[j] * prime[j] > i) break;
                if(i % prime[j] == 0){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                prime[top] = i;
                top++;
            }
        }

        for(int i = top - 1; i >= 0; i--){
            if(prime[i] == num)     return 1;
        }
        return 0;
    }
}

int main() {
    while(scanf("%d", &n) != EOF)
    {
        if(is_prime(n)){
            printf("%d=%d\n", n, n);
        }
        else{
            printf("%d=", n);
            int i = 0, first = 1;
            while (i < top)
            {
                int right = 0;
                if(n % prime[i] == 0){
                    printf(first?"%d":"*%d", prime[i]);
                    first = 0;
                    n /= prime[i];
                    right = 1;
                }
                i = right ? i : i+1;
            }
            printf("\n");
        }
    }
    

    return 0;
}