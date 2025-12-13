#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define int long long

int m, n, sum=0, tmp;

signed main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i<=n; i++){
        for(int j=1; j<=m;j++){
            scanf("%lld", &tmp);
            sum += tmp;
        }
    }
    //sum = 9x + 6y + 4z
    if(m==1&& n == 1){
        printf("%lld", sum);
        return 0;
    }

    if(m == 1 || n == 1){
        int max = (m!=1)?m-2:n-2;
        for(int z=0; z<=2; z++){
            int y = (sum - 2 * z) / 3;
            // printf("sum:%lld %lld,%lld\n",sum , y, z);
            if((sum - 2 * z) % 3 == 0 && y >= 0 && y <= max){
                printf("%lld\n", y+z);
            }
        }
        return 0;
    }

    int max = 2*(m-2) + 2*(n-2), square = (m-2) * (n-2);
    for(int z=0; z<=4; z++){
        for(int y=0; y<=max; y++){
            if((sum - 6*y -4*z) % 9 == 0 && (sum - 6*y -4*z) >=0 && ((sum - 6*y -4*z) / 9) <= square){
                int ans = ((sum - 6*y - 4*z) / 9) + y + z;
                printf("%lld\n", ans);
                printf("sum:%lld %lld,%lld,%lld\n",sum ,((sum - 6*y -4*z) / 9), y, z);
            }
        }
    }
    return 0;
}