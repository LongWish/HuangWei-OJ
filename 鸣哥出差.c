#include <stdio.h>

typedef struct {
    int hour;
    int minute;
} Time;

Time intToTime(int timeInt) {
    Time t;
    t.hour = timeInt / 100;
    t.minute = timeInt % 100;
    return t;
}

int timeDifference(Time start, Time end) {
    int startTotal = start.hour * 60 + start.minute;
    int endTotal = end.hour * 60 + end.minute;
    return endTotal - startTotal;
}

int main() {
    int hour, minites;
    
    while (scanf("%d %d", &hour, &minites) == 2) {
        Time departure = intToTime(hour);
        Time arrival = intToTime(minites);
        
        int sum = timeDifference(departure, arrival);
        
        int hours = sum / 60;
        int minutes = sum % 60;

        printf("The train journey time is %d hours %d minutes.\n", hours, minutes);
    }
    
    return 0;
}