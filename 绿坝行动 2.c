#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char ch, tmp[40] = {0}, blacklist[10][40] = {0}, words[100][40] = {0};
int tmplen = 0, blistlen = 0, wordslen = 0;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while((ch = getchar()) != '\n') {
        if(ch == ' ') {
            for(int i=0; i<tmplen ; i++) {
                tmp[i] = tolower(tmp[i]);
            }
            tmp[tmplen] = '\0';
            tmplen = 0;
            strcpy(blacklist[blistlen], tmp);
            blistlen++;
        } else {
            tmp[tmplen++] = ch;
        }
    }
    for(int i=0; i<tmplen ; i++) {
        tmp[i] = tolower(tmp[i]);
    }
    tmp[tmplen] = '\0';
    tmplen = 0;
    strncpy(blacklist[blistlen], tmp, 40);
    blistlen++;

    //deal
    while((ch = getchar()) != EOF && ch != '\n' && ch != '\r') {
        if(ch == ' ') {
            words[wordslen][tmplen] = '\0';
            tmplen = 0;
            wordslen++;
        } else {
//            printf("check\n");
            words[wordslen][tmplen++] = ch;
        }
    }
    words[wordslen][tmplen] = '\0';
    tmplen = 0;
    wordslen++;
//    printf("check\n");
//    for(int i =0; i<wordslen; i++){
//        printf("%s\n", words[i]);
//    }

    //check
    int space = 1, is_black = 0;
    for(int i=0; i<wordslen; i++){
        is_black = 0;
        memset(tmp, 0, sizeof(tmp));
//        printf("%d ", strlen(words[i]));
        int len = strlen(words[i]);
        for(int j=0; j<len ; j++) {
            tmp[j] = tolower(words[i][j]);
        }
        tmp[strlen(words[i])] = '\0';
        for(int j=0; j<blistlen; j++){
            // printf("check:%s\n",tmp);
            if(strcmp(tmp, blacklist[j]) == 0){
                is_black = 1;
                break;
            }
        }

        if(is_black){
            printf(space?"*":" *");
        }
        else{
            printf(space?"%s":" %s", words[i]);
        }
        space = 0;
    }

    return 0;
}