#include <stdio.h>

char str[1200];

int main() {
    while(scanf("%s", str) != EOF)
    {
        for(int i=0; str[i]; i++){
            if(str[i] == 'E')       str[i] = 'M';
            else if(str[i] == 'L')  str[i] = 'I';
            else if(str[i] == 'Y')  str[i] = 'S';
            else if(str[i] == 'S')  str[i] = 'A';
            else if(str[i] == 'I')  str[i] = 'K';
            else if(str[i] == 'A')  str[i] = 'I';
        }

        printf("%s\n", str);
    }
    
    return 0;
}