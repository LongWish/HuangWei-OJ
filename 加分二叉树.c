#include <stdio.h>
#define SIZE 50

typedef long long ll;

ll n, ans, score[SIZE] = {0}, memory[SIZE][SIZE] = {0}, left[SIZE] = {0}, right[SIZE] = {0}, root[SIZE][SIZE];

void preorder(ll l, ll r){
    if(l > r)           return;
    printf("%lld ", root[l][r]);
    if(l == r)          return;
    preorder(l, root[l][r] - 1);
    preorder(root[l][r] + 1, r);
}

ll treebuild(ll lnode, ll rnode){
    if(memory[lnode][rnode] != 0)   return memory[lnode][rnode];
    if(lnode == rnode){
        root[lnode][rnode] = lnode;
        return score[lnode];
    }
    if(lnode > rnode)               return 1;

    ll temp, max = 0;
    for(ll i = lnode; i <= rnode; i++){
        temp = (treebuild(lnode, i - 1) * treebuild(i + 1, rnode)) + treebuild(i, i);
        // if(i == 3){
        //     printf("check:%lld l:%lld r:%lld\n", temp, lnode, rnode);
        // }
        if(temp > max){     //How to compare can influce the answer.
            max = temp;
            root[lnode][rnode] = i;
        }
    }

    memory[lnode][rnode] = max;
    return max;
}

int main(){
    scanf("%lld", &n);

    for(ll i = 1; i <= n; i++){
        scanf("%lld", &score[i]);
    }
    
    ans = treebuild(1L, n);
    printf("%lld\n", ans);
    preorder(1, n);
    return 0;
}