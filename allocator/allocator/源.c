#define _CRT_SECURE_NO_WARNINGS 1
#include"myalloc.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	unsigned int i;

	vector<int, MY::allocator<int>> v(a, a + 5);
	for (i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}