#include <stdio.h>
int sx,sy,m,n;
int tmp[1001][1001][2], tmpx, tmpy;

int main() {
    scanf("%d%d%d%d",&m,&n,&sx,&sy);
    for(int i = 1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d%d", &tmp[i][j][0], &tmp[i][j][1]);
        }
    }
    while(sx != 0 || sy != 0){
        printf("%d %d\n", sx, sy);
        tmpx = tmp[sx][sy][0], tmpy = tmp[sx][sy][1];
        sx = tmpx, sy = tmpy;
    }
    return 0;
}