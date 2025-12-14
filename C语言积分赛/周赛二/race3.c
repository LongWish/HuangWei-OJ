#include <stdio.h>
#include <string.h>

#define SIZE 50010

int n, m, smaxlen[SIZE] = {0}, hash[(int)'z'+1], ans[SIZE], cnt;
char str[SIZE][510];

int min(int a, int b){
    return a < b ? a : b;
}   //c wcnm

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d%d\n", &n, &m);
    for(int i=1; i<=n; i++){  //i to sort
        memset(hash, 0, sizeof(hash));
        // input
        scanf("%s", str[i]);
        // fgets(str[i], sizeof(str[i]), stdin);
        // if(str[i][strlen(str[i])-1] == '\n')    str[i][strlen(str[i])-1] = '\0';


        for(int p=0; str[i][p]; p++){  //p to strlen
            hash[(int)str[i][p]]++;
        }
        for(char j='A'; j<='z'; j++){     //j to hash
            smaxlen[i] = hash[(int)j] > smaxlen[i] ? hash[(int)j] : smaxlen[i];
        }
        // smaxlen
    }

    for(int i=1; i<=n; i++){
        if(m == 1 && smaxlen[i] == (int)strlen(str[i]) && smaxlen[i] > 1)  smaxlen[i]--;
        else smaxlen[i] = min(strlen(str[i]), smaxlen[i] + m);
    }   //f(a,m) = min(lena, sa+m)

    // for(int i=1; i<=n; i++)
    //     printf("%d ", smaxlen[i]);
    // printf("\n");

    int max = -1;
    for(int i=1; i<=n; i++){
        if(smaxlen[i] > max){
            cnt = 1;
            max = smaxlen[i];
            ans[0] = i;
        } else if (smaxlen[i] == max)
        {
            ans[cnt] = i;
            cnt++;
        }
    }   //to choose

    printf("%d", ans[0]);
    for(int c=1; c<cnt; c++){
        printf(" %d", ans[c]);
    }
    // printf("\n");

    return 0;
}