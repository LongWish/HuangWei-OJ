#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main() {
    char line[10000];
    while(fgets(line, sizeof(line), stdin)){
        line[strcspn(line, "\n\r")] = '\0';

        char *token = strtok(line, " ");
        if (!token) return 0;

        int k;
        sscanf(token, "%d", &k);

        k = k % 26;
        if (k < 0) k += 26;

        char words[100][101];
        int count = 0;

        while ((token = strtok(NULL, " ")) != NULL) {
            if (count >= 100) break;
            strcpy(words[count], token);
            count++;
        }

        for (int i = 0; i < count; i++) {
            if (i > 0) printf(" ");
            for (int j = 0; words[i][j]; j++) {
                char c = words[i][j];
                if (c >= 'A' && c <= 'Z') {
                    c = 'A' + (c - 'A' + k) % 26;
                } else if (c >= 'a' && c <= 'z') {
                    c = 'a' + (c - 'a' + k) % 26;
                }
                printf("%c", c);
            }
        }
        printf("\n");
    }
    return 0;
}