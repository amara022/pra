#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stdlib.h>

#if 0
//enumö�٣�0��1��2��3...��˳�������ֵ����ֵ�����˳�������δ��ֵ�ı�����ֵ
int main()
{
	enum a
	{
		x1,y1,z1=5,a1,b1
	};
	enum a b = y1;
	enum a c = b1;
	cout << b << " " << c << endl;
	system("pause");
}
#endif

#if 0
int fun(int x, int y)
{
	static int m = 0;
	static int i = 2;
	i += m + 1;
	m = i + x + y;
	return m;
}
int main()
{
	int j = 4;
	int m = 1;
	int k;
	k = fun(j, m);
	cout << k << endl;
	k = fun(j, m);
	cout << k << endl;
	system("pause");
	return;
}
#endif

#if 0
//����unsigned int�ͱ���x��������1�ĸ���
int Fcount(unsigned int x)
{
	int count = 0;
	while (x)
	{
		if (x % 2)
			count++;
		x = x / 2;
	}
	return count;
}
int main()
{
	unsigned int a = 3;
	cout<<Fcount(a) << endl;
	system("pause");
}
#endif
int main()
{
	int count = 0;
	int x = 2019;
	while (x)
	{
		count++;
		x = x&(x - 1);
		cout << x << endl;
	}
	cout << count << endl;
	system("pause");
}