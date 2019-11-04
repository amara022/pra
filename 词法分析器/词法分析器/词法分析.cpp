#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include<iostream>
#include<fstream>
#include<iostream>
#include<string>
#include <atlstr.h>
using namespace std;
#define BUFFER 256      //定义缓冲区大小
class MAlex{
public:
	char range[12];  //12个界符
	char opn[19][3]; //19个运算符
	string key[20]; //20个保留字
	char line[256]; //读取一行字符串
	ifstream infile;//定义文件操作
	ofstream preout, resout;
public:
	void Init();//初始化
	bool is_digit(char c); //判断是否是数字
	bool is_alpbat(char c); //判断是否字母
	int is_oprator(int &i);//判断是否操作符
	int is_range(int &i);//判断是否界符
	int alpbat_c(int &i);//判断首字母是c
	int alpbat_i(int &i);//判断首字母是i
	int alpbat_s(int &i);//判断首字母是s
	int alpbat_e(int &i);//判断首字母是e
	void recog_reserve(int &i, int &num); //识别保留字
	void cope_firsrtaph(int &i);//处理首字符是字母
	void cope_firsrtnum(int &i);//处理首字符是数字
	void cope_range(int num, int &i);//处理首字符是界符
	void cope_operaor(int &i);//处理首字符是操作符
	int COPE(ifstream &inflie);//总处理程序
	void print_list(CString &s1);
};

void MAlex::Init()//初始化
{
	//12个界符
	range[0] = '#'; range[1] = '< '; range[2] = '>'; range[3] = '('; range[4] = ')'; range[5] = '[';//1-6号界符
	range[6] = ']'; range[7] = '{'; range[8] = '}'; range[9] = ','; range[10] = ';'; range[11] = '_'; //7-12号界符

	//19个运算符  
	strcpy_s(opn[0], "+"); strcpy_s(opn[1], "-"); strcpy_s(opn[2], "*"); strcpy_s(opn[3], "/");//编号13-16
	strcpy_s(opn[4], "%");  strcpy_s(opn[5], "++"); strcpy_s(opn[6], "--"); strcpy_s(opn[7], "&&");//编号17-20
	strcpy_s(opn[8], "||"); strcpy_s(opn[9], "!"); strcpy_s(opn[10], ">"); strcpy_s(opn[11], "<");//编号21-24
	strcpy_s(opn[12], "="); strcpy_s(opn[13], ">="); strcpy_s(opn[14], "<="); strcpy_s(opn[15], "==");//编号25-28
	strcpy_s(opn[16], "!="); strcpy_s(opn[17], ">>"); strcpy_s(opn[18], "<<");  //编号29-31

	//20个保留字
	key[0] = "include"; key[1] = "iostream"; key[2] = "using"; key[3] = "std"; key[4] = "main";  //32-36
	key[5] = "return"; key[6] = "void"; key[7] = "int"; key[8] = "char"; key[9] = "bool";  //37-41
	key[10] = "string"; key[11] = "cin"; key[12] = "cout"; key[13] = "endl"; key[14] = "if";  //42-46
	key[15] = "else"; key[16] = "do"; key[17] = "while"; key[18] = "for"; key[19] = "namespace";//47-51           
}

void MAlex::print_list(CString &s1)   //输出表格
{
	char buffer[128];
	s1 = "界符编号1-12\r\n";
	strcpy_s(buffer, 128, "[1,#]  [2,<]  [3,>]  [4,(]  [5,)]  [6,[]\r\n");
	s1 += buffer;
	strcpy_s(buffer, 128, "[7,]]  [8,{]  [9,}]  [10,,]  [11,;]  [12,_]\r\n\r\n");
	s1 += buffer;
	strcpy_s(buffer, 128, "运算符编号13-31\r\n");
	s1 += buffer;
	strcpy_s(buffer, 128, "[13,+]  [14,-]  [15,*]  [16,/]  [17,%]  [18,++] [19,--]\r\n");
	s1 += buffer;
	strcpy_s(buffer, 128, "[20,&&]  [21,||]  [22,!]  [23,>]  [24,<]  [25,=]\r\n");
	s1 += buffer;
	strcpy_s(buffer, 128, "[26,>=]  [27,<=]  [28,==]  [29,!=]  [30,>>]  [31,<<]\r\n\r\n");
	s1 += buffer;
	strcpy_s(buffer, 128, "保留字编号32-51\r\n");
	s1 += buffer;
	strcpy_s(buffer, 128, "[32,include]  [33,iostream]  [34,using]  [35,std]  [36,main]\r\n");
	s1 += buffer;
	strcpy_s(buffer, 128, "[37,return]  [38,void]  [39,int]  [40,char]  [41,bool]\r\n");
	s1 += buffer;
	strcpy_s(buffer, 128, "[42,string]  [43,cin]  [44,cout]  [45,endl]  [46,if]\r\n");
	s1 += buffer;
	strcpy_s(buffer, 128, "[47,else]  [48,do]  [49,while]  [50,for]  [51,namespace]\r\n");
	s1 += buffer;
}
//判断是否数字
bool MAlex::is_digit(char c){
	if (c >= '0'&&c <= '9')return true;
	else return false;
}

