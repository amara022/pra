#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
#include<stdlib.h>

#if 0
string test(string s)
{
	int c = s.size();
	string res;
	for (int i = 0; i < c; i++)
	{
		if (s[i] == ' ')
			res += "%20";
		else
			res += s[i];
	}
	return res;
}

int main()
{
	string s = "abc defg xyz";
	string ret=test(s);
	cout << ret << endl;
	system("pause");
}
#endif

#if 0
int main()
{
	char a[] = "hello\0world";
	char b[15] = { 0 };
	strcpy(b, a);//b=hello00000...
	cout << strlen(b) << "  " << sizeof(b) << endl;
	system("pause");
}
#endif

#if 0
int Fib(int n)
{
	int res = 0;
	if (n == 0)
		return res;
	if (n == 1 || n == 2)
	{
		res = 1;
		return res;
	}
	if (n > 2)
		return Fib(n - 1) + Fib(n - 2);
	return -1;
}
int fib(int n)
{
	int a1 = 1;
	int a2 = 1;
	int a3 = 0;
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	while (n > 2)
	{
		a3 = a1 + a2;
		a1 = a2;
		a2 = a3;
		n--;
	}
	return a3;
}
int main()
{
	cout << Fib(6) << endl;
	cout << fib(6) << endl;
	system("pause");
}
#endif

