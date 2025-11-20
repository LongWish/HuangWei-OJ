#include <stdio.h>
#include <string.h>

char a[1010], b[1010];
char ans[2020]= {0};

char tonum(char a) {
    return a-'0';
}

void commute() {
    memset(ans, 0, sizeof(ans)); 
    int lena = strlen(a)-1, lenb = strlen(b)-1, i=0;
    for(; i<=lena && i<=lenb; i++) {
        ans[i] += tonum(a[lena-i]) + tonum(b[lenb-i]);
        ans[i+1] += ans[i] / 10;
        ans[i] %= 10;
    }
    while(i<=lena){
        ans[i] += tonum(a[lena-i]);
        ans[i+1] += ans[i] / 10;
        ans[i] %= 10;
        i++;
    }
    while(i<=lenb){
        ans[i] += tonum(b[lenb-i]);
        ans[i+1] += ans[i] / 10;
        ans[i] %= 10;
        i++;
    }
}

void print(){
    int i=2020-1;
    while(ans[i] == 0 && i>0){
        i--;
    }
    for(; i>=0; i--){
        printf("%d", ans[i]);
    }
    printf("\n");
}

int main() {
    while(scanf("%s%s",a, b) != EOF) {
        commute();
        print();
    }
    return 0;
}