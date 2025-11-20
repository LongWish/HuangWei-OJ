#include <stdio.h>

int year, month, day, ans;
int ryear[15]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int normalyear[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void commute(int flag);

int main(){
    while(scanf("%d%d%d",&year, &month, &day) != EOF)
    {
        ans=0;
        if(year%4==0)
        {
            if(year%100!=0 || year%400==0)
            {
                commute(1);
                printf("%d\n",ans);
                continue;
            }
        }
        commute(0);
        printf("%d\n",ans);
    }
    
    return 0;
}

void commute(int flag){
    int *yearday;
    yearday = flag?ryear:normalyear;
    for(int i=1; i<month; i++){
        ans+=yearday[i];
    }
    ans+=day;
}