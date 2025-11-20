#include <stdio.h>
#define int long long

int n, ans = 0;
int tmp = 1;

signed main() {
    // freopen("out.txt", "w", stdout);
    if(scanf("%lld", &n) != EOF)
    {
        for(int i = 1; i <= n; i++){
            tmp = (tmp * 2) % 7;
            if(tmp == ((i * i) % 7)){
                ans++;
                // printf("%lld\n", i);
            }
            
        }
        printf("%lld", ans);
    }
    return 0;
}