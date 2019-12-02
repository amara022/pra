#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <iomanip>
#include <map>
#include <cmath>
#include <stack>
using namespace std;
struct node
{
	char left;
	string right;
};
class Base
{
protected:
	int T;
	node analy_str[100]; //�����ķ�����
	set<char> first_set[100];//first��
	set<char> follow_set[100];//follow��
	vector<char> ter_copy; //ȥ$�ս��
	vector<char> ter_colt;//�ս��
	vector<char> non_colt;//���ս��
public:
	Base() :T(0){}
	bool isNotSymbol(char c);
	int get_index(char target);//������ս�������е��±�
	int get_nindex(char target);//����ڷ��ս�������е��±�
	void get_first(char target); //�õ�first����
	void get_follow(char target);//�õ�follow����
	void inputAndSolve(); //����õ�first��follow
	void display(); //��ʾ
};

class TableStack :public Base
{
protected:
	vector<char> to_any; //����ջ
	vector<char> left_any;//ʣ�����봮
	int tableMap[100][100];//Ԥ���
public:
	TableStack(){ memset(tableMap, -1, sizeof(tableMap)); }

	void get_table(); //�õ�Ԥ���
	void analyExp(string s); //����ջ�Ĵ���
	void print_out();//���
	void getAns(); //��ϴ���
};
bool Base::isNotSymbol(char c)
{
	if (c >= 'A' && c <= 'Z')
		return true;
	return false;
}
int Base::get_index(char target)
{
	for (int i = 0; i<non_colt.size(); i++)
	{
		if (target == non_colt[i])
			return i;
	}
	return -1;
}
int Base::get_nindex(char target)
{
	for (int i = 0; i<ter_copy.size(); i++)
	{
		if (target == ter_copy[i])
			return i;
	}
	return -1;
}
void Base::get_first(char target)
{
	int tag = 0;
	int flag = 0;
	for (int i = 0; i<T; i++)
	{
		if (analy_str[i].left == target)//ƥ�����ʽ��
		{
			if (!isNotSymbol(analy_str[i].right[0]))//�����ս����ֱ�Ӽ���first
			{
				first_set[get_index(target)].insert(analy_str[i].right[0]);
			}
			else
			{
				for (int j = 0; j<analy_str[i].right.length(); j++)
				{
					if (!isNotSymbol(analy_str[i].right[j]))//�ս������
					{
						first_set[get_index(target)].insert(analy_str[i].right[j]);
						break;
					}
					get_first(analy_str[i].right[j]);//�ݹ�
					//	cout<<"curr :"<<analy_str[i].right[j];
					set<char>::iterator it;
					for (it = first_set[get_index(analy_str[i].right[j])].begin(); it != first_set[get_index(analy_str[i].right[j])].end(); it++)
					{
						if (*it == '$')
							flag = 1;
						else
							first_set[get_index(target)].insert(*it);//��FIRST(Y)�еķ�$�ͼ���FIRST(X)
					}
					if (flag == 0)
						break;
					else
					{
						tag += flag;
						flag = 0;
					}
				}
				if (tag == analy_str[i].right.length())//�����Ҳ�first(Y)����$,��$����FIRST(X)��
					first_set[get_index(target)].insert('$');
			}
		}
	}

}
void Base::get_follow(char target)
{
	for (int i = 0; i<T; i++)
	{
		int index = -1;
		int len = analy_str[i].right.length();
		for (int j = 0; j<len; j++)
		{
			if (analy_str[i].right[j] == target)
			{
				index = j;
				break;
			}
		}
		if (index != -1 && index < len - 1)
		{
			char nxt = analy_str[i].right[index + 1];
			if (!isNotSymbol(nxt))
			{
				follow_set[get_index(target)].insert(nxt);
			}
			else
			{
				int isExt = 0;
				set<char>::iterator it;
				for (it = first_set[get_index(nxt)].begin(); it != first_set[get_index(nxt)].end(); it++)
				{
					if (*it == '$')
						isExt = 1;
					else
						follow_set[get_index(target)].insert(*it);
				}

				if (isExt && analy_str[i].left != target)
				{
					get_follow(analy_str[i].left);
					set<char>::iterator it;
					char tmp = analy_str[i].left;
					for (it = follow_set[get_index(tmp)].begin(); it != follow_set[get_index(tmp)].end(); it++)
						follow_set[get_index(target)].insert(*it);
				}
			}
		}

		else if (index != -1 && index == len - 1 && target != analy_str[i].left)
		{
			get_follow(analy_str[i].left);
			set<char>::iterator it;
			char tmp = analy_str[i].left;
			for (it = follow_set[get_index(tmp)].begin(); it != follow_set[get_index(tmp)].end(); it++)
				follow_set[get_index(target)].insert(*it);
		}

	}
}
void Base::inputAndSolve()
{
	string s;
	cout << "����Ĳ���ʽ�ĸ�����" << endl;
	cin >> T;
	for (int index = 0; index<T; index++)
	{
		cin >> s;
		string temp = "";
		for (int i = 0; i<s.length(); i++)
		{
			if (s[i] != ' ')
				temp += s[i];
		}
		analy_str[index].left = temp[0];
		for (int i = 3; i<temp.length(); i++)
			analy_str[index].right += temp[i];


		for (int i = 0; i<temp.length(); i++)
		{
			if (temp[i] != '-' && temp[i] != '>')
			{
				if (isNotSymbol(temp[i]))
				{
					int flag = 0;
					for (int j = 0; j<non_colt.size(); j++)
					{
						if (non_colt[j] == temp[i])
						{
							flag = 1;
							break;
						}
					}
					if (!flag)
						non_colt.push_back(temp[i]);

				}
				else
				{
					int flag = 0;
					for (int j = 0; j<ter_colt.size(); j++)
					{
						if (ter_colt[j] == temp[i])
						{
							flag = 1;
							break;
						}
					}
					if (!flag)
						ter_colt.push_back(temp[i]);
				}
			}
		}

	}
	ter_colt.push_back('#');
	//first
	for (int i = 0; i<non_colt.size(); i++)
	{
		get_first(non_colt[i]);
	}

	for (int i = 0; i<non_colt.size(); i++)
	{
		if (i == 0)
			follow_set[0].insert('#');
		get_follow(non_colt[i]);
	}

	for (int i = 0; i<ter_colt.size(); i++)
	{
		if (ter_colt[i] != '$')
			ter_copy.push_back(ter_colt[i]);
	}
}

