#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;


#if 0
int main()
{
	int a, x;
	for (a = 0, x = 0; a <= 1 && !x++; a++)
		a++;
	cout << a << " " << x << endl;//2 1
	system("pause");
}

int main()
{
	int a, x;
	for (a = 0, x = 0; a <= 1 || !x++; a++)
		a++;
	cout << a << " " << x << endl;//4 2
	system("pause");
}
#endif

#if 0
int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int* p1 = (int*)(&a + 1);
	int* p2 = (int*)((int)a + 1);
	int* p3 = (int*)(a + 1);
	cout << p1[-1] << "  " << p2[0] << "  " << p3[1] << endl;
	system("pause");
}
#endif

#if 0
int main()
{
	char *str[3] = { "stra", "strb", "strc" };
	char *p = str[0];
	int i = 0;
	while (i < 3)
	{
		cout << p++ << endl;
		i++;
	}
	system("pause");
}
#endif

#if 0
int main()
{
	int i = 1;
	cout << sizeof(i++) << " " << i << endl;//4  1
	system("pause");
}
#endif

int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = (char)(-1 - i);
	}
	cout << strlen(a) << endl;
	system("pause");
}
