#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int a[1000], len, sum, max, ans, bold;

int main(){
    while(scanf("%d", &len) != EOF){
        if(len == 0){
            printf("0 0\n");
            continue;
        }
        max = 0, sum = 0, ans = 0, bold = 0;
        for(int i = 0; i < len; i++){
            scanf("%d", &a[i]);
        }

        for(int i=0; i<len; i++){
            sum += a[i];
            if(sum < 0){
                sum = 0;
                bold = i + 1;
                // printf("bold:%d i:%d a[i]:%d\n", bold, i, a[i]);
            }
            if(sum >= max){
                ans = (sum > max) ? (i - bold + 1) : (ans < (i - bold + 1) ? (i - bold + 1) : ans);
                max = sum;
            }
        }
        if(max == 0 && ans == 0){
            max = -__INT32_MAX__;
            for(int i = 0; i<len ;i++){
                max = a[i] > max ? a[i] : max;
            }
            ans = 1;
        }
        printf("%d %d\n", max, ans);
    }

    return 0;
}