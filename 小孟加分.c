#include <stdio.h>

int main(){
    double input;
    while(scanf("%lf", &input) != EOF)
    {
        if(input >= (double)100){
            printf("%.10lf\n", input);
            continue;
        }
        input += 1e-10;
        printf("%.10lf\n", input);
    }
    
    return 0;
}

