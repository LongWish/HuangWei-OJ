#include <stdio.h>

#define PI 3.14159265358979

int main(){
    int n, r[101], a[101];
    double ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&r[i],&a[i]);
    }
    for(int i=0;i<n;i++){
        ans+=0.5*(a[i]/180.0)*r[i]*r[i]*PI;
    }
    printf("%.3f",ans);

    return 0;
}
