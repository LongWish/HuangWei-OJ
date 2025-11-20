#include <stdio.h>

typedef long long ll;
ll ans[15000], n;

int main() {
    ans[0] = 0, ans[1] = 1;
    for(int i = 2; i<15000; i++){
        ans[i] = (ans[i-1]+ans[i-2]) % 10000;
    }
    while(scanf("%lld", &n) != EOF && n != -1)
    {
        printf("%lld\n", ans[n%15000]);
    }
    
    return 0;
}