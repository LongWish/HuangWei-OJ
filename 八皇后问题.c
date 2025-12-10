#include <stdio.h>

int ans[93][9] = {0}, tmp[9], flag[9][9] = {0},cnt = 1;

void dfs(int n){
    if(n == 9){
        for(int i=1;i<=8;i++){
            ans[cnt][i] = tmp[i];
        }
        cnt++;
        return;
    }

    if(n >= 1){
        // printf("ch");
        for(int i=1;i<=8;i++){
            int pass = 1;
            for(int j=1; j<=n-1; j++){
                if(flag[i][j]){
                    pass = 0;
                    break;
                }
                if(i-n+j >= 1 && i-n+j <= 8 && flag[i-n+j][j]){
                    pass = 0;
                    break;
                }
                if(i+n-j >= 1 && i+n-j <= 8 && flag[i+n-j][j]){
                    pass = 0;
                    break;
                }
            }
            if(pass){
                flag[i][n] = 1;
                tmp[n] = i;
                // if(n == 8)printf("(%d,%d)", i, n);
                dfs(n+1);
                tmp[n] = 0;
                flag[i][n] = 0;
            }
        }
    }
}

int main() {
    dfs(1);
    int num;
    while(scanf("%d", &num) != EOF)
    {
        printf("%d: ", num);
        for(int i=1;i<=8;i++){
            printf("%d", ans[num][i]);
        }
        printf("\n");
    }
    
    return 0;
}