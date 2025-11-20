#include <stdio.h>
#include <math.h>

#define PI 3.1415926536

int main(){
    double r, delta, fin, x, y, z;
    while(scanf("%lf%lf%lf", &r, &delta, &fin) != EOF)
    {
        delta = delta / 180.0 * PI;
        fin = fin / 180.0 * PI;
        x = r * sin(delta) * cos(fin);
        y = r * sin(delta) * sin(fin);
        z = r * cos(delta);
        printf("x = %.10lf y = %.10lf z = %.10lf\n", x, y, z);
    }
    
    return 0;
}

