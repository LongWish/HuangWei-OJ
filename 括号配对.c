#include <stdio.h>
#include <string.h>

char str[100];
int n, count[2], flag;

int main() {
    while(scanf("%d %s", &n, str) != EOF)
    {
        memset(count, 0, sizeof(count));
        flag = 1;
        for(int i=0; i<n; i++){
            if(count[0] <  count[1]){
                flag = 0;
                break;
            }
            if(str[i] == '('){
                count[0]++;
            }
            if(str[i] == ')'){
                count[1]++;
            }
        }
        if(flag == 1 && count[0] == count[1]){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    
    return 0;
}