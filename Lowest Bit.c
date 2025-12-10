#include <stdio.h>
int a;

int main() {
    while(scanf("%d", &a) != EOF)
    {
        if(a == 0) break;
        for(int i=0; i<=7; i++){
            if((a & (1<<i)) != 0){
                printf("%d\n", 1<<i);
                break;
            }
        } 
    }
    
    return 0;
}