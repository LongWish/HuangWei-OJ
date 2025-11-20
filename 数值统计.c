#include <stdio.h>
#include <string.h>

int n, ans[3];
double a[101];

int main() {
    while(scanf("%d", &n) != EOF)
    {
        if(n == 0)  return 0;
        memset(ans, 0, sizeof(ans));
        for(int i=0; i<n; i++){
            scanf("%lf", &a[i]);
            if(a[i] < 0)    ans[0]++;
            if(a[i] > 0)    ans[2]++;
            if(a[i] == 0)   ans[1]++;
        }
        printf("%d %d %d\n", ans[0], ans[1], ans[2]);
    }
    
    return 0;
}