#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//获得一个数字的二进制中1的个数

class Solution{
public:
//循环次数等于二进制位数
	int Get1()
{
	int count = 0;
	int flag = 1;
	while (flag)
	{
		if (n&flag)
			count++;
		flag = flag << 1;
	}
	return count;
}
//不可适用n来右移
//while(n)
//{if(n&1)
//	count++;
//n = n >> 1;
//}
//如果是负数右移，要保证右移后仍然是个负数，会陷入死循环
//右移虽然与除法作用相同，但右移效率更高不建议换成除法
//循环次数是二进制中1的个数
int Getnumber1()
{
	int count = 0;
	while (n)
	{
		++count;
		n = n&(n - 1);
	}
	return count;
}
int n;
};
int main()
{
	Solution *A = new Solution;
	//对象的使用必须new一个，否则只是一个模型
	A->n= 10;
	cout << A->Get1() << endl;
	cout << A->Getnumber1() << endl;
}