void Base::display()
{
	cout << "FIRST����" << endl;
	for (int i = 0; i<non_colt.size(); i++)
	{
		cout << non_colt[i] << ": ";
		set<char>::iterator it;
		for (it = first_set[i].begin(); it != first_set[i].end(); it++)
			cout << *it << "  ";
		cout << endl;
	}

	cout << "FOLLOW����" << endl;
	for (int i = 0; i<non_colt.size(); i++)
	{
		cout << non_colt[i] << ": ";
		set<char>::iterator it;
		for (it = follow_set[i].begin(); it != follow_set[i].end(); it++)
			cout << *it << "  ";
		cout << endl;
	}
}
void TableStack::get_table()
{
	for (int i = 0; i<T; i++)
	{
		char tmp = analy_str[i].right[0];
		if (!isNotSymbol(tmp))
		{
			if (tmp != '$')
				tableMap[get_index(analy_str[i].left)][get_nindex(tmp)] = i;
			if (tmp == '$')
			{
				set<char>::iterator  it;
				for (it = follow_set[get_index(analy_str[i].left)].begin(); it != follow_set[get_index(analy_str[i].left)].end(); it++)
				{
					tableMap[get_index(analy_str[i].left)][get_nindex(*it)] = i;
				}
			}
		}
		else
		{
			set<char>::iterator ti;
			for (ti = first_set[get_index(tmp)].begin(); ti != first_set[get_index(tmp)].end(); ti++)
			{
				tableMap[get_index(analy_str[i].left)][get_nindex(*ti)] = i;
			}
			if (first_set[get_index(tmp)].count('$') != 0)
			{
				set<char>::iterator  it;
				for (it = follow_set[get_index(analy_str[i].left)].begin(); it != follow_set[get_index(analy_str[i].left)].end(); it++)
				{
					tableMap[get_index(analy_str[i].left)][get_nindex(*it)] = i;
				}
			}
		}
	}
}
void TableStack::analyExp(string s)
{
	for (int i = s.length() - 1; i >= 0; i--)
		left_any.push_back(s[i]);

	to_any.push_back('#');
	to_any.push_back(non_colt[0]);


	while (left_any.size()>0)
	{
		//cout<<"����ջ��";
		string outs = "";
		for (int i = 0; i<to_any.size(); i++)
			outs += to_any[i];
		cout << setw(15) << outs;

		//cout<<"ʣ�����봮��";
		outs = "";
		for (int i = left_any.size() - 1; i >= 0; i--)
			outs += left_any[i];
		cout << setw(15) << outs;

		char char1 = to_any[to_any.size() - 1];
		char char2 = left_any[left_any.size() - 1];
		if (char1 == char2 && char1 == '#')
		{
			cout << setw(15) << "Accepted!" << endl;
			return;
		}
		if (char1 == char2)
		{
			to_any.pop_back();
			left_any.pop_back();
			cout << setw(15) << char1 << "ƥ��" << endl;
		}
		else if (tableMap[get_index(char1)][get_nindex(char2)] != -1)
		{
			int tg = tableMap[get_index(char1)][get_nindex(char2)];
			to_any.pop_back();

			if (analy_str[tg].right != "$")
			{
				for (int i = analy_str[tg].right.length() - 1; i >= 0; i--)
					to_any.push_back(analy_str[tg].right[i]);
			}
			//cout<<"�Ƶ���"<<analy_str[tg].right<<endl; 
			cout << setw(15) << analy_str[tg].right << endl;
		}
		else
		{
			cout << setw(15) << "error!" << endl;
			return;
		}
	}
}

void TableStack::print_out()
{
	//table
	for (int i = 0; i<ter_copy.size(); i++)
	{
		cout << setw(10) << ter_copy[i];
	}
	cout << endl;
	for (int i = 0; i<non_colt.size(); i++)
	{
		cout << non_colt[i] << ": ";
		for (int j = 0; j<ter_copy.size(); j++)
		{
			if (tableMap[i][j] == -1)
				cout << setw(10) << "error";
			else
				cout << setw(10) << analy_str[tableMap[i][j]].right;

		}
		cout << endl;
	}
}

void TableStack::getAns()
{
	inputAndSolve();
	display();
	get_table();
	print_out();
	//ջƥ��
	string ss;
	cout << "��������Ŵ���" << endl;
	cin >> ss;
	cout << setw(15) << "����ջ" << setw(15) << "ʣ�����봮" << setw(15) << "�Ƶ�ʽ" << endl;
	analyExp(ss);

}
int main()
{
	TableStack res;
	res.getAns();
	return 0;
}