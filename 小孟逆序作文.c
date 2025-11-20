#include <stdio.h>
#include <string.h>

char ch, temp[101] = {0};
int is_record = 0, top = 0;

int main() {
    freopen("out.txt", "w", stdout);
    while((ch = getchar()) != EOF)
    {
        if(ch == '#' && is_record == 0){
            getchar();
            is_record = 1;
            continue;
        }
        if(ch == '#' && is_record == 1){
            getchar();
            memset(temp, 0, sizeof(temp));
            is_record = 0;
            top = 0;
            continue;
        }
        if(ch != '#' && is_record == 1){
            if(ch != '\n' && ch != ' ' && ch != '\t' && ch != '\r'){
                temp[top] = ch;
                top++;
            }
            else{
                for(int i = top-1; i>=0; i--){
                    printf("%c", temp[i]);
                }
                printf("%c", ch);
                top = 0;
                memset(temp, 0, sizeof(temp));
            }
        }
    }
    
    return 0;
}