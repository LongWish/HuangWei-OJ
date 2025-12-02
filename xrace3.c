#include <stdio.h>
#include <string.h>
#include <ctype.h>

int p1, p2, p3;
char ans[10000], tmp[10000], gen[10000], ch1,ch2;

void to_upper(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = (char) toupper((unsigned char)str[i]);
    }
}

void to_star(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = '*';
    }
}

int main() {
    scanf("%d%d%d", &p1, &p2, &p3);
    scanf("%s", ans);
    for(int i = 0; ans[i] ;i++){
        // printf("check\n");
        if(ans[i] == '-'){
            if(i <= 0 || ans[i+1] == '\0' ||
                !((islower(ans[i-1])&&islower(ans[i+1]))||
                (isdigit(ans[i-1])&&isdigit(ans[i+1])))
                || ans[i-1] >= ans[i+1]
            ){
                // printf("check:%c %c\n", ans[i-1], ans[i+1]);
                continue;
            }
            else{
                memset(gen, 0, sizeof(gen));
                ch1 = ans[i-1], ch2 = ans[i+1];
                strcpy(tmp ,ans + i + 1);
                ans[i] = '\0';
                if(p3 == 1){
                    int top = 0;
                    for(char j=ch1+1;j<=ch2-1;j++){
                        for(int k=0; k<p2; k++){
                            gen[top++] = j;
                        }
                    }
                } else {
                    int top = 0;
                    for(char j=ch2-1;j>=ch1+1;j--){
                        for(int k=0; k<p2; k++){
                            gen[top++] = j;
                        }
                    }
                }
                // printf("check\n");

                if(p1 == 2){
                    to_upper(gen);
                }
                else if(p1 ==3){
                    to_star(gen);
                }
                
                strcat(ans, gen);
                strcat(ans, tmp);
            }
        }
    }
    printf("%s", ans);

    return 0;
}