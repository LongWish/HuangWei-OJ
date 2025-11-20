#include <stdio.h>

int main(){
    int a;
    while(scanf("%d",&a) != EOF)
    {
        if(a%4==0)
        {
            if(a%100!=0 || a%400==0)
            {
                printf("Leap year\n");
                continue;
            }
        }
        printf("Not leap year\n");
    }
    
    return 0;
}