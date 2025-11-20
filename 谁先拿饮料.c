#include <stdio.h>
#include <string.h>
#define SIZE 1001

int m, n, point, first;
char a[SIZE];

int main() {
    while(scanf("%d%d", &n, &m) != EOF)
    {
        point = 0, first = 1;
        memset(a, 1, sizeof(a));
        for(int i = 0; i < n; i++){
            for(int j=0; j<m; j++){
                point++;
                if(point == n+1)    point = 1;
                if(a[point] == 0)   j--;
            }
            printf(first?"%d":" %d", point);
            first = 0;
            a[point] = 0;
        }
        printf("\n");
    }
    
    return 0;
}