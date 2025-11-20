#include <stdio.h>
#include <string.h>

int num[6], flag[7], tmp;
char output[7][100] = {"状元\n", "对堂\n", "三红\n", "四进\n", "二举\n", "一秀\n", "再接再厉\n"};

int main() {
    
    while(scanf("%d%d%d%d%d%d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]) != EOF) {
        memset(flag, 0, sizeof(flag));
        tmp = 1;
        for(int i=0; i<6; i++){
            flag[num[i]]++;
        }
        for(int i=1; i<=6 && tmp; i++){
            if(flag[i] == 6){
                printf("%s", output[0]);
                tmp = 0;
                continue;
            }
            if(flag[i] == 5){
                if(flag[4] == 1){
                    printf("%s", output[0]);
                    tmp = 0;
                    continue;
                }
            }

            if(flag[i] == 1){
                if(flag[1] == 1 && flag[2] == 1 && flag[3] == 1 && flag[4] == 1 && flag[5] == 1 && flag[6] == 1){
                    printf("%s", output[1]);
                    tmp = 0;
                    continue;
                }
            }

            if(flag[4] == 3){
                printf("%s", output[2]);
                tmp = 0;
                continue;
            }

            if(flag[i] == 4 && i != 4)
            {
                printf("%s", output[3]);
                tmp = 0;
                continue;
            }
        }
        if(flag[4] == 2 && tmp){
            printf("%s", output[4]);
            tmp = 0;    
        }
        if(flag[4] == 1 && tmp){
            printf("%s", output[5]);
            tmp = 0;    
        }
        if(tmp){
            printf("%s", output[6]);
        }
    }
    
    return 0;
}

