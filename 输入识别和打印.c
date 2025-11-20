#include <stdio.h>
#include <string.h>

char tmp[200], title[100], name[100], tel[100];

int main() {
    while(fgets(tmp, sizeof(tmp), stdin) != NULL)
    {
        tmp[strlen(tmp)-1] = '\0';
        if(strncmp(tmp, "Name: ", 6) == 0){
            strcpy(name, tmp + 6);
        }
        else if(strncmp(tmp, "Title: ", 7) == 0){
            strcpy(title, tmp + 7);
        }
        else if(strncmp(tmp, "TEL: ", 5) == 0){
            strcpy(tel, tmp + 5);
        }
    }
    printf("%s %s's telephone number is %s.", title, name, tel);

    return 0;
}