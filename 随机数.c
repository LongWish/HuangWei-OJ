##include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 设置随机种子（使用当前时间）
    srand((unsigned int)time(NULL));
    
    // 生成1-58的随机数（包含1和58）
    int random_num = rand() % 58 + 1;
    
    printf("随机数: %d\n", random_num);
    return 0;
}