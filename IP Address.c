#include <stdio.h>
#include <string.h>
#include <ctype.h>

void trim(char *str) {
    int len = strlen(str);
    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t' || 
                      str[len - 1] == '\r' || str[len - 1] == '\n')) {
        str[--len] = '\0';
    }
    char *start = str;
    while (*start && (*start == ' ' || *start == '\t' || 
                     *start == '\r' || *start == '\n')) {
        start++;
    }

    if (start != str) {
        memmove(str, start, strlen(start) + 1);
    }
}

int check_octet(const char *str, int len) {
    if (len <= 0 || len > 3) {
        return 0;
    }
    
    if (len > 1 && str[0] == '0') {
        return 0;
    }
    
    int num = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
        num = num * 10 + (str[i] - '0');
        if (num > 255) {
            return 0;
        }
    }
    return 1;
}

int is_valid_ip(char *s) {
    if (s == NULL || s[0] == '\0') {
        return 0;
    }
    
    int dot_count = 0;
    int i = 0;
    int n = 0;

    while (s[i] != '\0') {
        if (s[i] == '.') {
            dot_count++;
        } else if (s[i] < '0' || s[i] > '9') {
            return 0;
        }
        i++;
    }
    n = i;

    if (dot_count != 3) {
        return 0;
    }
    
    int start = 0;
    int part_count = 0; 
    
    for (i = 0; i < n; i++) {
        if (s[i] == '.') {
            int len = i - start;
            if (len <= 0) {
                return 0;
            }
            if (!check_octet(s + start, len)) {
                return 0;
            }
            part_count++;
            start = i + 1;
        }
    }
    
    int last_len = n - start;
    if (last_len <= 0) {
        return 0;
    }
    if (!check_octet(s + start, last_len)) {
        return 0;
    }
    part_count++;

    return (part_count == 4);
}

int main() {
    char buf[1024];
    
    while (fgets(buf, sizeof(buf), stdin)) {
        int len = strlen(buf);
        if (len > 0 && buf[len - 1] == '\n') {
            buf[len - 1] = '\0';
        }
        
        trim(buf);
        
        if (is_valid_ip(buf)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}