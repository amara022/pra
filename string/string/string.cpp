#define _CRT_SECURE_NO_WARNINGS 1
#include"prastring.h"
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string>

//获得输入中最后一个单词长度
void getendlenth()
{
	string s;
	while (getline(cin, s))
	{
		int ret=s.substr(s.rfind(' ') + 1).size();
		cout << ret << endl;
	}
}

int main()
{
	test();
//	getendlenth();
	system("pause");
	return 0;
}