#include <stdio.h>
#include <string.h>
#define SIZE 1001

int m, n, a[110][110];
char ans[SIZE][SIZE] = {0}, cube[10][10]={
"+---+",
"|   |/",
"|   | +",
"+---+ |",
"\0/   /|",
"\0\0+---+",
};

void draw(int x, int y){
    for(int h = 0; h < a[x][y]; h++){
        for(int j=0; j<=8; j++){
            for(int i=0; i<=8; i++){
                if(cube[j][i]!=0){
                    ans[j+2*(m-1-x)+3*h][4*y+2*(m-1-x)+i] = cube[j][i]; 
                }
            }
        }
    }
}

void print() {
    int max_i = 0, max_j = 0;
    
    for(int j = 0; j < SIZE; j++) {
        for(int i = 0; i < SIZE; i++) {
            if(ans[j][i] != '.') {
                if(j > max_j) max_j = j;
                if(i > max_i) max_i = i;
            }
        }
    }
    
    for(int j = max_j; j >= 0; j--) {
        for(int i = 0; i <= max_i; i++) {
            printf("%c", ans[j][i]);
        }
        printf("\n");
    }
}

int main() {
    memset(ans, '.', sizeof(ans));
    scanf("%d%d",&m,&n);
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            scanf("%d",&a[i][j]);

    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++)
    //         printf("%d ",a[i][j]);
    //     printf("\n");
    // }
    
    for(int j=0; j<n; j++){
        for(int i=0; i<m; i++){
            draw(i, j);
        }
    }

    print();
    return 0;
}