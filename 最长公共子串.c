#include <stdio.h>
#include <string.h>
#define SIZE 1005

int dp[SIZE][SIZE];
char str1[SIZE], str2[SIZE];

int main() {
    while(scanf("%s %s", str1, str2) != EOF)
    {
        int ans = 0, tmp1;
        int len1 = strlen(str1), len2 = strlen(str2);
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < len1; i++){
            for(int j = 0; j < len2; j++){
                if(str1[i] == str2[j]){
                    if(i == 0 || j == 0)    dp[i][j] = 1;
                    else                    dp[i][j] = dp[i-1][j-1] + 1;

                    if(dp[i][j] > ans){
                        ans = dp[i][j];
                        tmp1 = i;
                    }
                }
            }
        }

        if(ans == 0)    printf("#\n");
        else{
            for(int i = tmp1 - ans + 1; i<=tmp1; i++){
                printf("%c", str1[i]);
            }
            printf("\n");
        }
    }
    
    return 0;
}