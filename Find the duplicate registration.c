#include <stdio.h>
#include <string.h>

int n, cnt, times[105], max, p;
char a[105][110], tmp[110];

int main() {
    while(scanf("%d", &n) != EOF)
    {
        memset(a, 0, sizeof(a));
        memset(times, 0, sizeof(times));
        max = -1, cnt = 0;
        if(n == 0)   return 0;
        for(int i=0; i<n; i++){
            scanf("%s", tmp);
            int flag = 1;
            for(int j=0; flag && j<cnt; j++){
                if(strcmp(tmp, a[j]) == 0){
                    times[j]++;
                    flag = 0;
                }
            }
            if(flag){
                strcpy(a[cnt], tmp);
                times[cnt]++;
                cnt++;
            }
        }

        for(int i=0; i<cnt; i++){
            if(times[i] > max){
                max = times[i];
                p = i;
            }
        }

        printf("%s", a[p]);
        printf("\n");
    }
    
    return 0;
}