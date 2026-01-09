#include <stdio.h>

void printsize(int ar[3])
{
    printf("%llu ",sizeof ar);
}

int main() {
    int arr2[39];
    int arr[10];
    // int a[2][3]={{1,0,1},{5,2,3}};
    // int b[][3]={{1,2,3},{4,5,6}};
    // int c[2][3]={{1,2,3},{4,5}};
    // int d[][3]={{1,0,1},{},{1,1}};
    // int e[][] = {{1,2,3},{}};
    
    // int arr[10][30];
    // int (*ptarr)[10][30] = &arr; // 正确
    // int (*parr)[30] = arr;       // 正确
    printsize(arr);
    printsize(arr2);

    return 0;
}