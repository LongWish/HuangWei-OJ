#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int t, n;
int min, max = -1, tmp, num[101000];
char flag[101000] = {0};

int main() {
    freopen("out.txt", "r", stdin);
    scanf("%d", &t);
    for(int times = 0;times < t;times++){
        int pass = 1;
        memset(flag, 0, sizeof(flag));
        scanf("%d", &n);
        scanf("%d", &min);
        if(min != 1)  pass = 0;
        for(int i=1; i<n-1; i++){
            scanf("%d", &tmp);
            if(tmp <= min || tmp == i+1 || tmp >= n){
                pass = 0;
            }
            flag[tmp]++;
            if(flag[tmp] > 1)   pass = 0;
            max = tmp>max?tmp:max;
        }
        scanf("%d", &tmp);
        if(tmp != n)  pass = 0;
        if(pass){
            printf("Yes\n");
        }else{
            printf("No\n");
        }

    }
    
    return 0;
}