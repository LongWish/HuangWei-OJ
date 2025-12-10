#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//预编译指令，根据不同系统获取对应头文件并记录终端状态（用于恢复）
#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>
    static DWORD original_console_mode = 0;
    static HANDLE hConsole = INVALID_HANDLE_VALUE;
#else
    #include <termios.h>
    #include <unistd.h>
    static struct termios original_termios;
#endif

#define BOARDSIZE 20

//定义数据体记录游戏的储存方式
typedef struct{
    int board[BOARDSIZE][BOARDSIZE];//记录棋盘
    int score;//记录当前分数
    //记录输赢状态
    int won;
    int lose;
}game_state;

//枚举用户输入方式
typedef enum{
    MOVE_UP,
    MOVE_DOWN,
    MOVE_RIGHT,
    MOVE_LEFT,
    QUIT,
}directions;

//只获取一次随机种子，若已获得过则不再生成时间种子（不然随机数会不随机，除非获取时间间隔更短）
void random_seed(void)
{
    static int seed_stat = 0;
    if(!seed_stat)
    {
        srand((unsigned)time(NULL));
        seed_stat = 1;
    }
}

//添加随机的（4/2）方块
void add_random_tile(game_state *game)
{
    //记录所有空闲的方块坐标【r】【c】以及空闲的方块坐标数
    int empty_cell[BOARDSIZE * BOARDSIZE][2];
    int empty_count = 0;
    for(int r = 0; r < BOARDSIZE; r++)
    {
        for(int c = 0; c < BOARDSIZE; c++)
        {
            if(game->board[r][c] == 0)
            {
                empty_cell[empty_count][0] = r;
                empty_cell[empty_count][1] = c;
                empty_count++;
            }
        }
    }
    if(empty_count == 0) return;//不再有可随机的方块的情况下退出函数
    int idx = rand() % empty_count;//随机选择一个坐标
    int val = (rand() % 10 == 0) ? 4 : 2;// 90%概率生成2，10%概率生成4
    game->board[empty_cell[idx][0]][empty_cell[idx][1]] = val;//在随机出来的坐标赋值随机出来的值（4/2）
}

//在最开始初始化游戏记录
void init_game(game_state *game)
{
   random_seed();//获取随机数种子
   memset(game, 0, sizeof(game_state));//将棋盘 state，分数 score，输赢状态 won lose 全部格式化为 0
   //随机生成两个板块
   add_random_tile(game);
   add_random_tile(game);
}

