#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1500

int cnt;
char str[SIZE * 60], *tmp, flt[SIZE][60];

int cmp(const void* str1, const void* str2){
    const char *flt1 = str1, *flt2 = str2;
    if((flt1[0] == '-' && flt2[0] != '-'))
        return 0;
    else if((flt2[0] == '-' && flt1[0] != '-'))
        return 1;
    else{
        int sign = flt1[0] == '-' ? 1 : 0;
        int point1, point2, len1 = strlen(flt1), len2 = strlen(flt2);

        for(int i = 0; i < len1; i++)
            if(flt1[i] == '.'){
                point1 = i;
                break;
            }
        for(int i = 0; i < len2; i++)
            if(flt2[i] == '.'){
                point2 = i;
                break;
            }

        if(point1 != point2)    return sign ? (point1 < point2) : !(point1 < point2);
        else{
            for(int i = 0; i < point1; i++){
                if(flt1[i] != flt2[i]){
                    return sign ? (flt1[i] < flt2[i]) : !(flt1[i] < flt2[i]);
                }
            }
            return sign ? -strcmp(flt1 + point1, flt2 + point2) : strcmp(flt1 + point1, flt2 + point2);
        }
    }
}

int main() {
    while(fgets(str, sizeof(str), stdin) != NULL)
    {
        cnt = 0;
        tmp = strtok(str, " \t\r\n");
        // printf("%s", tmp);
        while(tmp != NULL){
            sscanf(tmp, "%s", flt[cnt]);
            cnt++;
            tmp = strtok(NULL, " \t\r\n");
        }
        
        qsort(flt, cnt, sizeof(flt[0]), cmp);

        printf("%s", flt[0]);
        for(int i = 1; i<cnt; i++){
            printf(" %s", flt[i]);
        }
        printf("\n");
    }
    
    return 0;
}