#include <stdio.h>
#define SIZE 5001

bool flag[SIZE][SIZE] = {0};
int l,w,n, x, y, dp[SIZE][SIZE] = {0}, ans=-1;

int main() {
    // printf("%lld\n", sizeof(dp)/1024/1024);
    scanf("%d%d", &l, &w);
    l++, w++;
    scanf("%d", &n);
    for(int i=0; i<n;i++){
        scanf("%d%d", &x, &y);
        flag[x][y]=1;
    }
    for(int i=1; i<=l; i++){
        for(int j=1; j<=w;j++){
            if(!flag[i-1][j-1]){
                if(dp[i-1][j] == 0 && dp[i][j-1] != 0){
                    dp[i][j] = dp[i][j-1]+1;
                }
                else if(dp[i-1][j] != 0 && dp[i][j-1] == 0){
                    dp[i][j] = dp[i-1][j]+1;
                }
                else if(dp[i-1][j] != 0 && dp[i][j-1] != 0){
                    dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=1;
                }
            }
            ans = dp[i][j]>ans?dp[i][j]:ans;
        }
    }
    printf("%d", ans);
    return 0;
}