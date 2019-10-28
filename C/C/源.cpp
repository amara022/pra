#define _CRT_SECURE_NO_WARNINGS 1

#ifndef HUFFMAN_TREE
#define HUFFMAX_TREE
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>
//I don't know why I can't input Chinese so all of my comments are English. sry :D
using namespace std;
vector<string> S;
map <string, int>  m;//when you use queue, this can be used to find a key's frequence
map <string, string>  code;
map <string, string>  rcode;
string houzhui = "";
int zeroNum;
int miniCode = 1000;
struct Huffman
{
	int num; // the frequence
	string w; //the word
	Huffman * lnode;
	Huffman * rnode;
	Huffman() :w(""), lnode(NULL), rnode(NULL)	{}
	Huffman(string s, int n) :num(n), w(s), lnode(NULL), rnode(NULL)	{}
};
typedef Huffman* Node;
class Compare// used to construce priority_queue
{
public:
	bool operator()(const Node& e1, const Node& e2)
	{
		return (*e1).num > (*e2).num;
	}
};
priority_queue< Node, vector<Node>, Compare > que;

bool read_File(const char* file) //read the file , the argu is the address of the file
{
	ifstream fin(file, ios_base::binary);
	char ch;
	while (!fin)
	{
		cout << "Cannot read the file." << endl;
		return false;
	}
	while (!fin.eof())
	{
		char a;
		string s;
		fin.get(a);//if use istream would cause the blank and line cannot read
		if (!fin.eof())
		{
			s = a;
			m[s] += 1;
			S.push_back(s);
		}
	}//all of the content and its frequence are stored in the map
	return true;
	fin.close();
}

void getQueue()//construct the priority_queue
{
	for (auto i = m.begin(); i != m.end(); ++i)
	{
		Node tmp = new Huffman(i->first, i->second);
		que.push(tmp);
	}
}

void getTree()//construct the huffman tree
{
	while (que.size() > 1)
	{
		Node tmp1 = que.top();
		que.pop();
		Node tmp2 = que.top();
		que.pop();//choose the two most smallest elements
		Node root = new Huffman(tmp1->w + tmp2->w, tmp1->num + tmp2->num);
		root->lnode = tmp1;//the left must be the most smallest element
		root->rnode = tmp2;
		que.push(root);
	}
}

void getMap(string c, Node node)//get the code which belongs to the unique char
{
	if (node == NULL || node->w == "")
	{
		return;
	}
	if (node->w.length() == 1) // the leaf node
	{
		if (c.size() < miniCode)
		{
			miniCode = c.size();
		}
		code[node->w] = c;
		rcode[c] = node->w;
	}
	if (node->lnode)
	{
		getMap(c + "0", node->lnode);
	}
	if (node->rnode)
	{
		getMap(c + "1", node->rnode);
	}
}

void compress(const char* infile, const char* out)
{

	ifstream fin(infile, ios_base::binary);
	ofstream fout(out, ios_base::binary);

	//	fout << "zlh&&zht";//the define
	//	short n = code.size();
	//	fout << n;
	//	for(auto i : code)
	//	{
	//		fout << (i).first << (i).second;
	//	}

	int length = 0;
	char a, tc;
	string s, ts = "";
	for (auto i : code)
		cout << i.first << "  " << i.second << endl;
	while (!fin.eof())
	{
		fin.get(a);
		if (!fin.eof())// avoid read the extra char
		{
			s = a;
			ts.append(code[s]);//append
			length += code[s].size();
			while (ts.size() >= 8)
			{
				string tmp = ts.substr(0, 8);
				//			cout << tmp << endl;
				ts = ts.substr(8, ts.size());
				bitset <8> bit(tmp);
				unsigned long u_long = bit.to_ulong();
				unsigned char u_char = u_long;
				fout << u_char;
				length -= 8;
			}
		}
	}
	zeroNum = 8 - length;
	if (length != 0)
	{
		for (int i = length; i < 8; ++i)
			ts += "0"; //²¹Áã
	}
	//cout << s << s.size();
	bitset <8> bit(ts);
	unsigned long u_long = bit.to_ulong();
	unsigned char u_char = u_long;
	fout << u_char;

	fin.close();
	fout.close();
}

string charToString(unsigned char tc)
{
	string ts = "";
	char one = 1;
	for (int i = 0; i < 7; ++i)
	{
		unsigned char tmp = tc&one;
		if (tmp == 1)
			ts.insert(0, "1");
		else ts.insert(0, "0");

		tc = tc >> 1;
		//		cout << (int)tc << endl;
	}
	char tmp = tc&one;
	if (tmp == 1)
		ts.insert(0, "1");
	else ts.insert(0, "0");

	return ts;
}

void recompress(const char* infile, const char* out)
{
	//	time_t start, end;
	ifstream fin(infile, ios_base::binary);
	ofstream fout(out, ios_base::binary);

	//    string comfirm;
	//    fin >> comfirm;
	//    if(comfirm.compare("zlh&&zht") == 0)
	//    {
	//    	short n;
	//    	fin >> n;
	//    	string T1, T2;
	//    	while(n--)
	//    	{
	//    		rcode.insert(make_pair(T2, T1));
	//    	}
	//    		
	//    }
	//    else 
	//	{
	//		cout << "I cannot know this form of the file" << endl; 
	//		return;
	//	}

	string s("");
	//cout << rcode["00"] << " " << rcode["01"] << " " << rcode["11"] << endl;
	while (!fin.eof())
	{
		char a;
		fin.get(a);
		if (!fin.eof())//avoid get outside 
		{
			string tmp = charToString((unsigned char)a);
			s.append(tmp);
			//			cout << s << endl;
		}
	}
	s.erase(s.size() - zeroNum, s.size()); //remove the zero
	//	cout << s << endl;
	string findString = "";
	int len = miniCode - 1;
	findString = s.substr(0, len);
	//	start = clock();
	while (len < s.size())
	{
		findString += s[len++];
		auto tmp = rcode.find(findString);
		if (tmp != rcode.end())
		{
			fout << (*tmp).second;
			//			cout << findString << endl;
			//			cout << rcode[findString] << endl;
			findString.clear();
			//			s.erase(0, len);//it costs the most of the time
			if (len + miniCode - 1 < s.size())
				findString = s.substr(len, miniCode - 1);
			len += miniCode - 1;
		}
	}
	/*
	end = clock();
	double res = end - start;
	printf("Use Time:%f\n",(res/CLOCKS_PER_SEC));
	*/
	fin.close();
	fout.close();
}


int main()
{
	time_t start, end;
	string address;
	cout << "please input the input file address." << endl;
	cin >> address;
	//cout << "Now please input the output file address." << endl; 
	string::size_type tmp = address.find('.');
	houzhui = address.substr(tmp + 1, tmp + 3);
	read_File(address.c_str());
	getQueue();
	getTree();
	getMap("", que.top());
	compress(address.c_str(), "result.bin");

	start = clock();
	recompress("result.bin", "result.txt");
	end = clock();
	double res = end - start;
	printf("Use Time:%f\n", (res / CLOCKS_PER_SEC));
}
#endif
