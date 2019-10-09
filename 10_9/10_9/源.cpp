#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

int GetMyPower(int a, int n)
{
	int result = 1;
	for (int i = 0; i < n; i++)
	{
		result *= n;
	}
	return result;
}

int GetMyPower2(int a, int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return a;
	int result = GetMyPower2(a, n >> 1);
	result *= result;
	if (n &0x1 == 1)
		//ЧѓгрдЫЫу
		result *= a;
	return result;
}

int main()
{
	cout << GetMyPower(2, 2) << endl;
	cout << GetMyPower2(2, 5) << endl;
	return 0;
}