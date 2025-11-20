#include <stdio.h>

int main(){
    unsigned int tmp, count;
    while(scanf("%d", &tmp) != EOF)
    {
        count=1;
        if(tmp<=25){
            for(unsigned int i=2;i<=tmp;i++){
                count *= i;
                count %= 1000000;
            }
            printf("%06d\n", count);
        }
        else{
            printf("000000\n");
        }
    }
    
    return 0;
}