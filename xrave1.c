#include <stdio.h>

char flag[1200001] = {0};
int n, m, tmp, ans = 0;

int main() {
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d", &tmp);
        for(int j=tmp-2; j<=tmp+2; j++){
            if(j>=1 && j<=n){
                if(flag[j] == 0){
                    flag[j] = 1;
                    ans++;
                }
            }
        }
    }
    printf("%d", ans);
    
    return 0;
}