#include <stdio.h>
#include <string.h>
#define SIZE 110000

int n, mid, sum[SIZE], tmp, hash[2 * SIZE], met_mid = 0;
long long ans;

int main() {
    while(scanf("%d%d", &n, &mid) != EOF)
    {
        memset(hash, 0, sizeof(hash));
        sum[0] = 0, ans = 0, met_mid = 0, hash[n] = 1;
        for(int i = 1; i <= n; i++){
            scanf("%d", &tmp);
            if(met_mid == 0){
                if(tmp > mid)       sum[i] = sum[i-1] + 1;
                else if(tmp < mid)  sum[i] = sum[i-1] - 1;
                else{
                    met_mid = 1;
                    sum[i] = sum[i-1];
                    hash[n+sum[i]]--;
                }
                hash[n+sum[i]]++;
            }
            if(met_mid){
                if(tmp > mid)       sum[i] = sum[i-1] + 1;
                else if(tmp < mid)  sum[i] = sum[i-1] - 1;
                
                ans += hash[n+sum[i]];
            }
        }

        printf("%lld\n", ans);
    }
    
    return 0;
}