//判断是否字母

bool MAlex::is_alpbat(char c){ //判断是否字母
	if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))return true;
	else return false;
}

//判断是否操作符
int MAlex::is_oprator(int &i)
{
	switch (line[i]){
	case '+':if (line[i + 1] == '+'){ ++i; return 18; }
			 else { return 13; }
	case '-':if (line[i + 1] == '-'){ ++i; return 19; }
			 else { return 14; }
	case '*':return 15;
	case '/':if (line[i + 1] == '/'){ return -3; }  //预处理注释
			 else return 16;
	case '%':return 17;
	case '&':if (line[i + 1] == '&'){ ++i; return 20; }
			 else { return -2; };
	case '|':if (line[i + 1] == '|'){ ++i; return 21; }
			 else { return -2; };
	case '!':if (line[i + 1] == '='){ ++i; return 29; }
			 else { return 22; }
	case '>':if (line[i + 1] == '>'){ ++i; return 30; }
			 else if (line[i + 1] == '='){ ++i; return 26; }
			 else return 23;
	case '<':if (line[i + 1] == '<'){ ++i; return 31; }
			 else if (line[i + 1] == '='){ ++i; return 27; }
			 else return 24;
	case'=':if (line[i + 1] == '='){ ++i; return 28; }
			else  return 25;
	default:;
	}
	return -2; //不属于操作符
}

//判断是否界符，如果是，返回编号(处理时除去有歧义的尖括号）
int MAlex::is_range(int &i)
{
	switch (line[i]){
	case '#':return 1;
	case '<':if (line[i - 7] == '#') return 2;
			 else return -1; break;
	case '>':
		for (int j = i; line[j] != '\n'; ++j)
		if (is_digit(line[j]) || is_alpbat(line[j])) return -1; return 3; break;
	case '(':return 4;
	case ')':return 5;
	case '[':return 6;
	case ']':return 7;
	case '{':return 8;
	case '}':return 9;
	case ',':return 10;
	case ';':return 11;
	case '_':return 12;
	default:;
	}
	return -1; //不属于界符
}

int MAlex::alpbat_c(int &i){ //处理首字母为c的字符串
	if (line[i + 1] == 'h'&&line[i + 2] == 'a'&&line[i + 3] == 'r'&&line[i + 4] == ' '){
		i = i + 4;
		return 40;
	}
	else  if (line[i + 1] == 'i'&&line[i + 2] == 'n'&&line[i + 3] == '>'){
		i = i + 3;
		return 43;
	}
	else if (line[i + 1] == 'o'&&line[i + 2] == 'u'&&line[i + 3] == 't'&&line[i + 4] == '<'){

		i = i + 4;
		return 44;
	}
	else return 0;
}
int MAlex::alpbat_i(int &i){ //处理首字母为i的字符串
	if (line[i + 1] == 'n'){
		if (line[i + 2] == 't'&&line[i + 3] == ' '){
			i = i + 3;
			return 39;
		}
		else if (line[i + 2] == 'c'&&line[i + 3] == 'l'&&line[i + 4] == 'u'&&line[i + 5] == 'd'&&line[i + 6] == 'e'&&line[i + 7] == '<'){
			i = i + 7;
			return 32;
		}
		else return 0;
	}
	else if (line[i + 1] == 'o'&&line[i + 2] == 's'&&line[i + 3] == 't'&&line[i + 4] == 'r'&&line[i + 5] == 'e'
		&&line[i + 6] == 'a'&&line[i + 7] == 'm'&&line[i + 8] == '>'){
		i = i + 8;
		return 33;
	}
	else if (line[i + 1] == 'f'&&!is_alpbat(line[i + 2]) && !is_digit(line[i + 2]) && line[i + 2] != '_'){
		i = i + 2;
		return 46;
	}
	else return 0;
}

int MAlex::alpbat_s(int &i){ //处理首字母为s的字符串
	if (line[i + 1] == 't'){
		if (line[i + 2] == 'd'&&line[i + 3] == ';'){
			i = i + 3;
			return 35;
		}
		else if (line[i + 2] == 'r'&&line[i + 2] == 'i'&&line[i + 3] == 'n'&&line[i + 4] == 'g'&&
			!is_alpbat(line[i + 5]) && !is_digit(line[i + 5]) && line[i + 5] != '_'){
			i = i + 5;
			return 42;
		}
		else return 0;
	}
	else return 0;
}

