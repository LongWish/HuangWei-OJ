#include <stdio.h>
#include <string.h>

int dp[30] = {1, 1, 2, 4}, n;

int main() {
    while(scanf("%d", &n) != EOF)
    {
        for(int i=4; i<=n; i++){
            if(dp[i] == 0){
                dp[i] = dp[i-1] + dp[i-2] +dp[i-3];
            }
        }
        printf("%d\n", dp[n]);
    }
    
    return 0;
}