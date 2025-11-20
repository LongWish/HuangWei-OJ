#include <stdio.h>
#include <string.h>

int n, height[110], tmp = 0, ans, memory1[110][110] = {0}, memory2[110][110] = {0}, flag;

int max(int a, int b){
    return a > b ? a : b;
}

int dfsup(int a, int b){
    if(memory1[a][b] != 0)      return memory1[a][b];
    if(a == b)                  return 1;

    int res = 1;

    for(int i = b - 1; i >= a; i--){
        
        if(height[i] < height[b]){
            res = max(res, dfsup(a, i) + 1);
        }
    }

    memory1[a][b] = res;
    // printf("%d ", res);
    return res;
}

int dfsdown(int a, int b){
    if(memory2[a][b] != 0)      return memory2[a][b];
    if(a == b)                  return 1;

    int res = 1;

    for(int i = b - 1; i >= a; i--){
        if(height[i] > height[b]){
            res = max(res, dfsdown(a, i) + 1);
        }
    }

    memory2[a][b] = res;
    // printf("%d ", res);
    return res;
}


int main(){
    ans = __INT32_MAX__;
    if(scanf("%d", &n) != 1)    return -1;
    for(int i=0; i<n; i++){
        if(scanf("%d", &height[i]) != 1)    return -1;
    }
    // for(int i=0; i<n; i++){
    //     printf("%d ", height[i]);

    // }
    
    for(int i=0; i<n; i++){
        tmp = 0, flag = 0;

        for(int j=0; j<i; j++){
            tmp = max(tmp, dfsup(0, j));
        }
        flag += tmp;
        // printf("up:%d\n", tmp);
        
        tmp = 0;
        for(int j=i; j<n; j++){
            tmp = max(tmp, dfsdown(i, j));
        }
        flag += tmp;
        // printf("down:%d\n", tmp);
        ans = ans < (n - flag) ? ans : (n - flag);
    }

    printf("%d", ans);
    
    return 0;
}