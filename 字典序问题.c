#include <stdio.h>
#include <string.h>

char str[100][10];
int len[100], ans[100];

void count(int add, char* a, int k);


int main(){
    int k;
    scanf("%d",&k);
    for(int i = 0; i < k; i++){
        scanf("%s", str[i]);
        len[i] = strlen(str[i]);
    }

    for(int i = 0; i < k; i++){
        while (str[i][len[i]-1] >= 'a')
        {
            count(len[i]-1, str[i], i);
            //printf("%c\n", str[i][len[i]-1]);
        }
    }

    for(int i = 0; i < k; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}


void count(int add, char* a, int k)

{
    a[add]--;
    ans[k]++;
    if(a[add] < 'a')
    {
        return;
    }

    if(add != 0)
    {
        if(a[add-1] >= 'a')
        {
            if(a[add-1] >= a[add])
            {
                if(a[add+1] == '\0')    a[add] = 'z';
                else                    a[add] = a[add+1] - 1;
                
                count(add-1, a, k);
                ans[k]--;
            }
        }
    }
}


