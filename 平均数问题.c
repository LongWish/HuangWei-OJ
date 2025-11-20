#include <stdio.h>

int main(){
    int a,b,c;
    double ans;
    while(scanf("%d%d%d", &a, &b, &c) != EOF){
        ans = 1.0 * (a+b+c) / 3;
        printf("%.3f\n", ans);
    }
    
    return 0;
}