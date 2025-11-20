#include <stdio.h>
#include <string.h>

int day1[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31}, day2[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main() {
    int year, days;
    while(scanf("%d%d", &year, &days) != EOF) {
        if(year%4==0)
        {
            if(year%100!=0 || year%400==0)
            {
                for(int i=1; i<=12; i++){
                    if(days - day1[i] <= 0){
                        printf("%d.%02d.%02d\n", year, i, days);
                        break;
                    }
                    else{
                        days -= day1[i];
                    }
                    
                }
                continue;
            }
        }
        for(int i=1; i<=12; i++){
            if(days - day2[i] <= 0){
                printf("%d.%02d.%02d\n", year, i, days);
                break;
            }
            else{
                days -= day2[i];
            }
        }
    }
    
    return 0;
}

