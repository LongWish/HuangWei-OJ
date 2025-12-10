#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int m, n, t, c, min[100010], flag[100010] = {0};

int main() {
    scanf("%d", &t);
    min[1] = 1,min[2]=1 ,min[3] = 2, min[5] = 3, min[7]=4, flag[5] = 0;
    for(int i=4; i<=100000; i+=2){
        min[i] = i/2+1;
    }
    for(int i=7; i<=99999; i+=2){
        int tmp = 0;
        tmp = min[(i-1)/2] > tmp ? min[(i-1)/2] : tmp;
        tmp = min[(i+1)/2] > tmp ? min[(i+1)/2] : tmp;
        min[i] = 2*tmp;
        if((tmp == min[(i+1)/2] && flag[(i+1)/2] == 1) || (tmp == min[(i-1)/2] && flag[(i-1)/2] == 1))  flag[i] = 1;
    }

    flag[2] = 1;
    // for(int i=1; i<100000; i++){
    //     if(flag[i])     printf("%d ", i);
    // }
    for(int times = 0;times<t;times++){
        //main
        int pass = 0;
        scanf("%d%d%d", &n, &m, &c);
        if(flag[n]){
            if(c > m * 2 * min[n])  pass = 1;
        } else {
            if(c > m * min[n])  pass = 1;
        }
        printf("%d\n", pass?min[n]:0);
    }

    return 0;
}