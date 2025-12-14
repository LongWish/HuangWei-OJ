#include <stdio.h>
#include <math.h>

typedef long long ll;

int t;
double xc, yc, zc, xi, yi, zi;

int main() {
    scanf("%d", &t);
    for(int times=0; times<t; times++){
        scanf("%lf%lf%lf%lf%lf%lf", &xc, &yc, &zc, &xi, &yi, &zi);
        double distance = sqrt((xc-xi) * (xc-xi) + (zc-zi) * (zc-zi));
        double time = distance / 45.0;
        ll ans1 = ceil(time / 432.0), ans2 = ceil(distance / (1000.0/7.0));
        printf("%lld %lld\n", ans1, ans2);

    }
    
    return 0;
}