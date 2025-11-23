#include <stdio.h>
#include <string.h>

char line1[100 * 20 + 100] = {0}; 
char line2[100 * 20 + 100] = {0};
char words1[100][20];
char words2[100][20];
int count1 = 0, count2 = 0;

int main(){
    while(fgets(line1, sizeof(line1), stdin) != NULL){
        memset(words1, 0 ,sizeof(words1));
        memset(words2, 0 ,sizeof(words2));
        count1 = 0, count2 = 0;
        if (!fgets(line2, sizeof(line2), stdin)) return 0;
        char *token = strtok(line1, " \t\r\n");
        while (token != NULL) {
            strcpy(words1[count1], token);
            count1++;
            token = strtok(NULL, " \t\r\n");
        }

        token = strtok(line2, " \t\r\n");
        while (token != NULL) {
            strcpy(words2[count2], token);
            count2++;
            token = strtok(NULL, " \t\r\n");
        }

        for (int i = 0; i < count2; i++) {
            for (int j = 0; j < count1; j++) {
                if (strcmp(words2[i], words1[j]) == 0) {
                    printf("(%d,%d)", i, j);
                }
            }
        }
        printf("\n");
    }
    return 0;
}