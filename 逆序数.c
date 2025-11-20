#include <stdio.h>
#include <string.h>

char num[10];
int len, flag, tmp;

int main() {
    while(scanf("%s", num) != EOF)
    {
        flag = 0;
        tmp = 1;
        len = strlen(num);
        for(int i=0; i<len; i++){
            if(num[i] != '0' && num[i] != 0){
                tmp = 0;
            }
        }
        if(tmp){
            printf("0\n");
            memset(num, 0, sizeof(num));
            continue;
        }
        for(int i=len-1; i>=0; i--){
            if(num[i] != '0' && !flag){
                flag = 1;
            }
            if(flag){
                printf("%c", num[i]);
            }
        }
        printf("\n");
        memset(num, 0, sizeof(num));
    }
    
    return 0;
}