#include <stdio.h>

int n, a[4][4], ans, tmp;

void dfs(int t[4]){
    int pass = 1, co;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            // printf("%d<%d && %d < %d\n", a[i][t[i]], a[i][t[j]], a[j][t[j]], a[j][t[i]]);
            if(a[i][t[i]] < a[i][t[j]] && a[j][t[j]] < a[j][t[i]]){
                co = t[i];
                t[i] = t[j];
                t[j] = co;
                pass = 0;

                dfs(t);

                co = t[i];
                t[i] = t[j];
                t[j] = co;
            }
        }
    }
    if(pass){   //no exchange
        tmp = 0;
        for(int i=1; i<=n; i++){
            tmp += a[i][t[i]];
        }
        ans = tmp > ans ? tmp : ans; 
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int tol, t[4];
    scanf("%d", &tol);
    for(int times = 0; times<tol; times++){
        scanf("%d", &n);
        t[1] = 1, t[2] = 2, t[3] = 3;
        ans = -1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                scanf("%d", &a[i][j]);
            }
        }

        dfs(t);

        printf("%d\n", ans);
    }
    
    return 0;
}