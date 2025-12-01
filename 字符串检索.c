#include <stdio.h>
#include <string.h>

int main() {
    char article[2050];
    char word[15];
    char ch;
    int idx;

    while (1) {
        idx = 0;
        while ((ch = getchar()) != '#') {
            if (ch == EOF) {
                return 0;
            }
            if (ch == '\n') {
                continue;
            }
            article[idx++] = ch;
            if (idx >= 2049) break;
        }
        article[idx] = '\0';

        while ((ch = getchar()) != '\n') {
            if (ch == EOF) {
                return 0;
            }
        }

        if (scanf("%s", word) != 1) {
            break;
        }

        int count = 0;
        char *p = article;
        while ((p = strstr(p, word)) != NULL) {
            count++;
            p++;
        }

        printf("%d time(s)\n", count);
        while ((ch = getchar()) != '\n' && ch != EOF);
        if (ch == EOF) {
            break;
        }
    }
    return 0;
}