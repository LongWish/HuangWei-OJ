#include <stdio.h>
#include <string.h>

#define DAY_SECONDS (long long)(24*60*60)
#define NYEAR_SECONDS (long long)(365*24*60*60)
#define LYEAR_SECONDS (long long)(366*24*60*60)

typedef struct time{
    int year, month, day, hour, minute, second;     //six members
}time;

typedef long long ll;

char mode;
time first, second_, ans;
const ll leapyear[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
const ll normalyear[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
ll answerseconds;

int is_leapyear(int year){
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

ll to_seconds(time self){
    ll seconds = 0;
    for(int i = 1; i < self.year; i++){
        seconds += is_leapyear(i) ? LYEAR_SECONDS : NYEAR_SECONDS;
    }
    for(int i = 1; i < self.month; i++){
        seconds += is_leapyear(self.year) ? leapyear[i] * DAY_SECONDS : normalyear[i] * DAY_SECONDS;
    }
    for(int i = 1; i < self.day; i++){
        seconds += DAY_SECONDS;
    }
    for(int i = 1; i <= self.hour; i++){
        seconds += 60*60;
    }
    for(int i = 1; i <= self.minute; i++){
        seconds += 60;
    }
    seconds += self.second;

    return seconds;
}

time to_time(ll seconds){
    time self;
    int i;

    //year
    for(i = 1; seconds >= 0 ; i++){
        seconds -= is_leapyear(i) ? LYEAR_SECONDS : NYEAR_SECONDS;
    }
    i--;
    self.year = i;
    seconds += is_leapyear(i) ? LYEAR_SECONDS : NYEAR_SECONDS;

    //month
    for(i = 1; seconds >= 0 ; i++){
        seconds -= is_leapyear(self.year) ? leapyear[i] * DAY_SECONDS : normalyear[i] * DAY_SECONDS;
    }
    i--;
    self.month = i;
    seconds += is_leapyear(self.year) ? leapyear[i] * DAY_SECONDS : normalyear[i] * DAY_SECONDS;

    //day
    for(i = 1; seconds >= 0 ; i++){
        seconds -= DAY_SECONDS;
    }
    i--;
    self.day = i;
    seconds += DAY_SECONDS;

    //hour
    for(i = 0; seconds >= 0 ; i++){
        seconds -= 60*60;
    }
    i--;
    self.hour = i;
    seconds += 60*60;

    //minute
    for(i = 0; seconds >= 0; i++){
        seconds -= 60;
    }
    i--;
    self.minute = i;
    seconds += 60;
    
    //second
    self.second = seconds;

    // printf("%#X\n", &self);
    return self;
}

int main() {
    scanf("%d-%d-%d %d:%d:%d %c %d %d:%d:%d", &first.year, &first.month, &first.day, &first.hour, &first.minute, &first.second,
        &mode, &second_.day, &second_.hour, &second_.minute, &second_.second);
    second_.year = 0, second_.month = 0;
    second_.day += 1;   //Add 1 to second_time object to commute correctly.

    if(mode == '+'){
        answerseconds = to_seconds(first) + to_seconds(second_);
        ans = to_time(answerseconds);
    }
    else if(mode == '-'){
        answerseconds = to_seconds(first) - to_seconds(second_);
        ans = to_time(answerseconds);
    }
    // printf("%#X\n", &ans);

    // printf("%04d-%02d-%02d %02d:%02d:%02d\n", first.year, first.month, first.day, first.hour, first.minute, first.second);
    // printf("%04d-%02d-%02d %02d:%02d:%02d\n", second_.year, second_.month, second_.day, second_.hour, second_.minute, second_.second);

    printf("%04d-%02d-%02d %02d:%02d:%02d", ans.year, ans.month, ans.day, ans.hour, ans.minute, ans.second);

    return 0;
}