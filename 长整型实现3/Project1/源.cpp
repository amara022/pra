#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int SIZE = 100;
typedef struct Node
{
	int data;         
	int len;           
	struct Node* prior;   
	struct Node* next;    
} Node;
typedef Node* LinkList;

class Long
{
public:
	Long()
	{
		L = (LinkList)malloc(sizeof(LinkList));
		L->prior = NULL;
		L->next = NULL;
		L->data = '+';      
	}
	void Init()
	{
		LinkList p, q;
		char ch[SIZE];
		char *str = ch;
		printf("请输入整数(每四位用逗号隔开)\n>> ");
		scanf("%s", ch);
		p = L;
		int len = strlen(str);
		int cc = 1;
		int LEN = 0;
		int end = 0;
		if (ch[0] == '-')
		{
			this->L->data = '-';
			end = 1;  
		}

		for (int i = len - 1; i >= end; --i)
		{
			if (cc % 5)
			{
				q = (LinkList)malloc(sizeof(LinkList));
				q->data = ch[i] - '0';     
				q->prior = p;
				p->next = q;
				p = q;
				++LEN;
			}
			++cc;
		}
		// 循环连接
		p->next = L;
		L->prior = p;
		L->len = LEN;                    

	}
	void print()
	{
		int len = L->len;
		LinkList tmp = L;
		if (L->data == '-')
		{
			printf("%c", L->data);
			L = L->prior;
			while (L->data == 0 && L->prior != tmp)
			{ 
				L = L->prior;
				--len;
			}
		}
		else
		{
			L = L->prior;
			while (L->data == 0 && L->prior != tmp)
			{
				L = L->prior; 
				--len;
			}
		}
		while (len)
		{ 
			printf("%d", L->data);
			L = L->prior;
			--len;
			if (!(len % 4) && len) putchar(',');
		}
		puts("");
	}
	//判断绝对值大小
	int abs(Long& a1)
	{
		int len1 = this->L->len;
		int len2 = a1.L->len;
		if (len1 > len2)
		{
			return 1;
		}
		else if (len1<len2)
		{
			return 0;
		}
		else
		{
			LinkList tmp1 = this->L, tmp2 = a1.L;
			int cnt = 0;
			tmp1 = tmp1->prior;
			tmp2 = tmp2->prior;
			if (len1<len2)
				len1 = len2;
			while (cnt != len1)
			{
				if (tmp1->data >= tmp2->data)
				{
					return 1;
				}
				else if (tmp1->data < tmp2->data)
				{
					return 0;
				}
				tmp1 = tmp1->prior;
				tmp2 = tmp2->prior;
				++cnt;
			}
		}
	}
	//判断两整形同号异号
	int pan(Long& a1)
	{
		if (!(this->L->data ^ a1.L->data))
		{   // 同号
			return 1;
		}
		else
		{   // 异号
			return 0;
		}
	}
	Long operator-(const Long& a1)
	{
		Long Lo;
		int len1 = this->L->len;
		int len2 = a1.L->len;
		LinkList a = new Node;
		LinkList b = new Node;// a为较长的整数链表， b为较短的整数链表
		if (len1 > len2)
		{
			a = this->L;
			b = a1.L;
		}
		else if (len1 < len2)
		{
			a = a1.L;
			b = this->L;
		}
		else
		{
			LinkList tmp1 = this->L, tmp2 = this->L;
			int cnt = 0;
			tmp1 = tmp1->prior;
			tmp2 = tmp2->prior;
			while (cnt != len1)
			{
				if (tmp1->data > tmp2->data)
				{
					a = this->L;
					b = a1.L;
					break;
				}
				else if (tmp1->data < tmp2->data)
				{
					a = a1.L;
					b = this->L;
					break;
				}
				tmp1 = tmp1->prior;
				tmp2 = tmp2->prior;
				++cnt;
			}
			if (cnt == len1)
			{ 
				a = this->L;
				b = a1.L;
			}
		}

		len1 = a->len;          // 较长链表
		len2 = b->len;          // 较短链表

		int cnt = 0;
		int ex = 0;  
		while (cnt != len1)
		{
			a = a->next;
			b = b->next;

			if (cnt >= len2)    
				a->data = a->data - ex;
			else
				a->data = a->data - b->data - ex;
			ex = 0;
			if (a->data < 0) a->data += 10, ex = 1;   
			++cnt;
		}
		a = a->next;    
		a->len = len1; 
		Lo.L = a;
		return Lo;
	}
	Long operator+(const Long& a1)
	{
		int len1 = this->L->len;
		int len2 = a1.L->len;
		Long Lo;
		Lo.L->data = 0;
		LinkList a, b;       
		if (len1 > len2)
		{
			a = this->L;
			b = a1.L;
		}
		else
		{
			a = a1.L;
			b = this->L;
		}
		len1 = a->len;          // 较长链表
		len2 = b->len;          // 较短链表

		int cnt = 0;
		int ex = 0;          
		while (cnt != len1)
		{
			a = a->next;
			b = b->next;

			if (cnt >= len2)  
				a->data = a->data + ex;
			else
				a->data = a->data + b->data + ex;
			ex = 0;
			if (a->data >= 10) a->data -= 10, ex = 1;   
			++cnt;
		}

		if (ex)
		{
			LinkList p = (LinkList)malloc(sizeof(Node));
			p->data = ex;

			p->next = a->next;
			a->next->prior = p;
			p->prior = a;
			a->next = p;

			a = p;
			++len1;
		}
		a = a->next;      
		a->len = len1;      
		Lo.L = a;
		return Lo;

	}
	LinkList L;
};

int main()
{
	Long L;
	L.Init();
	Long B;
	B.Init();
	Long C;
	char ch[2];
	printf("请输入操作符:\n>>");
	scanf("%s", &ch[0]);
	if (ch[0] == '+')
	{
		if (L.pan(B))
			C = L + B;
		else
			C = L - B;
	}
		
	else if (ch[0] == '-')
	{
		if (L.pan(B))
		{
			if (L.abs(B))
			{
				C = L - B;
				if (C.L->prior->data==0)
					C.L->data = '+';
			}
			else
			{
				C = B - L;
				if (C.L->data == '-')
					C.L->data = '+';
				else
					C.L->data = '-';
			}
		}
		else
		{
			if (L.abs(B))
				C = B + L;
			else
			{
				C = B + L;
				if (C.L->data == '-')
					C.L->data = '+';
				else
					C.L->data = '-';
			}
		}
	}
	else
		printf("请重新输入");
	printf("计算得：");

	C.print();
	return 0;
}