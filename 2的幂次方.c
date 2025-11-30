#include <stdio.h>

const int tmp[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384};

int n;
void dfs(int n){
    if(n == 1){
        printf("2(0)");
        return;
    }
    else if(n == 2){
        printf("2");
        return;
    }
    else if (n == 3)
    {
        printf("2+2(0)");
        return;
    }
    else if(n == 4)
    {
        printf("2(2)");
        return;
    }
    for(int i=2; i<=14; i++){
        if(n / tmp[i] == 1){
            if(n % tmp[i]==0){
                printf("2(");
                dfs(i);
                printf(")");
            } else {
                dfs(tmp[i]);
                printf("+");
                dfs(n % tmp[i]);
            }
        }
    }
    
}

int main() {
    scanf("%d", &n);
    dfs(n);
    return 0;
} 