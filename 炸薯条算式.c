#include <stdio.h>

typedef struct stack
{
    int data[100];
    int top;
}stack;

int id, ans[29] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 6, 11, 18, 22, 45, 63, 104, 102, 205, 267, 610, 924, 1677, 2271, 3865, 5429};
stack a;

int main()
{
    a.top = 0;
    while(scanf("%d", &id) != EOF){
        if(id > a.top - 1){
            for(int i = a.top; i <= id; i++, a.top++){
                a.data[a.top] = ans[i];
            }
            printf("%d\n", a.data[id]);
        } else {
            printf("%d\n", a.data[id]);
        }
    }
    return 0;
}