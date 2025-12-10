#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[100000];
int num[11001], cnt;

int cmp(const void* p1, const void* p2){
    return *(int*)p2 - *(int*)p1;
}

int main() {
    while(fgets(str, sizeof(str), stdin) != NULL)
    {
        cnt = 0;
        char *tmp;
        tmp = strtok(str, " \t\r\n");
        while(tmp != NULL){
            sscanf(tmp, "%d", &num[cnt]);
            cnt++;
            tmp = strtok(NULL, " \t\r\n");
        }

        qsort(num, cnt, sizeof(num[0]), cmp);

        if(cnt>0) printf("%d", num[0]);
        for(int i=1; i<cnt; i++){
            printf(" %d", num[i]);
        }
        printf("\n");
    }
    return 0;
}