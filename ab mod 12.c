#include <stdio.h>
#define int long long

int a, b;
int tmp = 1;

signed main() {
    if(scanf("%lld%lld", &a, &b) != EOF)
    {
        for(int i = 1; i <= b; i++){
            tmp = tmp * a;
            if(tmp == 0){
                printf("0");
                return 0;
            }
            tmp %= 1012;
        }
        printf("%lld", tmp);
    }
    return 0;
}