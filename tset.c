#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void meun()//起始游戏
{
	printf("________________\n");
	printf("____1-play______\n");
	printf("____0-exit______\n");
	printf("________________\n");
	printf("请选择:");
}
void game()
{
	/*printf("开始游戏");*/
	//创建棋盘对应的数组
	char mine[ROWS][COLS];//存放布置好的雷的信息
	char show[ROWS][COLS];//存放排查出来雷的信息

	//初始化棋盘
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show, ROWS, COLS,'*');

	//打印棋盘
	DisplayBaord(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL, EASY_COUNT);

	//排查雷
	FindMine(mine, show, ROW, COL);
}
int main()
{
	int n = 0;
	srand((unsigned int)time(NULL));
	do
	{
		meun();
		scanf("%d", &n);
		switch(n)
		{
		    case 1:
				game();
				break;
			case 0:
				printf("退出游戏");
				break;
			default:
				printf("输入错误，请重新输入:\n");
				break;
		}
	} while (n);
	system("pause");
	return 0;
}