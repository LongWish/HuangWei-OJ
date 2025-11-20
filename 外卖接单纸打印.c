#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 40

int len, tmp, dish, num;
double price[6] = {7, 4, 3, 2.5, 2.5, 1}, sum_ = 4.0;
char str[LEN], *point;
char dishes[6][LEN] = {"Fried beef pepper", "Lotus root soup", "Dried bean curd", "Potato", "Sauteed lettuce", "Rice"};
char code[6][LEN] = {"Fried beef pepper   ", "Lotus root soup     ", "Dried bean curd     ", "Potato              ", "Sauteed lettuce     ", "Rice                "};

void quit(){
    str[strlen(str) - 1] = 0;
}

int main() {
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    printf("        #1 MT Takeaway\n\n");
    fgets(str, LEN, stdin);
    quit();
    len = strlen(str);
    tmp = (30 - len -2) / 2;
    for(int i=0; i < tmp; i++){
        printf("-");
    }
    printf(" ");
    printf("%s", str);
    printf(" ");
    tmp = (len % 2 == 0) ? tmp : tmp + 1;
    for(int i=0; i < tmp; i++){
        printf("-");
    }
    printf("\n");

    while(fgets(str, LEN, stdin) != NULL)
    {
        quit();
        point = NULL;
        for(int i=0; point == NULL; i++){
            point = strstr(str, dishes[i]);
            dish = i;
        }
        
        printf("%s", code[dish]);
        sscanf(str, strcat(dishes[dish], " %d"), &num);
        sum_ += price[dish] * num;
        printf("x%-2d%5.1lf\n", num, price[dish] * num);
    }
    printf("Delivery fees: 4\n------------------------------\n");
    for(int i=0;i < 16; i++)    printf(" ");
    printf("Total:%6.1lf", sum_);
    return 0;
}