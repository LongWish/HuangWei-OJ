#include <stdio.h>
#include <string.h>

#define SIZE 9037 + 210 * 346

typedef long long ll;

ll prime[SIZE] = {2L, 3};   

ll a, d, n, top = 2;

int is_prime(ll num){
    // printf("check\n");
    if(prime[top - 1] >= num){
        for(int i = top - 1; i >= 0; i--){
            if(prime[i] == num)     return 1;
        }
        return 0;
    }
    else{
        int flag;
        for(ll i = prime[top-1]; i <= num; i+=2){
            flag = 1;
            // printf("check: %lld\n", i);
            for(int j=0; j < top; j++){
                if(prime[j] * prime[j] > i) break;
                if(i % prime[j] == 0){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                // printf("check: %lld\n", i);
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
    ll i, count;
    while(scanf("%lld%lld%lld", &a, &d, &n) != EOF)
    {
        i = 0, count = 0;
        for(; count < n; i++){
            // printf("%lld\n", a + i * d);
            if(is_prime(a + i * d)){
                count++;
                // printf("%lld    %lld\n", count, a + i * d);
            }
        }
        i--;
        printf("%lld\n", a + i * d);
    }
    
    return 0;
}