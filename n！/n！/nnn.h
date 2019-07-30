#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
using namespace std;

class Temp{
public:
	static unsigned int N;
	static unsigned int Sum;
	Temp(){ ++N; Sum += N; }
};
//静态变量在这里只能算是定义，不能算是初始化
unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

class Solution {
public:
	int Sum_Solution(int n) {

		//静态变量初始化
		Temp::N = 0;
		Temp::Sum = 0;

		Temp *a = new Temp[n];
		delete[] a;
		a = NULL;

		return Temp::Sum;
	}
};
void test()
{
	Solution A;
	cout<<A.Sum_Solution(5)<<endl;
}