int MAlex::alpbat_e(int &i){ //处理首字母为e的字符串
	if (line[i + 1] == 'l'&&line[i + 2] == 's'&&line[i + 3] == 'e'&&!is_alpbat(line[i + 4]) &&
		!is_digit(line[i + 4]) && line[i + 4] != '_'){
		i = i + 4;
		return 47;
	}
	else if (line[i + 1] == 'n'&&line[i + 2] == 'd'&&line[i + 3] == 'l'&& line[i + 4] == ';'){
		i = i + 4;
		return 45;
	}
	else return 0;
}

void MAlex::recog_reserve(int &i, int &num) //识别保留字
{
	switch (line[i]){  //识别保留字开关语句
	case 'c':num = alpbat_c(i); break;
	case'd':if (line[i + 1] == 'o'&&!is_alpbat(line[i + 2]) && !is_digit(line[i + 2]) && line[i + 2] != '_'){
				num = 48;
				i = i + 2;
	}break;
	case'e':num = alpbat_i(i); break;
	case'f':if (line[i + 1] == 'o'&&line[i + 2] == 'r'&&!is_alpbat(line[i + 3]) && !is_digit(line[i + 3])){
				i = i + 3;
				num = 50;
	}break;
	case 'i':num = alpbat_i(i); break;
	case'm':if (line[i + 1] == 'a'&&line[i + 2] == 'i'&&line[i + 3] == 'n'&&line[i + 4] == '('){
				num = 36;
				i = i + 4; break;
	}
	case'n':if (line[i + 1] == 'a'&&line[i + 2] == 'm'&&line[i + 3] == 'e'&&line[i + 4] == 's'&&line[i + 5] == 'p'
		&&line[i + 6] == 'a'&&line[i + 7] == 'c'&&line[i + 8] == 'e'&&line[i + 9] == ' '){
				num = 51;
				i = i + 9; break;
	}
	case'r':if (line[i + 1] == 'e'&&line[i + 2] == 't'&&line[i + 3] == 'u'&&line[i + 4] == 'r'&&line[i + 5] == 'n'&&line[i + 6] == ' '){
				num = 37;
				i = i + 6; break;
	}
	case's':num = alpbat_s(i); break;
	case'u':if (line[i + 1] == 's'&&line[i + 2] == 'i'&&line[i + 3] == 'n'&&line[i + 4] == 'g'&&line[i + 5] == ' '){
				num = 34;
				i = i + 5; break;
	}
	case 'v':if (line[i + 1] == 'o'&&line[i + 2] == 'i'&&line[i + 3] == 'd'&&!is_alpbat(line[i + 4]) &&
		!is_digit(line[i + 4]) && line[i + 4] != '_'){
				 num = 38;
				 i = i + 4; break;
	}
	case'w':if (line[i + 1] == 'h'&&line[i + 2] == 'i'&&line[i + 3] == 'l'&&line[i + 4] == 'e'&&
		!is_alpbat(line[i + 5]) && !is_digit(line[i + 5]) && line[i + 5] != '_'){
				num = 49;
				i = i + 5; break;
	}
	default:break;
	}
}

void MAlex::cope_firsrtaph(int &i){   //处理首字符是字母
	int num = 0;
	recog_reserve(i, num);
	if (num){
		resout << '<' << num << ',' << key[num - 32] << ',' << "保留字" << '>' << "  ";
		preout << key[num - 32];
	}
	else{
		int j = 0;
		resout << '<';
		for (; is_digit(line[i]) || is_alpbat(line[i]); i++, j++){
			preout << line[i];
			resout << line[i];
		}
		resout << ',' << "标识符" << '>' << "  ";
	}
}

void MAlex::cope_firsrtnum(int &i){   //处理首字符是数字
	int j = 0;
	resout << '<';
	for (; is_digit(line[i]); i++, j++){
		preout << line[i];
		resout << line[i];
	}
	resout << ',' << "数字" << '>' << '  ';
}

void MAlex::cope_range(int num, int &i){ //处理首字符是界符
	preout << range[num - 1];
	resout << '<' << num << ',' << range[num - 1] << ',' << "界符" << '>' << "  ";
	++i;
}

void MAlex::cope_operaor(int &i){//处理符号
	int num = is_oprator(i);
	switch (num){
	case -2:break;
	case -3:while (line[i + 1] != '\n')++i; break;
	default:	preout << opn[num - 13];
		resout << '<' << num << ',' << opn[num - 13] << ',' << "运算符" << '>' << "  "; break;
	}	++i;

}

