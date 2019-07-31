#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
#include<stdlib.h>
#include<stack>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> s1;
		for (char ch : s)
		{
			if (s1.empty())
				s1.push(ch);
			else if (s1.top() == '('&&ch == ')')
				s1.pop();
			else if (s1.top() == '['&&ch == ']')
				s1.pop();
			else if (s1.top() == '{'&&ch == '}')
				s1.pop();
			else
				s1.push(ch);
		}
		return s1.empty();
	}
};



int main()
{
	Solution a;
	string s = "(}";
	if (a.isValid(s))
		cout << "Æ¥Åä" << endl;
	else 
		cout << "²»Æ¥Åä" << endl;
	system("pause");
}
