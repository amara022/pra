#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#if 0
int main()
{
	int n;
	cout << "请输入共多少数字" << endl;
	cin >> n;
	while (n)
	{
		cout << "请输入这" << n << "个元素" << endl;
		int arr[10];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		int count = 1;
		//123221
		for (int j = 1; j < (n - 1); ++j)
		{
			if ((arr[j - 1] < arr[j] && arr[j] > arr[j + 1]) || (arr[j - 1]>arr[j] && arr[j] < arr[j - 1]))
			{
				count++;
				if (j != n - 3)
					j++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
#endif

int main()
{
	string str;
	vector<string> v;
	getline(cin, str);
	size_t pos = 0, start = 0;
	while (pos < str.size())
	{
		pos = str.find(' ', start);
		string n = str.substr(start, pos - start);
		v.push_back(n);
		start = pos + 1;
	}
	vector<string>::reverse_iterator it = v.rbegin();
	while (it != v.rend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	return 0;
}

//出现次数超过总数一半
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		int ans = numbers[0];
		int count = 1;
		for (int i = 1; i<numbers.size(); i++)
		{
			if (ans == numbers[i])
				count++;
			else
				count--;
			if (count == 0)
			{
				ans = numbers[i];
				count = 1;
			}
		}
		count = 0;
		for (int i = 0; i<numbers.size(); i++)
		if (numbers[i] == ans)
			count++;

		if (count > numbers.size() / 2)
			return ans;
		else
			return 0;
	}
};