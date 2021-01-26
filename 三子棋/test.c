#include"game.h"

void menu()
{
	printf("************************\n");
	printf("*********1.play*********\n");
	printf("*********0.exit*********\n");
	printf("************************\n");
}

void game()
{
	char ret = 0;
	char board[ROW][COL];
	//初始化
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		system("cls");
		DisplayBoard(board, ROW, COL);
		ret = CheckWin(board, ROW, COL);
		if (ret != 'c')
			break;
		//电脑下棋
		ComputerMove(board, ROW, COL);
		system("cls");
		DisplayBoard(board, ROW, COL);
		ret = CheckWin(board, ROW, COL);
		if (ret != 'c')
			break;
	}
	if (ret == '#')
		printf("玩家赢\n");
	else if (ret == '*')
		printf("电脑赢\n");
	else if (ret == 'q')
		printf("和棋\n");
}

int main()
{
	srand((unsigned int)time(NULL));
	int m = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &m);
		switch (m)
		{
		case 1:
			game();//三子棋的游戏
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择!\n");
			break;
		}
	} while (m);
	return 0;
}