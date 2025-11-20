#include <stdio.h>

int a[1000000],b[1000000];
long long ans=0;

void merge(int l,int k,int r){
    int i=l,j=k,m=l;
    while(i<k && j<r){
        if(a[i]>a[j]){
            b[m]=a[j];
            m++,j++;
            ans+=(k-i);
        }
        else{
            b[m]=a[i];
            m++,i++;
        }
    }
    while(i < k){
        b[m]=a[i];
        i++,m++;
    }
    while(j < r){
        b[m]=a[j];
        j++,m++;
    }
    for(int ti=l;ti<r;ti++){
        a[ti]=b[ti];
    }
}

void mergepaixu(int l,int r){
    if(r-l>1){
        int k=(l+r)/2;
        mergepaixu(l,k);
        mergepaixu(k,r);

        merge(l,k,r);
    }
    else return;
}

int main(){
    int volumn;

    scanf("%d",&volumn);
    for(int i=0;i<volumn;i++)
        scanf("%d",&a[i]);

    mergepaixu(0,volumn);

    printf("%lld",ans);
    return 0;
}
/*666洛谷终于过了www*/