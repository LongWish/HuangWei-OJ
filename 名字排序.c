#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[1200], *tmp;
char name[200][21];
int count;

int cmp(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {
    while(fgets(str, sizeof(str), stdin) != NULL)
    {
        count = 0;
        tmp = strtok(str, " ");
        while(tmp != NULL){
            sscanf(tmp, "%s", name[count]);
            count++;
            tmp = strtok(NULL, " \t\r\n");
        }

        // printf("%d\n", count);
        // printf("%s", name[0]);
        // for(int i = 1; i<count; i++){
        //     printf(" %s", name[i]);
        // }
        // printf("\n");

        qsort(name, count, sizeof(name[0]), cmp);

        printf("%s", name[0]);
        for(int i = 1; i<count; i++){
            printf(" %s", name[i]);
        }
        printf("\n");
    }
    
    return 0;
}