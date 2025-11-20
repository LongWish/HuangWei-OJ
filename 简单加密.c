#include <stdio.h>

#define DISTANCE 'a'-'A'

int main(){
    char asl, tmp[3];
    while(scanf("%s",tmp) != EOF)
    {
        asl = tmp[0];
        if(asl >= 'A' && asl <= 'Z')
            printf("%c\n", asl+(DISTANCE));
        else if(asl >= 'a' && asl <= 'z')
            printf("%c\n", asl-(DISTANCE));
        else if(asl >= '0' && asl <= '8')
            printf("%c\n", asl+1);
        else if(asl == '9')
            printf("0\n");
        else
            printf("%d\n", asl);
    }
    
    return 0;
}

