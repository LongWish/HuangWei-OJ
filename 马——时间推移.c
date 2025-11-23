#include <stdio.h>

int month_day[13] = {0, 31, 28, 31, 30, 31, 30 ,31, 31, 30, 31, 30, 31};

int is_leap_year(int year)
{
    if((year % 100 == 0 && year % 400 != 0) || year % 4 != 0) return 0;
    else return 1;
}

int days_in_month(int year, int month)
{
    if (month == 2 && is_leap_year(year))
    {
        return 29;
    }
    return month_day[month];
}

long long total_days(int year, int month, int day)
{
    long long total_days = 0;
    for (int y = 1; y < year; y++)
    {
        total_days += is_leap_year(y) ? 366 : 365;
    }
    for (int m = 1; m < month; m++)
    {
        total_days += days_in_month(year, m);
    }
    total_days += (day - 1);
    return total_days;
}

void days_to_date(long long total_days, int *year, int *month, int *day)
{
    *year = 1;
    while (1)
    {
        long long days_in_current_year = is_leap_year(*year) ? 366 : 365;
        if (total_days >= days_in_current_year)
        {
            total_days -= days_in_current_year;
            (*year)++;
        } 
        else
        {
            break;
        }
    }
    *month = 1;
    while (1)
    {
        int days_in_current_month = days_in_month(*year, *month);
        if (total_days >= days_in_current_month)
        {
            total_days -= days_in_current_month;
            (*month)++;
        } 
        else
        {
            break;
        }
    }
    *day = (int)total_days + 1;
}

int main()
{

    int in_year, in_month, in_day, in_hour, in_minute, in_second;
    int delta_day, delta_hour, delta_minute, delta_second;
    char delta_type;
    int out_year, out_month, out_day, out_hour, out_minute, out_second;
    scanf("%d-%d-%d %d:%d:%d %c %d %d:%d:%d", &in_year, &in_month, &in_day, &in_hour, &in_minute, &in_second, &delta_type, &delta_day, &delta_hour, &delta_minute, &delta_second);

    long long in_total_days = total_days(in_year, in_month, in_day);
    long long in_total_seconds = in_total_days * 86400LL + in_hour * 3600LL + in_minute * 60LL + in_second;
    long long delta_total_seconds = delta_day * 86400LL + delta_hour * 3600LL + delta_minute * 60LL + delta_second;

    long long out_total_seconds;
    if(delta_type == '+')
    {
        out_total_seconds = in_total_seconds + delta_total_seconds;
    }
    else if(delta_type == '-')
    {
        out_total_seconds = in_total_seconds - delta_total_seconds;
    }

    long long out_total_days;
    int remaining_seconds;
    if (out_total_seconds >= 0)
    {
        out_total_days = out_total_seconds / 86400LL;
        remaining_seconds = out_total_seconds % 86400;
    } 
    else
    {
        out_total_days = out_total_seconds / 86400LL;
        remaining_seconds = out_total_seconds % 86400;
        if (remaining_seconds < 0)
        {
            out_total_days--;
            remaining_seconds += 86400;
        }
    }
    days_to_date(out_total_days, &out_year, &out_month, &out_day);
    out_hour = remaining_seconds / 3600;
    remaining_seconds %= 3600;
    out_minute = remaining_seconds / 60;
    out_second = remaining_seconds % 60;
    printf("%04d-%02d-%02d %02d:%02d:%02d", out_year, out_month, out_day, out_hour, out_minute, out_second);
    return 0;
}