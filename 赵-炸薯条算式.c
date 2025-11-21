#include<stdio.h>
#include<string.h>
long long ma[30][10000] = {
{},{},
{0,1},{0,7,0xc},{0,4,0xf},{0,2,3,5,0xb,0xd,0xE},{0,0,6,9,0xA},{0,8}
};
int cnt[28]; 
int a[20] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 6, 5, 3, 5, 5, 4};
int ans[30];


int main()
{
    cnt[2] = 1;
    cnt[3] = 2;
    cnt[4] = 2;
    cnt[5] = 6;
    cnt[6] = 4;
    cnt[7] = 1;
    for(int i = 2; i <= 18; i++)
    {
        // if(i == 5)
        //     i = 5;
        for(int j = 0; j <= 15; j++)
        {
            int k = i-a[j];
            for(int t = 1; t <= cnt[k]; t++)
                if(ma[k][t]) 
                    ma[i][++cnt[i]] = ma[k][t]*16+j;
        }
    }
        
//    for(int i = 1; i <= 25; i++)
//    {
//        printf("%d:%d\n", i, cnt[i]);
//        for(int j = 1; j <= cnt[i]; j++)
//            printf("%x ", ma[i][j]);
//        puts("");
//    }
for(int t = 6; t <= 25; t++)
{
    for(int a = 2; a <= t-4; a++)
        for(int b = 2; b <= t-a-2; b++)
        {
            int c = t-a-b;
            for(int i = 1; i <= cnt[a]; i++)
                for(int j = 1; j <= cnt[b]; j++)
                    for(int k = 1; k <= cnt[c]; k++)
                        if(ma[a][i] - ma[b][j] == ma[c][k])
                            ans[t]++;    
        }    
    printf("%d:%d\n",t+3,ans[t]);        
}

    for(int i = 2; i<=28; i++)  printf("count[%d] : %d\n", i, cnt[i]);

    return 0;
}