//实现多平台终端清屏
void clear_screen(void)
{
    //预编译指令，若存在_WIN32则编译 cls，否则编译 clear，实现多平台终端清屏
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

//从 game 的游戏状态库中构建棋盘
void print_board(game_state *game)
{
    printf("\n");
    for(int i = 0; i < BOARDSIZE; i++) printf("+------");
    printf("+\n");
    for (int r = 0; r < BOARDSIZE; ++r)
    {
        printf("|");
        for (int c = 0; c < BOARDSIZE; ++c)
        {
            if (game->board[r][c] == 0)
            {
                printf("      |");
            } 
            else
            {
                printf("%6d|", game->board[r][c]);
            }
        }
        printf("\n");
        for(int i = 0; i < BOARDSIZE; i++) printf("+------");
        printf("+\n");
    }
}

//设置无缓冲模式
void set_terminal(void)
{
    #ifdef _WIN32
        hConsole = GetStdHandle(STD_INPUT_HANDLE);
        GetConsoleMode(hConsole, &original_console_mode);
        // 禁用 ENABLE_ECHO_INPUT 和 ENABLE_LINE_INPUT（相当于 ECHO + ICANON）
        SetConsoleMode(hConsole, original_console_mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
    #else
        tcgetattr(STDIN_FILENO, &original_termios);
        struct termios raw = original_termios;
        raw.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &raw);
    #endif
}

//解除无缓冲模式
void reset_terminal(void)
{
    #ifdef _WIN32
    if (hConsole != INVALID_HANDLE_VALUE) {
        SetConsoleMode(hConsole, original_console_mode);
    }
    #else
        tcsetattr(STDIN_FILENO, TCSANOW, &original_termios);
    #endif
}

//处理为无缓冲模式并获取输入
directions get_input(void)
{
    set_terminal();
    printf("w(up),s(down),a(left),d(right),q(quit)\n");
    char c;
    while(1)
    {
        c = getchar();
        if(c == 'w' || c == 'W') { reset_terminal(); return MOVE_UP; }
        if(c == 's' || c == 'S') { reset_terminal(); return MOVE_DOWN; }
        if(c == 'a' || c == 'A') { reset_terminal(); return MOVE_LEFT; }
        if(c == 'd' || c == 'D') { reset_terminal(); return MOVE_RIGHT; }
        if(c == 'q' || c == 'Q') { reset_terminal(); return QUIT; }
    }
}

// 检查是否还有可用移动
int has_moves(game_state *game) {
    // 检查是否有空位
    for (int r = 0; r < BOARDSIZE; ++r) {
        for (int c = 0; c < BOARDSIZE; ++c) {
            if (game->board[r][c] == 0) {
                return 1;
            }
        }
    }
    // 检查是否有可合并的相邻数字
    for (int r = 0; r < BOARDSIZE; ++r) {
        for (int c = 0; c < BOARDSIZE; ++c) {
            if ((c + 1 < BOARDSIZE && game->board[r][c] == game->board[r][c + 1]) ||
                (r + 1 < BOARDSIZE && game->board[r][c] == game->board[r + 1][c])) {
                return 1;
            }
        }
    }
    return 0;
}

//移动函数：将一行元素向左合并（如有 0 则抹平，如相邻两者相同则相加）
int slide_tiles(int column[BOARDSIZE])
{
    int score = 0;
    int filtered[BOARDSIZE] = {0};
    int filter_count = 0;
    for(int i = 0; i < BOARDSIZE; i++)//从原本的 column 中去除所有的 0 位
    {
        if(column[i] != 0)
        {
            filtered[filter_count++] = column[i];
        }
    }
    int merged[BOARDSIZE] = {0};
    int merge_idx = 0;
    for(int i = 0; i < BOARDSIZE; i++)//合并所有相同的（从左向右的优先级）
    {
        if(i + 1 < filter_count && filtered[i] == filtered[i + 1])
        {
            merged[merge_idx++] = filtered[i] * 2;
            score += filtered[i] * 2;
            i++;
        }
        else
        {
            merged[merge_idx++] = filtered[i];
        }
    }
    while(merge_idx < BOARDSIZE)
    {
        merged[merge_idx++] = 0;
    }
    memcpy(column, merged, sizeof(int) * BOARDSIZE);
    return score;//返回得分
}

//处理向上移动
void move_up(game_state *game)
{
    for(int c = 0; c < BOARDSIZE; c++)//逐列取出
    {
        int column[BOARDSIZE];
        for(int r = 0; r < BOARDSIZE; r++)//一列中的各元素赋值
        {
            column[r] = game->board[r][c];
        }
        game->score += slide_tiles(column);//应用移动函数，同时获取分数并加入总分
        for(int r = 0; r < BOARDSIZE; r++)
        {
            game->board[r][c] = column[r];
        }
    }
    return;
}

//处理向下移动
void move_down(game_state *game)
{
    for(int c = 0; c < BOARDSIZE; c++)//逐列取出
    {
        int column[BOARDSIZE];
        // 从下往上取出，这样 slide_tiles 向左合并就相当于向下合并
        for(int r = 0; r < BOARDSIZE; r++)
        {
            column[r] = game->board[BOARDSIZE - 1 - r][c];
        }
        game->score += slide_tiles(column);//应用移动函数，同时获取分数并加入总分
        // 再反向放回
        for(int r = 0; r < BOARDSIZE; r++)
        {
            game->board[BOARDSIZE - 1 - r][c] = column[r];
        }
    }
    return;
}

//处理向左移动
void move_left(game_state *game)
{
    for (int r = 0; r < BOARDSIZE; r++)
    {
        game->score += slide_tiles(game->board[r]);
    }
    return;
}

//处理向右移动
void move_right(game_state *game)
{
    for (int r = 0; r < BOARDSIZE; r++)
    {
        int row[BOARDSIZE];
        // 反向取出行元素
        for (int c = 0; c < BOARDSIZE; c++)
        {
            row[c] = game->board[r][BOARDSIZE - 1 - c];
        }
        game->score += slide_tiles(row);
        // 再反向放回
        for (int c = 0; c < BOARDSIZE; c++)
        {
            game->board[r][BOARDSIZE - 1 - c] = row[c];
        }
    }
    return;
}

//向 game 结构体应用用户移动结果
void apply_move(game_state *game, directions move)
{
    if(game->lose || game->won) return;
    int changed = 0;
    switch(move)
    {
        case MOVE_UP:
            move_up(game);
            changed = 1;
            break;
        case MOVE_DOWN:
            move_down(game);
            changed = 1;
            break;
        case MOVE_LEFT:
            move_left(game);
            changed = 1;
            break;
        case MOVE_RIGHT:
            move_right(game);
            changed = 1;
            break;
        case QUIT:
            game->lose = 2;
            break;
    }
    if(changed)
    {
        add_random_tile(game);
        // 检查是否赢得游戏
        for (int r = 0; r < BOARDSIZE; r++)
        {
            for (int c = 0; c < BOARDSIZE; c++)
            {
                if (game->board[r][c] == 2048)
                {
                    game->won = 1;
                }
            }
        }
        game->lose = !has_moves(game);
    }
    return;
}

int main()
{
    //建立并初始化棋盘
    game_state game;
    init_game(&game);
    while(!game.won && !game.lose)//当游戏并未结束
    {
        clear_screen();//将屏幕清屏（上一局的内容和分数）
        print_board(&game);//打印出当前的棋盘状态（从 game 中获取）
        printf("得分: %d\n", game.score);//打印出当前的分数
        directions move = get_input();//获取用户输入
        if(move == QUIT)//判断是否主动终止
        {
            reset_terminal();
            printf("Exit Successful");
            return 0;
        }
        apply_move(&game, move);//将用户输入计算并将结果记录入 game
    }
    reset_terminal();//游戏结束后退出无缓存输入模式
    clear_screen();//清屏
    print_board(&game);//打印出最后的棋盘结果
    //输出输赢和得分
    if(game.won)
    {
        printf("Congrats! You've WON! Your score is:%d", game.score);
    }
    else if(game.lose == 1)
    {
        printf("Game Over! You've Lost! Your score is:%d", game.score);
    }
    else if(game.lose == 2)
    {
        printf("Successfully Exited");
    }
    return 0;
}