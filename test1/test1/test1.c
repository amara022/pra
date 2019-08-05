#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

#if 0
int main()
{
	int i, j, a = 0;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++);
		{
			if (j % 2)
				break;
			a++;
		}
		a++;
	}
	printf("%d", a);
}
#endif
#if 0
int main(){
	int a[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24 }, *q[4], k;
	for (k = 0; k < 4; k++)
	{
		q[k] = &a[k * 3];
	}
	printf("%d\n", q[3][1]);
	system("pause");
}
#endif

int FindNum(int a[4][4],int rows, int cols, int num)
{
	int i = 0, j = cols - 1;
	
	while (i < rows&&j >= 0)
	{
		if (a[i][j] == num)
			return 1;
		else if (a[i][j]>num)
			j--;
		else
			i++;
	}
	return 0;
}
int main()
{
	int arr[4][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	printf("%d\n", FindNum(arr, 4, 4, 12));
	system("pause");
}