
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EASY_COUNT 10//雷的个数
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
//初始化
void InitBoard(char board[ROWS][COLS], int rows, int cols, char star);
//打印棋盘
void DisplayBaord(char board[ROWS][COLS], int row, int col);
//布置雷
void SetMine(char mine[ROWS][COLS], int row, int col, int count);
//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//统计雷
int GetMineCount(char mine[ROWS][COLS], int x, int y);