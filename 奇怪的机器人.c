#include <stdio.h>

int a, b;
long long fact[21] = {1, 1};

long long factorial(int num){
    if(fact[num] != 0)  return fact[num];
    else                fact[num] = factorial(num - 1) * num;
    return fact[num];
}

int main() {
    // printf("%d", factorial(10));
    while(scanf("%d%d", &a, &b) != EOF)
    {
        // for(int i = 0; i<20; i++)   printf("%d ", fact[i]);
        long long ans = factorial(a+b-2) / factorial(a-1) / factorial(b-1);
        printf("%lld\n", ans);
    }
    
    return 0;
}