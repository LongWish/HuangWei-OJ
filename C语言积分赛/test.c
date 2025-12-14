#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *str1, *str2;

char* s(const char* str);
char* p(const char* str); // 处理去括号字符串
void change(char* src, char* det);
char* add(char* str1, char* str2);

char* s(const char* str) {
    char *ans = (char*)malloc(2048);
    if (strcmp(str, "") == 0) {
        strcpy(ans, "{}");
    } else {
        strcpy(ans, str);
        strcat(ans, ",{");
        strcat(ans, str);
        strcat(ans, "}");
    }
    return ans;
}

char* p(const char* str) {
    char *ans = (char*)calloc(2048, 1);
    if (strcmp(str, "{}") == 0) {
        return ans; // 返回空字符串
    }
    if (strcmp(str, "") == 0) {
        return ans; // 返回空字符串
    }

    int len = strlen(str);
    if ((len - 3) % 2 != 0 || len < 7) {
        return ans; // 无效输入，返回空字符串
    }

    int n = (len - 3) / 2;
    if (str[n] != ',' || str[n + 1] != '{' || str[len - 1] != '}') {
        return ans;
    }

    if (strncmp(str + n + 2, str, n) != 0 || str[n + 2 + n] != '}') {
        return ans;
    }

    strncpy(ans, str, n);
    ans[n] = '\0';
    return ans;
}

char* antistr(const char* str) {
    char *ans = (char*)malloc(2048);
    strcpy(ans, str + 1);
    ans[strlen(ans) - 1] = '\0';
    return ans;
}

char* str(const char* inner) {
    char *ans = (char*)malloc(2048);
    sprintf(ans, "{%s}", inner);
    return ans;
}

void change(char* src, char* det) {
    strcpy(src, det);
    free(det);
}

char* add(char* str1, char* str2) {
    if (strcmp(str2, "") == 0) {
        char* res = (char*)malloc(2048);
        strcpy(res, str1);
        return res;
    }
    
    char* pB = p(str2);
    char* temp = add(str1, pB);
    char* result = s(temp);
    
    free(pB);
    free(temp);
    return result;
}

int main() {
    str1 = (char*)malloc(2048);
    str2 = (char*)malloc(2048);

    fgets(str1, 2048, stdin);
    if (str1[strlen(str1) - 1] == '\n') str1[strlen(str1) - 1] = '\0';
    fgets(str2, 2048, stdin);
    if (str2[strlen(str2) - 1] == '\n') str2[strlen(str2) - 1] = '\0';

    // 修正：判断完整字符串表示的空集 "{}"
    if (strcmp(str1, "{}") == 0) {
        printf("%s", str2);
        free(str1);
        free(str2);
        return 0;
    }
    if (strcmp(str2, "{}") == 0) {
        printf("%s", str1);
        free(str1);
        free(str2);
        return 0;
    }

    // 转换为去括号字符串
    char* tmp1 = antistr(str1);
    char* tmp2 = antistr(str2);
    strcpy(str1, tmp1);
    strcpy(str2, tmp2);
    free(tmp1);
    free(tmp2);

    char* ans_inner = add(str1, str2);
    char* final_ans = str(ans_inner);

    printf("%s", final_ans);

    free(str1);
    free(str2);
    free(ans_inner);
    free(final_ans);
    return 0;
}