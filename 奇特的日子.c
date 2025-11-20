#include <stdio.h>

int sqrt_[1000], top = 0, day[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31}, flag;

int main(){
    int a;
    for(int i = 2; i * i <7000; i++){
        sqrt_[top] = i * i;
        top++;
    }
    while(scanf("%d",&a) != EOF)
    {
        flag = 1;
        if(a%4==0)
        {
            if(a%100!=0 || a%400==0)
            {
                for(int i=1; i<=12 && flag; i++){
                    for(int j=0; j < top && flag; j++){
                        if(sqrt_[j] - (a + (31*i)) <= day[i] && sqrt_[j] - (a + (31*i)) > 0){
                            printf("%d %d %d\n", a, i, sqrt_[j] - (a + (31*i)));
                            flag = 0;
                        }
                    }
                }
            }
        }
        if(flag)    printf("no leap day\n");
    }
    
    return 0;
}