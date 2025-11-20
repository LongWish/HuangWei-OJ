#include <stdio.h>
#include <math.h>

int a[201], tmp[201]={0}, volumn, ans=0, dp[201][201]={0}, flag[201][201]={0};

void to_sum(){
    tmp[1] = a[1];
    for(int i=2; i<=2*volumn; i++){
        tmp[i] = tmp[i-1] + a[i];
    }
}

void dpmin(int n1, int n2){
    int record=0, tosum;
    tosum = tmp[n2] - tmp[n1-1];
    if(n1 == n2){
        dp[n1][n2] = 0;
        return;
    }

    if(flag[n1][n2])    return;
    for(int i=n1; i<=n2-1; i++){
        dpmin(n1, i);
        dpmin(i+1, n2);
        record = dp[n1][i] + dp[i+1][n2] + tosum;
        if(record < dp[n1][n2]) dp[n1][n2] = record;    //To sort
    }
    flag[n1][n2] = 1;
    return;
}

void dpmax(int n1, int n2){
    int record=0, tosum;
    tosum = tmp[n2] - tmp[n1-1];
    if(n1 == n2){
        dp[n1][n2] = 0;
        return;
    }

    if(flag[n1][n2])    return;
    for(int i=n1; i<=n2-1; i++){
        dpmax(n1, i);
        dpmax(i+1, n2);
        record = dp[n1][i] + dp[i+1][n2] + tosum;
        if(record > dp[n1][n2]) dp[n1][n2] = record;    //To sort
    }
    flag[n1][n2] = 1;
    return;
}

int main(){
    scanf("%d",&volumn);
    for(int i=1; i <= volumn; i++)
        scanf("%d", &a[i]);

    if(volumn == 1){
        printf("0\n");
        printf("0\n");
        return 0;
    }
    
    for(int i=volumn+1; i<=2*volumn; i++){  //To initialze
        a[i] = a[i-volumn];
    }
    to_sum();
    
    ans = __INT_MAX__;
    for(int i=0; i<201; i++){
        for(int j=0; j<201; j++){   //To initialze
            dp[i][j] = __INT_MAX__;
        }
    }
    for(int i=1; i<=volumn; i++){
        dpmin(i,i+volumn-1);
        if(ans>dp[i][i+volumn-1]) ans = dp[i][i+volumn-1];
    }
    printf("%d\n", ans);

    ans = -1;
    
    for(int i=0; i<201; i++){
        for(int j=0; j<201; j++){   //To initialze
            dp[i][j] = -1;
            flag[i][j] = 0;
        }
    }
    for(int i=1; i<=volumn; i++){
        dpmax(i,i+volumn-1);
        if(ans<dp[i][i+volumn-1]) ans = dp[i][i+volumn-1];
    }
    printf("%d\n", ans);

    return 0;
}