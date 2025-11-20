#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char abbr;
    int start_year;
    int start_month;
    int start_day;
    int end_year;
    int end_month;
    int end_day;
} Era;

Era eras[] = {
    {'M', 1868, 9, 8, 1912, 7, 29},
    {'T', 1912, 7, 30, 1926, 12, 24},
    {'S', 1926, 12, 25, 1989, 1, 7},
    {'H', 1989, 1, 8, 2019, 4, 30},
    {'R', 2019, 5, 1, 9999, 12, 31}
};


int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int era_start_days[5];
int era_end_days[5];


int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int get_month_days(int year, int month) {
    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    return month_days[month - 1];
}

int date_to_days(int year, int month, int day) {
    int days = 0;
    
    for (int y = 1868; y < year; y++) {
        days += is_leap_year(y) ? 366 : 365;
    }
 
    for (int m = 1; m < month; m++) {
        days += get_month_days(year, m);
    }

    days += day - 1;
    
    return days;
}


void days_to_date(int days, int *year, int *month, int *day) {
    int y = 1868;
    int remaining = days;
    
    while (1) {
        int year_days = is_leap_year(y) ? 366 : 365;
        if (remaining < year_days) {
            break;
        }
        remaining -= year_days;
        y++;
    }
    
    int m = 1;
    while (m <= 12) {
        int month_days = get_month_days(y, m);
        if (remaining < month_days) {
            break;
        }
        remaining -= month_days;
        m++;
    }
    
    *year = y;
    *month = m;
    *day = remaining + 1;
}


char get_era_by_days(int days, int *era_year) {
    int y, m, d;
    days_to_date(days, &y, &m, &d);
    for (int i = 0; i < 5; i++) {
        if (days >= era_start_days[i] && days <= era_end_days[i]) {
            *era_year = y - eras[i].start_year + 1;
            return eras[i].abbr;
        }
    }
    return '?';
}


int era_date_to_days(char era, int era_year, int month, int day) {
    for (int i = 0; i < 5; i++) {
        if (eras[i].abbr == era) {
            int year = eras[i].start_year + era_year - 1;
            return date_to_days(year, month, day);
        }
    }
    return -1;
}

int main() {
    for (int i = 0; i < 5; i++) {
        era_start_days[i] = date_to_days(eras[i].start_year, eras[i].start_month, eras[i].start_day);
        era_end_days[i] = date_to_days(eras[i].end_year, eras[i].end_month, eras[i].end_day);
    }

    char input[100];
    
    while (fgets(input, sizeof(input), stdin)) {
        if (strlen(input) == 0 || input[0] == '\n') continue;
        
        char era;
        int era_year, month, day, add_days;
        
        if (sscanf(input, " %c%d/%d/%d %d", &era, &era_year, &month, &day, &add_days) == 5) {
            int days = era_date_to_days(era, era_year, month, day);
            
            days += add_days;
            
            int new_year, new_month, new_day;
            days_to_date(days, &new_year, &new_month, &new_day);
            
            int new_era_year;
            char new_era = get_era_by_days(days, &new_era_year);
            
            printf("%c%d/%d/%d\n", new_era, new_era_year, new_month, new_day);
        }
    }
    
    return 0;
}