#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;
ll l, s, t, m, dp[150000], rock[101], ans = 0
, flag[150000] = {0}, x;

int cmp(const void* p1, const void* p2){
    ll a = *(ll*)p1;
    ll b = *(ll*)p2;
    if(a < b) return -1;
    if(a > b) return 1;
    return 0;
}

int main() {
    memset(dp, 0x3f, sizeof(dp));
    scanf("%lld", &l);
    scanf("%lld%lld%lld", &s, &t, &m);
    for(ll i = 0; i < m; i++){
        scanf("%lld", &rock[i]);
    }

    if(m == 0){
        printf("0");
        return 0;
    }

    if(s == t){
        for(ll i = 0; i < m; i++){
            if(rock[i] % s == 0)    ans++;
        }
        printf("%lld", ans);
        return 0;
    }
    qsort(rock, m, sizeof(rock[0]), cmp);

    ll base = 72;
    if(rock[0] > base){
        rock[0] = base;
    }

    ll tmp = l - rock[m-1];
    l = rock[0];
    flag[l] = 1;
    for(ll i = 0; i < m - 1; i++){
        if(rock[i+1] - rock[i] > base)      x = base;
        else                                x = rock[i+1] - rock[i];
        l += x;
        flag[l] = 1;
        // printf("%lld ", rock[i]);
    }
    if(tmp > base) tmp = base;
    l += tmp;
    flag[l] = 1;
    // printf("%lld = %lld", l, rock[0]);

    dp[0] = 0;
    // for(ll i = s; i <= t; i++){
    //     dp[i] = flag[i] ? 1 : 0;
    // }
    // printf("%lld ", flag[2]);
    for(ll i = 1; i <= l + t; i++){
        ll min = 200;
        for(ll j = s; j <= t; j++){
            if(i - j >= 0)  min = dp[i - j] < min ? dp[i - j] : min;
        }
        dp[i] = flag[i] ? min + 1 : min;
        // if(flag[i])     printf("%lld ", i);
        // printf("%lld:%lld -> ", i, dp[i]);
    }
    ans = 200;
    // printf("%lld ", l);
    for(ll i = l; i <= l + t - 1; i++){
        ans = ans > dp[i] ? dp[i] : ans;
    }
    printf("%lld", ans);

    return 0;
}