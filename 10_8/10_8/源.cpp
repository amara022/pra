#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//���һ�����ֵĶ�������1�ĸ���

class Solution{
public:
//ѭ���������ڶ�����λ��
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
//��������n������
//while(n)
//{if(n&1)
//	count++;
//n = n >> 1;
//}
//����Ǹ������ƣ�Ҫ��֤���ƺ���Ȼ�Ǹ���������������ѭ��
//������Ȼ�����������ͬ��������Ч�ʸ��߲����黻�ɳ���
//ѭ�������Ƕ�������1�ĸ���
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
	//�����ʹ�ñ���newһ��������ֻ��һ��ģ��
	A->n= 10;
	cout << A->Get1() << endl;
	cout << A->Getnumber1() << endl;
}