#include<stdio.h>

void test()
{
	int i = 0;
	int j = 0;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j <= i; j++)
		{
			int ret = i*j;
			printf("%d*%d=%-3d ",i,j, ret);
		}
		printf("\n");
	}
}
