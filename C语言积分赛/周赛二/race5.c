#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *str1, *str2;

char* s(const char* str);
char* p(const char* str); //only for non-{}-str
void change(char* src, char* det);

char* s(const char* str){
    char *ans;
    ans = (char*)malloc(2020);
    if(strcmp(str, "") == 0)        strcpy(ans, "{}");
    else{
        strcpy(ans, str);
        strcat(ans, ",{");
        strcat(ans, str);
        strcat(ans, "}");
    }

    return ans;
}

// char* p(const char* str){ //wdf
//     char *ans;
//     ans = (char*)malloc(2020);
//     ans[0] = '\0';
//     if(strcmp(str, "{}") == 0)       return ans;
//     else if(strcmp(str, "") == 0)    return ans;
//     else{
//         char *p1, *p2;
//         p1 = strstr(str, ",");
//         while (p1 != NULL)
//         {
//             p2 = p1;
//             p1 = strstr(p2+1, ",");
//         }
//         sscanf(p2+1, "%s", ans);
//         return ans;
//     }
// }

char* p(const char* str) {
    //AI version after competition is finished.
    char *ans = (char*)malloc(2020);
    ans[0] = '\0';
    
    if (strcmp(str, "{}") == 0) return ans;
    if (strcmp(str, "") == 0) return ans;

    int len = strlen(str);
    int depth = 0;
    int last_comma = -1;

    // 寻找最后一个顶层逗号
    for (int i = 0; i < len; i++) {
        if (str[i] == '{') depth++;
        else if (str[i] == '}') depth--;
        else if (str[i] == ',' && depth == 0) {
            last_comma = i;
        }
    }

    if (last_comma == -1) return ans; // 无逗号

    // 验证最后一部分格式: 必须是 "{X}"
    int start_pos = last_comma + 1;
    if (str[start_pos] != '{' || str[len-1] != '}') {
        return ans;
    }

    // 提取逗号前的部分作为结果
    strncpy(ans, str, last_comma);
    ans[last_comma] = '\0';
    return ans;
}

char* antistr(const char* str){
    char *ans = (char*)malloc(2020);
    strcpy(ans, str+1); // f**k {
    ans[strlen(ans) - 1] = '\0'; // f**k }
    return ans;
}

char* str(const char* str){
    char *ans = (char*)malloc(2020);
    sprintf(ans, "{%s}", str);
    return ans;
}

void change(char* src, char* det){
    strcpy(src, det);
    free(det);
    return;
}

char* add(char* str1, char* str2){
    if (strcmp(str2, "") == 0) {
        char* res = (char*)malloc(2020);
        strcpy(res, str1);
        return res;
    }

    char* pB = p(str2);
    char* temp = add(str1, pB);
    char* ans = s(temp);
    
    free(pB);
    free(temp);
    return ans;
}

int main() {
    str1 = (char*)malloc(2020), str2 = (char*)malloc(2020);

    fgets(str1, 2020, stdin);
    if(str1[strlen(str1)-1] == '\n')    str1[strlen(str1)-1] = '\0';
    fgets(str2, 2020, stdin);
    if(str2[strlen(str2)-1] == '\n')    str2[strlen(str2)-1] = '\0';

    if(strcmp(str1, "") == 0){
        printf("%s", str2);
        return 0;
    }
    else if(strcmp(str2, "") == 0){
        printf("%s", str2);
        return 0;
    }

    char* tmp1 = antistr(str1);
    char* tmp2 = antistr(str2);
    strcpy(str1, tmp1);
    strcpy(str2, tmp2);
    free(tmp1);
    free(tmp2);

    char* ans_inner = add(str1, str2);
    char* final_ans = str(ans_inner);

    printf("%s", final_ans);

    return 0;
}