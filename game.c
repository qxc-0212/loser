#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
//��ʼ��
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
//��ӡ
void DisplayBaord(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("*********ɨ����Ϸ*********\n");
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
//������
void SetMine(char mine[ROWS][COLS], int row, int col, int count)
{
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % row + 1;
		if (mine[x][y] == '0')
		{
			//x,y����û����
			mine[x][y] = '1';
			count--;
		}
	}
}

//�Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	while (win<row*col-EASY_COUNT)
	{
		printf("������Ҫ�Ų������:");
		int x = 0;
		int y = 0;
		scanf("%d%d", &x, &y);
		//1.���������
		//2.�������ǲ����ף������ף�ͳ����Χ�׵ĸ���
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը����\n");
				DisplayBaord(mine, row, col);
				break;
			}
			else
			{
				//�����ף�ͳ����Χ�׵ĸ���
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				DisplayBaord(show, row, col);
				win++;
			}
		}
		else
		{
			printf("����Ƿ�������������!\n");
		}
	}
	if (win == row*col - EASY_COUNT)
	{
		printf("��ϲ�����׳ɹ�!\n");
		DisplayBaord(mine, row, col);
	}
}
//ͳ����
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] +
		mine[x - 1][y] + mine[x + 1][y] +
		mine[x - 1][y + 1] + mine[x][y + 1] + mine[x + 1][y + 1] -
		8 * '0';
}