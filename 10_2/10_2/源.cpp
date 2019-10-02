#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
//旋转数组找最小数字
int Find(int* arr,int length)
{
	if (arr == nullptr || length <= 0)
		return -1;
	int result = arr[0];
	for (int i = 0; i < length;++i)
	{
		if (arr[i]>arr[i + 1])
			result = arr[i + 1];
	}
	return result;
}
//这个方法的时间复杂度为O(n)，并没有用到旋转数组的特性，不推荐使用

int FindMin(int* arr, int p1, int p2)
{
	int result = arr[p1];
	for (int i = p1 + 1; i <= p2; ++i)
	{
		if (arr[i] < result)
			result = arr[i];
	}
	return result;
}

int Min(int* arr, int length)
{
	if (arr == nullptr || length <= 0)
		return -1;
	int p1 = 0;
	int p2 = length - 1;
	int mid = 0;
	while (arr[p1]>arr[p2])
	{
		if (p2 - p1 == 1)
		{
			mid = p2;
			break;
		}
		mid = (p1 + p2) / 2;
		if (arr[p1] == arr[mid] && arr[mid] == arr[p2])
		{
			return FindMin(arr, p1, p2);
		}
		if (arr[mid]>arr[p1])
			p1 = mid;
		else if (arr[mid] < arr[p2])
			p2 = mid;

	}
	return arr[mid];
}

int main()
{
	int arr[5] = { 3, 4, 5, 1, 2 };
	cout << Min(arr, 5) << endl;
	cout << Find(arr, 5) << endl;
	return 0;
}