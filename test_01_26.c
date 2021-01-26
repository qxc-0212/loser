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
	//printf("请输入两个值:");
	//scanf("%d%d",&m,&n);
	//int r=m^n;//异或，不同的地方为1
	//int i = 0;//不同地方的个数
	//while (r)
	//{
	//	r = r&(r - 1);
	//	i++;
	//}
	//printf("这两个数有%d不同",i);
	int intput = 0;
	printf("请输入一个数:");
	scanf("%d",&intput);
	printf("奇数位:");
	for (int i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (intput >> i) & 1);
	}
	printf("\n");
	printf("偶数位:");
	for (int i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (intput >> i) & 1);
	}
	system("pause");
	return 0;
}