#include <stdio.h>
#include <string.h>

#define hex ((unsigned long long)0x100000000)
#define SIZE 10000
#define BYTES 8

char str[2 * BYTES * SIZE], a_[BYTES * SIZE], b_[BYTES * SIZE];
unsigned long long ans[SIZE];
unsigned int a[SIZE], b[SIZE];
int bitsa, bitsb, tmpa, tmpb;


void commute() {
    memset(ans, 0, sizeof(ans));

    for(int i=0; i < bitsa; i++) {
        for(int j=0; j < bitsb; j++) {
            ans[i + j] += (unsigned long long)a[i] * (unsigned long long)b[j];
            ans[i + j + 1] += ans[i + j] / hex;
            ans[i + j] %= hex;
        }
    }

    return;
}

void print(){
    int i = SIZE - 1;
    while(ans[i] == 0 && i>0){
        i--;
    }
    printf("%llX", ans[i]);
    i--;
    for(; i>=0; i--){
        printf("%08llX", ans[i]);
    }
    printf("\n");
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(gets(str) != NULL) {
        sscanf(str, "%s%s", a_, b_);
        int lena = strlen(a_), lenb = strlen(b_);
        tmpa = strlen(a_) % BYTES, tmpb = strlen(b_) % BYTES;
        bitsa = (tmpa == 0) ? (lena / BYTES) : (lena / BYTES + 1);
        bitsb = (tmpb == 0) ? (lenb / BYTES) : (lenb / BYTES + 1);

        for(int i=0; i < bitsa - 1; i++){
            sscanf(a_ + lena  - (i+1)*BYTES, "%8X", &a[i]);   //To flip.
        }
        if(tmpa == 1)   sscanf(a_, "%1X", &a[bitsa - 1]);
        if(tmpa == 2)   sscanf(a_, "%2X", &a[bitsa - 1]);
        if(tmpa == 3)   sscanf(a_, "%3X", &a[bitsa - 1]);
        if(tmpa == 4)   sscanf(a_, "%4X", &a[bitsa - 1]);
        if(tmpa == 5)   sscanf(a_, "%5X", &a[bitsa - 1]);
        if(tmpa == 6)   sscanf(a_, "%6X", &a[bitsa - 1]);
        if(tmpa == 7)   sscanf(a_, "%7X", &a[bitsa - 1]);
        if(tmpa == 0)   sscanf(a_, "%8X", &a[bitsa - 1]);


        for(int i=0; i < bitsb - 1; i++){
            sscanf(b_ + lenb  - (i+1)*BYTES, "%8X", &b[i]);   //To flip.
        }
        if(tmpb == 1)   sscanf(b_, "%1X", &b[bitsb - 1]);
        if(tmpb == 2)   sscanf(b_, "%2X", &b[bitsb - 1]);
        if(tmpb == 3)   sscanf(b_, "%3X", &b[bitsb - 1]);
        if(tmpb == 4)   sscanf(b_, "%4X", &b[bitsb - 1]);
        if(tmpb == 5)   sscanf(b_, "%5X", &b[bitsb - 1]);
        if(tmpb == 6)   sscanf(b_, "%6X", &b[bitsb - 1]);
        if(tmpb == 7)   sscanf(b_, "%7X", &b[bitsb - 1]);
        if(tmpb == 0)   sscanf(b_, "%8X", &b[bitsb - 1]);

        commute();
        print();
    }
    return 0;
}