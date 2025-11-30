#include <stdio.h>

int cnt = 0;
void dfs(char a, char b, char c, int step){
    if(step == 1){
        cnt++;
        printf("Step %d:%c -> %c\n", cnt, a, c);
    }
    else{
        dfs(a, c, b, step-1);
        cnt++;
        printf("Step %d:%c -> %c\n", cnt, a, c);
        dfs(b, a, c, step-1);
    }
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF)
    {
        cnt = 0;
        dfs('A', 'B', 'C', n);    
    }

    return 0;
}