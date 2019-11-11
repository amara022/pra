#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
const int MAX = 1000000;
int main()
{
	int a;
	cin >> a;
	int b[MAX];
	for (int i = 0; i<a; i++)
		cin >> b[i];
	int sum1 = 0, sum2 = 0;
	int result = b[0];
	for (int i = 0; i < a; ++i)
	{
		sum2 = (sum1>0 ? (sum1 + b[i]) : b[i]);
		if (result < sum2)
			result = sum2;
		if (sum2 < 0)
			sum2 = 0;
		sum1 = sum2;
	}
	cout << result << endl;
	return 0;

}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool HW(string A)
{
	string s = A;
	reverse(A.begin(), A.end());
	if (A == s)
		return true;
	else
		return false;
}
int main()
{
	string A, B, C;
	cin >> A >> B;
	int len = A.size();
	int res = 0;
	for (int i = 0; i<len + 1; i++)
	{
		C = A;
		C.insert(i, B);
		if (HW(C))
			res++;
	}
	cout << res << endl;
	return 0;
}