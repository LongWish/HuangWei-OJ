#include <stdio.h>
#include <string.h>

char a[1002], b[1002], *c, str[2004];

int main() {
    while(fgets(str, sizeof(str), stdin) != NULL)
    {
        int count = 0;
        sscanf(str, "%s %s", a, b);
        while((c = strstr(a, b)) != NULL){
            // printf("check");
            count++;
            strcpy(a, c + 1);
        }
        // printf("check");
        printf("%d time(s)\n", count);
    }
    
    return 0;
}