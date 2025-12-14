#include <stdio.h>
#include <string.h>

#define SIZE 50010

long long n, k, ans;

int main() {
    scanf("%lld%lld", &n, &k);

    ans = ((n/2) % k == 0)?(n/2) / k:(n/2) / k + 1;
    
    printf("%lld", ans);

    return 0;
}