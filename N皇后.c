#include <stdio.h>

int ans[5][15] = {0}, tmp[15], flag[15][15] = {0}, cnt = 1, max, w[15] = {0};

void dfs(int n){
    if(n == max + 1){
        if(cnt < 5)
            for(int i=1;i<=max;i++){
                ans[cnt][i] = tmp[i];
            }
        cnt++;
        return;
    }

    if(n >= 1){
        // printf("ch");
        for(int i=1;i<=max;i++){
            if(w[i] == 1)   continue;
            int pass = 1;
            for(int j=1; j<=n-1; j++){
                // if(flag[i][j]){
                //     pass = 0;
                //     break;
                // }
                int tmp1 = i-n+j, tmp2 = i+n-j;
                if(tmp1 >= 1 && tmp1 <= max && flag[tmp1][j]){
                    pass = 0;
                    break;
                }
                if(tmp2 >= 1 && tmp2 <= max && flag[tmp2][j]){
                    pass = 0;
                    break;
                }
            }
            if(pass){
                flag[i][n] = 1, w[i] = 1;
                tmp[n] = i;
                // if(n == max)printf("(%d,%d)", i, n);
                dfs(n+1);
                flag[i][n] = 0, w[i] = 0;
            }
        }
    }
}

int main() {
    scanf("%d", &max);
    // printf("%lld", sizeof(ans)/1024/1024);
    dfs(1);
    for(int i=1;i<=3;i++){
        printf("%d ", ans[i][1]);
        for(int j=2; j <= max; j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    printf("%d\n", cnt - 1);
    
    return 0;
}