#include <stdio.h>
#include <string.h>

char a[1010], b[1010];
char ans[2020]= {0};
int pre;

void exchange(char *a, char *b){
    for(int i=0; i<1010; i++){
        b[i] = a[i];
    }
    return;
}

char tonum(char a) {
    return a-'0';
}

void compare(){
    if(strlen(a) > strlen(b) || (strlen(a) == strlen(b) && a[0] >= b[0])){
        pre = 0;
        return;
    }
    else{
        pre = 1;
        char temp[1010];
        exchange(a, temp);
        exchange(b, a);
        exchange(temp, b);
        return;
    }
}

void commute() {
    memset(ans, 0, sizeof(ans)); 
    int lena = strlen(a)-1, lenb = strlen(b)-1, i=0;
    for(; i<=lena && i<=lenb; i++) {
        ans[i] += tonum(a[lena-i]) - tonum(b[lenb-i]);
        if(ans[i] < 0){
            ans[i+1]--;
            ans[i] += 10;
        }
    }
    while(i<=lena){
        ans[i] += tonum(a[lena-i]);
        ans[i+1] += ans[i] / 10;
        ans[i] %= 10;
        i++;
    }
    // while(i<=lenb){
    //     ans[i] += tonum(b[lenb-i]);
    //     ans[i+1] += ans[i] / 10;
    //     ans[i] %= 10;
    //     i++;
    // }
}

void print(){
    int i=2020-1;
    while(ans[i] == 0 && i>0){
        i--;
    }
    if(pre == 1){
        printf("-");
    }
    for(; i>=0; i--){
        printf("%d", ans[i]);
    }
    printf("\n");
}

int main() {
    while(scanf("%s%s",a, b) != EOF) {
        compare();
        commute();
        print();
    }
    return 0;
}