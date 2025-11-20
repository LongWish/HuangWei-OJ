#include <stdio.h>
#include <string.h>

char str[1000];
int in_code = 0, had_enter = 0, len, started = 0, in_marking = 0, inbrack = 0;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(fgets(str, 1000, stdin) != NULL)
    {
        len = strlen(str);
        if(len > 0 && str[len - 1] == '\n')     str[--len] = '\0';
        if(strcmp(str, "###") == 0){
            // printf("check: %s\n", str);
            in_code = !in_code;
            had_enter = 0, started = 0, in_marking = 0, inbrack = 0;
            continue;
        }
        if(in_code){
            if(!in_marking && len == 0){
                if(started == 0)    continue;
                if(started == 1 && had_enter == 0){
                    had_enter = 1;
                    continue;
                }
            }
            else{
                int had_content = 0;
                for(int point = 0; point <= len-1; point++){
                    if(str[point] == '/'){
                        if(in_marking == 0 && str[point + 1] == '/'){
                            break;
                        }
                        else if(in_marking == 0 && str[point + 1] == '*'){
                            in_marking = 1;
                            point += 2;
                            continue;
                        }
                        else if(in_marking == 1 && str[point - 1] == '*'){
                            // printf("check");
                            in_marking = 0;
                            continue;
                        }
                        else if(!in_marking){
                            if(had_enter == 1){
                                if(inbrack > 0) printf("\n");
                                had_enter = 0;
                            }
                            putchar('/');
                            had_content = 1;
                            continue;
                        }
                    }

                    if(str[point] == '{')       inbrack++;
                    else if(str[point] == '}')  inbrack--;

                    if(!in_marking){
                        started = 1;
                        if(had_enter == 1){
                            if(inbrack > 0) printf("\n");
                            had_enter = 0;
                        }
                        putchar(str[point]);
                        had_content = 1;
                    }
                }
                // if(flag == 1 && !in_marking)    putchar(str[len - 1]);
                if(had_content == 1 && had_enter == 0)  printf("\n");
            }
        }
    }
    
    return 0;
}