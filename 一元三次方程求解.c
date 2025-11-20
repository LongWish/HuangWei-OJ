#include <stdio.h>
#define HEX 1e-3

double a, b, c, d;
double tmp[10];
int count;

double multi(double x){
    return a*x*x*x + b*x*x + c*x + d;
}

double solve(double x){
    double y = x + 1, temp;
    while(y - x > HEX){
        temp = (x + y) / 2.0;
        // printf("check%.2f\n", temp);
        if(multi(temp) * multi(x) <= 0){
            y = temp;
        }
        else{
            x = temp;
        }
    }

    return x;
}

int main() {
    while(scanf("%lf%lf%lf%lf", &a, &b, &c, &d) == 4)
    {
        count = 0;
        for(int i = -100; i<=99; i++){
            if((multi((double)i) * multi((double)(i+1))) <= 0.0){
                // printf("%d: %.2lf %d: %.2lf\n", i, multi((double)i), i + 1, multi((double)(i+1))); 
                tmp[count++] = (double)i;
                if(multi(1.0 + i) == 0.0)   i++;  
            }
        }
        // for(int i = 0; i<count; i++)    printf("%.2lf\n", tmp[i]);
        printf("%.2lf %.2lf %.2lf\n", solve(tmp[0]), solve(tmp[1]), solve(tmp[2]));
    }
    
    return 0;
}