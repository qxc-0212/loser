#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//int putfor(int n)
//{
//
//}
int main()
{
	//int m = 0;
	//int n = 0;
	//printf("����������ֵ:");
	//scanf("%d%d",&m,&n);
	//int r=m^n;//��򣬲�ͬ�ĵط�Ϊ1
	//int i = 0;//��ͬ�ط��ĸ���
	//while (r)
	//{
	//	r = r&(r - 1);
	//	i++;
	//}
	//printf("����������%d��ͬ",i);
	int intput = 0;
	printf("������һ����:");
	scanf("%d",&intput);
	printf("����λ:");
	for (int i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (intput >> i) & 1);
	}
	printf("\n");
	printf("ż��λ:");
	for (int i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (intput >> i) & 1);
	}
	system("pause");
	return 0;
}