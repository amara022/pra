#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stdlib.h>

#if 0
//论strlen和sizeof区别
int main()
{
	char *p = "blue1";
	char c[] = "blue1";
	cout << strlen(p) << endl;//5
	cout << strlen(c) << endl;//5
	cout << sizeof(p) << endl;//4
	cout << sizeof(c) << endl;//6
	system("pause");
}
#endif

#if 0
int main()
{
	int s = 0, n;
	for (n = 0; n < 4; n++)
	{
		switch (n)
		{
		default:s += 4;
		case 1:s += 1;
		case 2:s += 2;
		case 3:s += 3;
		}
		cout << s << endl;
		system("pause");
	}
}
#endif

//求数组中一个元素超过数组长度的一半的数字
#include <algorithm>
#include <vector>
int MoreThanHalfNum_Solution(vector<int> numbers)
{
	vector<int>::iterator it = numbers.begin(); 
	sort(it, numbers.end());       
	int mid = numbers.size() / 2;
	int count = 0;
	int size = numbers.size();
	for (int i = 0; i < size; i++)
	{
		if (numbers[mid] == numbers[i])
			count++;
		if (count > size / 2)
			return numbers[mid];
	}
	return 0;
}
int main()
{
	vector<int> ar = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	cout<<MoreThanHalfNum_Solution(ar)<<endl;
	system("pause");
}
