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
//������int myminus(int,double)��: ���غ����롰double myminus(int,double)��ֻ���ڷ��������ϲ�ͬ
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
