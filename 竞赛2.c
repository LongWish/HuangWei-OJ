#include <stdio.h>
#include <string.h>

char num[100];
unsigned int len, ans;

int main() {
    
    while(scanf("%s", num) != EOF) {
        ans = 0;
        len = strlen(num);
        for(int i=len - 1; i>=0; i--){
            ans += (num[i] - '0') * (1<<(len - 1 - i));
        }
        printf("%d\n", (int)ans);
    }
    
    return 0;
}

