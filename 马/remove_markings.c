#include <stdio.h>
#include <string.h>

#define MAX_LEN 100000
char buf[MAX_LEN], code[MAX_LEN];

void remove_comments(const char *src, char *dst) 
{
    int i = 0, j = 0;
    while (src[i]) 
    {
        if (src[i] == '/' && src[i+1] == '/') 
        {
            i += 2;
            while (src[i] && src[i] != '\n') i++;
        }
        else if (src[i] == '/' && src[i+1] == '*') 
        {
            i += 2;
            while (src[i] && !(src[i] == '*' && src[i+1] == '/')) i++;
            if (src[i]) i += 2;
        }
        else
        {
            dst[j++] = src[i++];
        }
    }
    dst[j] = '\0';
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    printf("check");
    int first_block = 1;
    while (fgets(buf, sizeof(buf), stdin) != NULL) 
    {
        int len = strlen(buf);
        if (len > 0 && buf[len-1] == '\n') buf[len-1] = '\0';
        if (strcmp(buf, "###") == 0) 
        {
            code[0] = '\0';
            while (fgets(buf, sizeof(buf), stdin) != NULL) 
            {
                len = strlen(buf);
                if (len > 0 && buf[len-1] == '\n') buf[len-1] = '\0';
                if (strcmp(buf, "###") == 0) break;
                strcat(code, buf);
                strcat(code, "\n");
            }
            char no_comment[MAX_LEN];
            remove_comments(code, no_comment);
            
            char lines[10000][256];
            int n = 0;
            int i = 0;
            while (no_comment[i]) 
            {
                int l = 0;
                while (no_comment[i] && no_comment[i] != '\n') 
                {
                    lines[n][l++] = no_comment[i++];
                }
                lines[n][l] = '\0';
                if (no_comment[i] == '\n') i++;
                n++;
            }
            int start = 0, end = n - 1;
            while (start < n && strlen(lines[start]) == 0) start++;
            while (end >= 0 && strlen(lines[end]) == 0) end--;
            if (!first_block) printf("\n");
            for (int j = start; j <= end; j++) 
            {
                if (strlen(lines[j]) > 0) 
                {
                    if (j < end) 
                    {
                        printf("%s\n", lines[j]);
                    } 
                    else 
                    {
                        printf("%s", lines[j]);
                    }
                }
            }
            first_block = 0;
        }
    }
    return 0;
}