#include <stdio.h>

double p(double x, int n){
    if(n == 0){
        return 1.0;
    } else if(n == 1) {
        return x;
    } else {
        return ((2.0 * n - 1.0) * x * p(x, n-1) - (1.0 * n - 1.0) * p(x, n-2)) / (1.0 * n);
    }
}

int main() {
    int n;
    double x;
    while(scanf("%d %lf", &n, &x) != EOF)
    {
        printf("%.2lf\n", p(x, n));
    }
    
    return 0;
}