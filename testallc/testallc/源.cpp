#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#if 0
extern "C"int myminus(int a, int b)
{
	return a - b;
}
double myminus(int a, double b)
{
	return a - b;
}
//出错：“int myminus(int,double)”: 重载函数与“double myminus(int,double)”只是在返回类型上不同
//int myminus(int a, double b)
//{
//	return a - b;
//}

double myminus(double a, int b)
{
	return a - b;
}
double myminus(double a, double b)
{
	return a - b;
}
int main()
{
	myminus(10, 5);
	myminus(13, 1.5);
	myminus(10.5, 1.2);
	return 0;
}
#endif
int main()
{
	int a = 10;
	int& ra = a;
	const int& cra = a;
	ra = 5;
	cout << cra<< endl;
	return 0;
}
