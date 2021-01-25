#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
//初始化
void InitBoard(char board[ROWS][COLS], int rows, int cols, char star)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = star;
		}
	}
}
//打印
void DisplayBaord(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("*********扫雷游戏*********\n");
	for (i = 0; i < row; i++)
	{
		printf(" %d", i);
	}
	printf("\n");
	for (i = 1; i < row; i++)
	{
		printf(" %d", i);
		for (j = 1; j < col; j++)
		{
			printf(" %c", board[i][j]);
		}
		printf("\n");
	}
}
//布置雷
void SetMine(char mine[ROWS][COLS], int row, int col, int count)
{
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % row + 1;
		if (mine[x][y] == '0')
		{
			//x,y坐标没有雷
			mine[x][y] = '1';
			count--;
		}
	}
}

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	while (win<row*col-EASY_COUNT)
	{
		printf("请输入要排查的坐标:");
		int x = 0;
		int y = 0;
		scanf("%d%d", &x, &y);
		//1.坐标合理性
		//2.该坐标是不是雷？不是雷，统计周围雷的个数
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBaord(mine, row, col);
				break;
			}
			else
			{
				//不是雷，统计周围雷的个数
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				DisplayBaord(show, row, col);
				win++;
			}
		}
		else
		{
			printf("坐标非法，请重新输入!\n");
		}
	}
	if (win == row*col - EASY_COUNT)
	{
		printf("恭喜你排雷成功!\n");
		DisplayBaord(mine, row, col);
	}
}
//统计雷
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] +
		mine[x - 1][y] + mine[x + 1][y] +
		mine[x - 1][y + 1] + mine[x][y + 1] + mine[x + 1][y + 1] -
		8 * '0';
}