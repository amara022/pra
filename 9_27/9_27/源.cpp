#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<stdlib.h>
//需要移动交换数组
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
bool dupulcation1(int arr[],int length)
{
	if (arr == nullptr || length <= 0)
		return false;
	for (int i = 0; i < length; i++)
	{
		if (arr[i]<0 && arr[i]>length - 1)
			return false;
	}
	for (int i = 0; i < length;i++)
	{
		while (arr[i] != 0)
		{
			if (arr[i] == arr[arr[i]])
				return true;
			swap(arr[i], arr[arr[i]]);
		}
	}
	return false;
}
//不修改，二分查看
int GetCount(const int *arr, int length, int begin, int end)
{
	if (arr == nullptr)
		return 0;
	int count = 0;
	for (int i = 0; i < length; i++)
		if (arr[i] >= begin&&arr[i] <= end)
			++count;
	return count;
}
int dupulcation2(const int arr[], int length)
{
	if (arr == nullptr || length <= 0)
		return -1;
	int begin = 1;
	int end = length - 1;
	while (end >= begin)
	{
		int mid = ((end - begin) >> 1) + begin;
		int count = GetCount(arr, length, begin, mid);
		if (end == begin)
		{
			if (count > 1)
				return begin;
			else
				break;
		}
		if (count > (mid - begin) + 1)
			end = mid;
		else
			begin = mid + 1;
	}
	return -1;
}
int main()
{
	int arr[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	cout << dupulcation2(arr[], sizeof(arr)) << endl;
	system("pause");
	return 1;
}