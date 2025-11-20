#include <stdio.h>
#define int unsigned long long

int n, fruits[1000010], endurance = 0;

void treeup(int node){
    if(node == 1)   return;
    int fnode = node / 2, tmp;

    if(fruits[fnode] > fruits[node]){
        tmp = fruits[node];
        fruits[node] = fruits[fnode];
        fruits[fnode] = tmp;
        treeup(fnode);
    }
    else{
        return;
    }
}

void treedown(int node){
    if(node > n)   return;
    int son1 = node * 2, son2 = (node * 2) + 1, tmp;
    // printf("check! %d\n", n);
    if(son1 <= n){
    if(fruits[son1] <= fruits[son2] && fruits[son1] < fruits[node]){
        tmp = fruits[node];
        fruits[node] = fruits[son1];
        fruits[son1] = tmp;
        treedown(son1);
        }
    }
    if(son2 <= n){
        if(fruits[son2] < fruits[son1] && fruits[son2] < fruits[node]){
            tmp = fruits[node];
            fruits[node] = fruits[son2];
            fruits[son2] = tmp;
            treedown(son2);
        }
    }
    else{
        return;
    }
}

signed main() {
    int tmp;
    for(int i=0; i < 10010; i++){
        fruits[i] = __INT32_MAX__;
    }
    scanf("%llu", &n);
    for(int i=1; i<=n; i++){
        scanf("%llu", &fruits[i]);
        treeup(i);
    }
    if(n == 1){
        printf("0");
        return 0;
    }
    // for(int i=1; i<=n; i++){
    //     printf("%d %d\n",fruits[i], i);
    // }
    //To merge
    while(n > 2){
        tmp = fruits[1];
        fruits[1] = fruits[n];
        fruits[n] = __INT32_MAX__;
        n--;
        treedown(1);
        // for(int i=1; i<=n; i++){
        //     printf("%d %d\n",fruits[i], i);
        // }
        // printf("check! min:%d\n", fruits[1]);
        tmp += fruits[1];
        endurance += tmp;
        fruits[1] = fruits[n];
        fruits[n] = __INT32_MAX__;
        n--;
        treedown(1);
        n++;
        fruits[n] = tmp;
        treeup(n);
        // printf("check! min:%d\n", fruits[1]);
        // printf("check! endurance:%d\n", endurance);
        // printf("%d\n", n);
    } 
    endurance += fruits[1] + fruits[2];
    printf("%llu", endurance);
    return 0;
}