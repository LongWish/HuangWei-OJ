#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_COUNT 200
#define MAX_STR_LEN 50

char input_line[1024];
char strings[MAX_STR_COUNT][MAX_STR_LEN];
int count;
char *token;

unsigned int ctov(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else if (isalpha(c)) {
        return toupper(c) - 'A' + 1;
    }
    return 0;
}

unsigned int stov(const char *str) {
    char num_str[20] = {0};
    char temp[4];
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned int val = ctov(str[i]);
        sprintf(temp, "%u", val);
        strcat(num_str, temp);
    }
    return (unsigned int)strtoul(num_str, NULL, 10);
}

int cmp(const char *str1, const char *str2) {
    unsigned int num1 = stov(str1);
    unsigned int num2 = stov(str2);
    if (num1 > num2) return 1;
    if (num1 < num2) return -1;
    return 0;
}

int main() {
    while(fgets(input_line, sizeof(input_line), stdin) != NULL){
        int len = strlen(input_line);
        if (len > 0 && input_line[len-1] == '\n') {
            input_line[len-1] = '\0';
        }

        count = 0;
        token = strtok(input_line, " ");
        while (token != NULL && count < MAX_STR_COUNT) {
            strncpy(strings[count], token, MAX_STR_LEN-1);
            strings[count][MAX_STR_LEN-1] = '\0';
            count++;
            token = strtok(NULL, " ");
        }

        for (int i = 0; i < count-1; i++) {
            for (int j = 0; j < count-1-i; j++) {
                if (cmp(strings[j], strings[j+1]) < 0) {
                    char temp[MAX_STR_LEN];
                    strcpy(temp, strings[j]);
                    strcpy(strings[j], strings[j+1]);
                    strcpy(strings[j+1], temp);
                }
            }
        }

        for (int i = 0; i < count; i++) {
            if (i > 0) printf(" ");
            printf("%s", strings[i]);
        }
        printf("\n");
    }
    return 0;
}