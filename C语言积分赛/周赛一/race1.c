#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char a[1100], tmp[1100];
const char haqi[] = "nya";

int main() {
    while(fgets(a, sizeof(a), stdin) != NULL)
    {
        int len = strlen(a);
        for(int i=0; i<len; i++){
            tmp[i] = tolower(a[i]);
        }
        tmp[len] = '\0';

        if(strstr(tmp, haqi) == NULL){
            a[len-1] = ' ';
            strcat(a, haqi);
            a[strlen(a)+1] = '\0';
            a[strlen(a)] = '\n';
            printf("%s", a);
        }
        else{
            printf("%s", a);
        }
    }
    
    return 0;
}