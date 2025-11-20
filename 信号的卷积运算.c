#include <stdio.h>

int m, n, list1[211], list2[211], ans[211], top = 0;

int max(int a, int b){
    return a > b ? a : b;
}

int min(int a, int b){
    return a < b ? a : b;
}

int main() {
    scanf("%d%d", &m, &n);
    for(int i=0; i<m; i++){
        scanf("%d", &list1[i]);
    }
    for(int i=n-1; i>=0; i--){
        scanf("%d", &list2[i]);
    }

    for(int i = 1 - n; i <= m - 1; i++){
        for(int j = max(0, i), h = 0; j <= min(i + n - 1, m - 1); j++, h++){
            ans[top] += list1[j] * list2[max(0, -i) + h];
        }
        top++;
    }
    printf("%d", ans[0]);
    for(int i=1; i<top; i++){
        printf(" %d", ans[i]);
    }
    
    return 0;
}