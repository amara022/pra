#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<stdlib.h>

//左到右，上到下递增的二维数组
bool Findnum(int *arr,int rows,int cols, int n)
{
	bool find = false;
	if (arr != nullptr&&rows > 0 && cols > 0)
	{
		int row = 0;
		int col = cols - 1;
		while (col >= 0 && row<rows)
		{
			if (arr[row*cols + col] == n)
			{
				find = true;
				break;
			}
			else if (arr[row*cols + col] > n)
				col--;
			else
				row++;	
		}
	}
	return find;
}

//把字符串指针转为%20

void ReplaceBlank(char str[], int length)
{
	if (str == nullptr || length <= 0)
		return;
	int num = 0;
	int orginal = 0;
	int i = 0;
		while (str[i] != '\0')
		{
			orginal++;
			if (str[i] == ' ')
				num++;
			i++;
		}
		int newlen = orginal + 2 * num;
		if (newlen > length)
			return;
		int old = orginal;
		int newd = newlen;
		while (old >= 0 && newd > old)
		{
			if (str[old] == ' ')
			{
				str[newd--] = '0';
				str[newd--] = '2';
				str[newd--] = '%';
			}
			else
				str[newd--] = str[old];
			old--;
		}

	}
int main()
{
	int arr[4][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	if (Findnum(*arr, 4, 4, 7))
		cout << "找到" << endl;
	else
		cout << "没找到" << endl;
	const int length = 100;
	char str[length] = { "I LOVE CHINA" };
	ReplaceBlank(str, length);
	cout << str << endl;
	system("pause");
	return 0;
}