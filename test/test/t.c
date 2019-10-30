#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include<stdio.h>
#include<string.h>

void main()
{
	int years = 20, year = 1999, month = 4, i, j = 0, k = 0, t = 0;
	char number[30] = "452126";
	char name[] = "李笃菊", father[] = "李洋", mother[] = "张美";
	printf("姓名:");
	while (j < 4)
	{
		printf("%c", name[j]);
		j++;
	}
	printf("\n");
	printf("年龄%d\n", years);
	printf("出生年月:%d年%d月\n", year, month);
	printf("身份证号:");
	strcat(number, "451029199904264933");
	puts(number);
	printf("\n");
	printf("\n");

	printf("父子关系:");
	while (k < 4)
	{
		printf("%c", father[k]);
		k++;
	}
	printf("\n");
	printf("母子关系:");
	while (t < 4)
	{
		printf("%c", mother[t]);
		t++;
	}
	scanf("%d", &i);
}
#endif
/*
#include <stdio.h>
void bubble_sort(int arr[], int len)
{
int i, j, temp;
for (i = 0; i < len - 1; i++)
{
	for (j = 0; j<len - 1 - i; j++)
	{
		if (arr[j]>arr[j + 1])
		{
			temp = arr[j]; 
			arr[j] = arr[j + 1]; 
			arr[j + 1] = temp;
		}
	}
}
}
int main()
{
	int arr[] = {27, 42, 45, 35, 66, 88, 75, 965};
	int len = sizeof(arr)/sizeof(arr[1]);
	bubble_sort(arr, len);
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	return 0;
}*/
#include <stdio.h>
void swap(int a[], int i, int j)
{
	int temp = a[i]; 
	a[i] = a[j]; 
	a[j] = temp;
}
void selectionsort(int a[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int min = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[min] > a[j])
				min = j;
				
		}
		swap(a, i, min);
	}
}
int main(){
	int a[] = { 27, 42, 45, 35, 66, 88 };
	int n = sizeof(a) / sizeof(int);
	selectionsort(a, n);
	printf("选择排序结果:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
		
	}printf("\n");
	return 0;
}