#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void meun()//��ʼ��Ϸ
{
	printf("________________\n");
	printf("____1-play______\n");
	printf("____0-exit______\n");
	printf("________________\n");
	printf("��ѡ��:");
}
void game()
{
	/*printf("��ʼ��Ϸ");*/
	//�������̶�Ӧ������
	char mine[ROWS][COLS];//��Ų��úõ��׵���Ϣ
	char show[ROWS][COLS];//����Ų�����׵���Ϣ

	//��ʼ������
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show, ROWS, COLS,'*');

	//��ӡ����
	DisplayBaord(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL, EASY_COUNT);

	//�Ų���
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
				printf("�˳���Ϸ");
				break;
			default:
				printf("�����������������:\n");
				break;
		}
	} while (n);
	system("pause");
	return 0;
}