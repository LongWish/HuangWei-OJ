#include <stdio.h>
#include <string.h>
#define SIZE 30000
#define LEN 202

int k, w, max, hex, left;
char a[SIZE][LEN] = {0}, ans[LEN] = {0};    //a[j] -> dp[i][j], i from 2 to max

void plus(char *srh, const char *buf){
    int lenc=0, x=0;
    while (lenc<srh[0] || lenc<buf[0])
    {
        lenc++;
        srh[lenc] = srh[lenc] + buf[lenc] + x;
        x = srh[lenc] / 10;
        srh[lenc] %= 10;
    }
    if(x>0){
        lenc++;
        srh[lenc] = x;
    }
    srh[0] = lenc;
}

void print(const char *num){
    for (int i= num[0]; i>=1; i--)
        printf("%d", num[i]);
}

int main(){
    // printf("%lld\n", sizeof(a) / 1024 / 1024);
    scanf("%d %d", &k, &w);
    hex = (1 << k);     //2^k
    left = w % k;
    max = (left == 0) ? w / k : w / k + 1;
    int maxleft = left == 0 ? 1 : hex - (1 << left) + 1;
    // printf("%d\n\n", maxleft);
    if(max < 2 || (max == 2 && w == k + 1)){
        printf("0");
        return 0;
    }
    if(max == 2 && left != 0){
        int ans_ = 0;
        for(int i = 1; i <= (1 << (left)) - 1; i++){
            ans_ += hex - i - 1;
        }
        printf("%d", ans_);
        return 0;
    }
    if(max == 2 && left == 0){
        int ans_ = 0;
        for(int i = 1; i <= hex - 1; i++){
            ans_ += hex - i - 1;
        }
        printf("%d", ans_);
        return 0;
    }

    //i=1
    a[1][0] = 1, a[1][1] = 1, a[2][0] = 1;   //dp[1][j]=1(j <= hex - 1), dp[i][1] = 0(i >= 2)

    // for(int j = 1; j <= max; j++){
    //     a[j][0] = 1;
    //     print(a[j]);
    //     printf(" ");
    // }
    // printf("\n");


    for(int j = 2; j <= hex - 1; j++){
        for(int i = max; i >= 1; i--){
            /*
            dp[i][j] = sum(dp[i-1][1~(j-1)])
            dp[i][j+1] = sum(dp[i-1][1~j]) = dp[i-1][j] + sum(dp[i-1][1~(j-1)]) = dp[i-1][j] + dp[i][j]

            dp[i][val] = dp[i][val-1] + dp[i-1][val-1]
            error: The order of j has been reversed.

            我不玩了，我以为滚动数组滚的是j，结果滚的是i，4小时人麻了！

            我要痛骂这道题，因为10MB的内存限制导致我做了8个小时才通过，还因为开了int高精度得了一次0分，我谢谢你。
            */
            plus(a[i], a[i-1]);
        }
        for(int i = max; i >= 1; i--){
            if((i >= 2 && i < max) || (i == max && j >= maxleft)){
                // print(a[i]);
                // printf(":i=%d,j=%d\n", i, j);
                plus(ans, a[i]);
            }
        }
        // for(int i = 1; i <= max; i++){
        //     print(a[i]);
        //     printf(" ");
        // }
        // printf("\n");
    }
    // print(ans);

    // if(left == 0){
    //     for(int i = max - 1; i >= 1; i--){
    //         plus(a[i], a[i-1]);
    //         if(i == max)  plus(ans, a[i]);
    //     }  
    // }
    // else{
    //     int maxleft = (1 << left) - 1;
    //     for(int i = max - 1; i >= 1; i--){
    //         plus(a[i], a[i-1]);
    //     }
    //     for(int i = hex - 1; i >= maxleft; i--){
    //         if(i >= 2)  plus(ans, a[i]);
    //     }
    // }

    // for(int i = 1; i < max; i++){
    //     print(a[i]);
    //     printf(" ");
    // }
    // printf("\n");
    print(ans);

    return 0;
}