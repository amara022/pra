#include<iostream>
using namespace std;

#include<string>
#if 0
void TestString()
{
	string s1;
	string s2("Hello");
	string s3(s2);
	s3 += " world";
	cout << s1 << endl;
	cout << s1.size() << " " << s1.capacity() << endl;
	cout << s2 << endl;
	cout << s2.size() << " " << s2.capacity() << endl;
	cout << s3 << endl;
	cout << s3.size() << " " << s3.capacity() << endl;
	//遍历字符串 1
	for (auto e : s2)
		cout << e;
	cout << endl;
	// 2
	for (size_t i = 0; i < s3.size(); i++)
		cout << s3[i];
	cout << endl;
	//3
	string::iterator it = s3.begin();
	while (it != s3.end())
	{
		cout << *it;
		it++;
	}
	cout << endl;
	//扩充----->resize改的是有效字符个数
	s3.resize(15, '!');
	cout << s3 << endl;
	s3.resize(10);
	cout << s3 << endl;
	//--------->reserve改的是capicity个数
	//n<=old capicity:不扩容
	//n>oldcapicity:扩容
	//n<=15:缩小
	//n>15:容量不变
	s2.reserve(4);
	cout << s2 << endl;
	cout << s2.size() << " " << s2.capacity() << endl;
	s2.reserve(30);
	cout << s2 << endl;
	cout << s2.size() << " " << s2.capacity() << endl;
	string S1("hello world");
	const string S2("Hello world");
	cout << S1 << "   " << S2 << endl;
	S1[0] = 'H';
//	S2[0] = 'h';//const修饰不能更改
	cout << S1 << endl;
	S1.push_back(' ');
	S1.append("too");
	S1.resize(18, '!');
	cout << S1 << endl;
	//获取文件后缀
	//substr:在str中从pos位置开始，截取n个字符，然后将其返回
	string W("prastring.h");
	size_t pos = W.rfind('.');
	string w(W.substr(pos, W.size() - pos));
	cout << w << endl;
	//取出域名
	string url("https://hao.360.com/?wd=1000");
	size_t start = url.find("://");
	if (start == string::npos)  //static const size_t npos = -1
	{
		cout << "no url" << endl;
	}
	start += 3;
	size_t finish = url.find('/', start);
	string adress = url.substr(start, finish - start);
	cout << adress << endl;
}

void test()
{
	TestString();
}
#endif

//反转字符串
class solution{
public:
	string reverse(string s)
	{
		if (s.empty())
			return s;
		size_t start = 0;
		size_t end = s.size() - 1;
		while (start < end)
		{
			swap(s[start], s[end]);
			start++;
			end--;
		}
		return s;
	}
};

void test()
{
	solution S;
	string s("Hello World");
	string su = S.reverse(s);
	cout << su << endl;
}