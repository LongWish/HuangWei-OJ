#include <stdio.h>
#include <string.h>

char a[1010], b[1010];
char ans[2020]= {0};

char tonum(char a) {
    return a-'0';
}

void commute() {
    memset(ans, 0, sizeof(ans)); 
    int lena, lenb;
    lena = strlen(a)-1;
    lenb = strlen(b)-1;
    for(int i=lena; i>=0; i--) {
        for(int j=lenb; j>=0; j--) {
            ans[lena-i+lenb-j] += tonum(a[i]) * tonum(b[j]);
            ans[lena-i+lenb-j+1] += ans[lena-i+lenb-j] / 10;
            ans[lena-i+lenb-j] %= 10;
        }
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
    while(scanf("%s%s",&a, &b) != EOF) {
        commute();
        print();
    }
    return 0;
}