int MAlex::COPE(ifstream &infile)  //主处理函数
{	Init();
	preout.open("preout.txt", ios::out);
	resout.open("resout.txt", ios::out);
	if (!preout)
	{
		cout << "预处理文件打开有误！" << endl;
		exit(-1);
	}
	if (!resout)
	{
		cout << "结果文件打开有误！" << endl;
		exit(-1);
	}
	int num;
	while (!infile.eof()){  //文件没有结束
		if (infile.fail())break;
		infile.getline(line, 256, '\n');
		strcat_s(line, 256, "\n");
		for (int i = 0; line[i] != '\n';){
			if (line[i] == ' '&&i != 0)preout << ' ';
			while (line[i] == ' ')++i;  //除空格
			if (is_alpbat(line[i])){  //如果是字母		
				cope_firsrtaph(i);
			}
			else if (is_digit(line[i]) && line[i] != '\n'){ //如果是数字
				cope_firsrtnum(i);
			}
			else if ((num = is_range(i)) != -1 && line[i] != '\n'){//首字符为界符
				cope_range(num, i);
			}
			else {//首字符为操作符
				if (line[i] != '\n')
					cope_operaor(i);
			}
		}
		preout << endl;
		resout << endl;
	}
}
int main()
{
	MAlex A;
	A.Init();
	A.COPE(A.infile);
	return 0;
}
#endif
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char prog[80], token[8];
char ch;
int syn, p, m = 0, n, row, sum = 0;
char *rwtab[6] = { "begin", "if", "then", "while", "do", "end" };

void scaner()
{
	
	for (n = 0; n<8; n++) token[n] = NULL;
	ch = prog[p++];
	while (ch == ' ')
	{
		ch = prog[p];
		p++;
	}
	if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))  //可能是标示符或者变量名 
	{
		m = 0;
		while ((ch >= '0'&&ch <= '9') || (ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))
		{
			token[m++] = ch;
			ch = prog[p++];
		}
		token[m++] = '\0';
		p--;
		syn = 10;
		for (n = 0; n<6; n++)  //将识别出来的字符和已定义的标示符作比较， 
		if (strcmp(token, rwtab[n]) == 0)
		{
			syn = n + 1;
			break;
		}
	}
	else if ((ch >= '0'&&ch <= '9'))  //数字 
	{
		{
			sum = 0;
			while ((ch >= '0'&&ch <= '9'))
			{
				sum = sum * 10 + ch - '0';
				ch = prog[p++];
			}
		}
		p--;
		syn = 11;
		if (sum>32767)
			syn = -1;
	}
	else switch (ch)   //其他字符 
	{
	case'<':m = 0; token[m++] = ch;
		ch = prog[p++];
		if (ch == '>')
		{
			syn = 21;
			token[m++] = ch;
		}
		else if (ch == '=')
		{
			syn = 22;
			token[m++] = ch;
		}
		else
		{
			syn = 23;
			p--;
		}
		break;
	case'>':m = 0; token[m++] = ch;
		ch = prog[p++];
		if (ch == '=')
		{
			syn = 24;
			token[m++] = ch;
		}
		else
		{
			syn = 20;
			p--;
		}
		break;
	case':':m = 0; token[m++] = ch;
		ch = prog[p++];
		if (ch == '=')
		{
			syn = 18;
			token[m++] = ch;
		}
		else
		{
			syn = 17;
			p--;
		}
		break;
	case'*':syn = 13; token[0] = ch; break;
	case'/':syn = 14; token[0] = ch; break;
	case'+':syn = 15; token[0] = ch; break;
	case'-':syn = 16; token[0] = ch; break;
	case'=':syn = 25; token[0] = ch; break;
	case';':syn = 26; token[0] = ch; break;
	case'(':syn = 27; token[0] = ch; break;
	case')':syn = 28; token[0] = ch; break;
	case'#':syn = 0; token[0] = ch; break;
	case'\n':syn = -2; break;
	default: syn = -1; break;
	}
}

int main()
{
	FILE *w = fopen("D:\\output.txt", "w");
	p = 0;
	row = 1;
	cout << "Please input string:" << endl;
	do
	{
		cin.get(ch);
		prog[p++] = ch;
	} while (ch != '#');
	p = 0;
	do
	{
		scaner();
		switch (syn)
		{
		case 11: cout << "(" << syn << "," << sum << ")" << endl; break;
		case -1: cout << "Error in row " << row << "!" << endl; break;
		case -2: row = row++; break;
		default: {
					 cout << "(" << syn << "," << token << ")" << endl; 
					 fprintf(w, "(%d", syn);
					 fprintf(w,",");
					 fprintf(w, "%s)", token);
				break;
			}
		}
	} while (syn != 0);
	return 0;
}
