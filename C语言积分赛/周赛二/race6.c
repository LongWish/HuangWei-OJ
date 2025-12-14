// 这份代码是错的，但可以在OJ上编译通过。你需要在它的基础上完善work()函数。
// attentionIsAllYouNeed.h 头文件提供了函数int move(int x);
#include "attentionIsAllYouNeed.h"
// 你需要实现函数void work();

#define U 0
#define R 1
#define D 2
#define L 3

int now_direct = 0;

int hash_r(int direct){
    return (direct + 1) % 4;
}

int hash_l(int direct){
    return (direct + 3) % 4;
}

void work(){
    // move(0) 示例：让小A往上移动一步
    // 0：向上，1：向右，2：向下，3：向左
    while(move(hash_r(now_direct)) == 0){
        now_direct = hash_l(now_direct);
    }
    now_direct = hash_r(now_direct);

    return;
}
// 不需要你自己写main函数！！！！千万不要自己写main函数！！！否则OJ会编译失败！！！