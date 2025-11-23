#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 10
#define MAX_LINE_LEN 1200

int main() {
    char line1[MAX_LINE_LEN] = {0};
    char line2[MAX_LINE_LEN] = {0};
    
    // 严格只读两行
    if (fgets(line1, MAX_LINE_LEN, stdin) == NULL) {
        return 0;
    }
    if (fgets(line2, MAX_LINE_LEN, stdin) == NULL) {
        // 第二行可能不存在（文件末尾无换行符），但题目保证两行
        // 为健壮性，置空第二行
        line2[0] = '\0';
    }

    // 彻底清理行尾：\r\n, \n, \r
    size_t len = strlen(line1);
    while (len > 0 && (line1[len-1] == '\n' || line1[len-1] == '\r')) {
        line1[--len] = '\0';
    }
    
    len = strlen(line2);
    while (len > 0 && (line2[len-1] == '\n' || line2[len-1] == '\r')) {
        line2[--len] = '\0';
    }

    char words1[MAX_WORDS][MAX_WORD_LEN + 1] = {{0}};
    char words2[MAX_WORDS][MAX_WORD_LEN + 1] = {{0}};
    int count1 = 0, count2 = 0;

    // 安全分割第一行
    char *token = strtok(line1, " \t");
    while (token != NULL && count1 < MAX_WORDS) {
        // 跳过空token
        if (token[0] == '\0') {
            token = strtok(NULL, " \t");
            continue;
        }
        
        // 严格截断到10字符
        size_t token_len = strlen(token);
        if (token_len > MAX_WORD_LEN) token_len = MAX_WORD_LEN;
        
        strncpy(words1[count1], token, token_len);
        words1[count1][token_len] = '\0';
        count1++;
        
        token = strtok(NULL, " \t");
    }

    // 安全分割第二行
    token = strtok(line2, " \t");
    while (token != NULL && count2 < MAX_WORDS) {
        if (token[0] == '\0') {
            token = strtok(NULL, " \t");
            continue;
        }
        
        size_t token_len = strlen(token);
        if (token_len > MAX_WORD_LEN) token_len = MAX_WORD_LEN;
        
        strncpy(words2[count2], token, token_len);
        words2[count2][token_len] = '\0';
        count2++;
        
        token = strtok(NULL, " \t");
    }

    // 按要求输出所有匹配
    for (int i = 0; i < count2; i++) {
        for (int j = 0; j < count1; j++) {
            if (strcmp(words2[i], words1[j]) == 0) {
                printf("(%d,%d)", i, j);
            }
        }
    }
    printf("\n");

    return 0;
}