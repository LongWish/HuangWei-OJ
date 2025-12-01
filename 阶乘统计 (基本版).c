#include <stdio.h>

typedef long long ll;
int n, k, top = 1;
ll tmp[22] = {1};

ll ten(int k){
    ll num = 1;
    for(int i=0; i<k; i++)  num *=10;
    return num;
}

int main() {
    while(scanf("%d%d", &n, &k) != EOF)
    {
        if(tmp[n] == 0){
            for(int i=top; i<=n; i++){
                tmp[i] = tmp[i-1] * i;
                while(tmp[i]%10==0) tmp[i] /=10;
            }
            top = n+1;
        }
        if(tmp[n] < ten(k)){
            printf("%lld\n", tmp[n]);
        } else {
            ll dob = ten(k) / 10;
            for(int i=0; i<k; i++){
                printf("%lld", (tmp[n] / dob) % 10);
                dob /= 10;
            }
            printf("\n");
        }
    }
    
    return 0;
}