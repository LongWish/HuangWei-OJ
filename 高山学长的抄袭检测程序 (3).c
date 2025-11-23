#include <stdio.h>
#include <string.h>

char line1[100 * 20 + 100] = {0}; 
char line2[100 * 20 + 100] = {0};
char words1[100][20];
char words2[100][20];
int count1 = 0, count2 = 0;


void turn(char *str){
    //+1 oparation
    char c;
    for(int j = 0; str[j]; j++) {
        c = str[j];
        if (c >= 'A' && c <= 'Z') { //25 for reversing.
            c = 'A' + (c - 'A' + 25) % 26;
        } else if (c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' + 25) % 26;
        }
        str[j] = c;
    }
}

int main(){
    while(fgets(line1, sizeof(line1), stdin) != NULL){
        //in
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

        //check
        int has_output = 0;
        for(int k = 0; k < 26; k++){
            int is_first = 1;
            for (int i = 0; i < count2; i++) {
                for (int j = 0; j < count1; j++) {
                    if (strcmp(words2[i], words1[j]) == 0) {
                        if(is_first)    printf("+%d ", k);
                        printf("(%d,%d)", i, j);
                        is_first = 0;
                        has_output = 1;
                    }
                }
                turn(words2[i]);
            }
            if(!is_first)   printf("\n");
        }
        if(!has_output)     printf("No\n");
    }
    return 0;
}