#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int u[5001], v[5001], ans = 0;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    if(n % 3 == 0){
        for(int i=2; i<=n; i+=3) u[i] = 1;
    } else if(n % 3 == 1) {
        for(int i=1; i<=n; i+=3) u[i] = 1;
    } else {    //n%3=2
        for(int i=2; i<=n; i+=3) u[i] = 1;
    }

    if(m % 3 == 0){
        for(int i=2; i<=m; i+=3) v[i] = 1;
    } else if(m % 3 == 1) {
        for(int i=1; i<=m; i+=3) v[i] = 1;
    } else {    //m%3=2
        for(int i=2; i<=m; i+=3) v[i] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int a;
            scanf("%d", &a);
            ans += u[i] * v[j] * a;
        }
    }

    printf("%d\n", ans);

    return 0;
}