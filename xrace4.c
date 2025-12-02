#include <stdio.h>
typedef long long ll;

ll tmp = 0, min = 0, in;

int main() {
    int n;
    scanf("%d", &n);
    for(int i=0;i<n; i++){
        scanf("%lld", &in);
        tmp += in;
        min = tmp<min?tmp:min;
    }
    printf("%lld", -min+1);
    return 0;
}