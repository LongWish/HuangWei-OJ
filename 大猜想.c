#include <stdio.h>
#define int long long

int x, count;

signed main() {
    while(scanf("%lld", &x) != EOF)
    {
        count = 0;
        while(x != 1){
            count++;
            if(x % 2 ==1){
                x = 3 * x + 1;
            }
            else{
                x /= 2;
            }
        }
        printf("%lld\n", count);
    }
    
    return 0;
}