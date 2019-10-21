#define _CRT_SECURE_NO_WARNINGS 1101010123213
#include<stdlib.h>
#include<assert.h>
#include<iostream>
using namespace std;

//定义数据类型 int
typedef int DateType;
//c++const int 代替typedef
const int MAX = 1000;      

typedef struct Sqlist
{
	DateType date[MAX];    
	int length;
}Sqlist;
//节点类型定义
typedef struct Node
{
	DateType data;
	struct Node *next;
}Node;
void InitList(Node *L)//初始化
{
	L = new Node;
	L->next = NULL;
}
void GetList(Node* L)//尾插法建立单链表
{
	Node *r, *s;
	DateType c = 1;
	r = L;
	while (c)
	{
		s = new Node;
		cin>>c;
		if (c == 0)
		{
			r->next = NULL;
			return;
		}
		s->data = c;
		r->next = s;
		r = s;
	}

}

void PrintLink(Node* L)//打印链表
{
	Node* P = L->next;
	while (P != NULL)
	{
		cout<<P->data<<" ";
		P = P->next;
	}
	cout<<endl;
}

int ListLength(Node* L)//求链表长度
{
	Node *p;
	p = L;
	int j = 0;
	while (p->next != NULL)
	{
		p = p->next;
		j++;
	}
	return j;
}

void Ins(Node* L, DateType x)//尾插元素
{
	Node *s;
	s = new Node;
	s->data = x;
	L->next = s;
}
//合并两个链表并打印
Sqlist* Merge(Node* l, Node* m)
{
	Node *pl, *pm, *pls;
	Node* LS=new Node;
	Sqlist* SL = new Sqlist;
	InitList(LS);
	pl = l->next;
	pm = m->next;
	pls = LS;
	int count_l = ListLength(pl), count_m = ListLength(pm);
	int sum = count_l + count_m;
	if (count_l >= count_m)
	{
		while ((pl != NULL) || (pm != NULL))
		{
			if (pl != NULL)
			{
				Ins(pls, pl->data);
				pl = pl->next;
				pls = pls->next;
			}
			if (pm != NULL)
			{
				Ins(pls, pm->data);
				pm = pm->next;
				pls = pls->next;
			}
		}
	}

	if (count_l <= count_m)
	{
		while ((pl != NULL) || (pm != NULL))
		{
			if (pm != NULL)
			{
				Ins(pls, pm->data);
				pm = pm->next;
				pls = pls->next;
			}
			if (pl != NULL)
			{
				Ins(pls, pl->data);
				pl = pl->next;
				pls = pls->next;
			}
		}
	}
	pls->next = NULL;
	Node* cur = LS;
	int len = ListLength(LS);
	for (int i = 0; i <= len; i++)
	{
		SL->date[i] = cur->data;
		cur = cur->next;
	}
	SL->length = len;
	cout << "链表合并后为："<<endl;
	for (int i = 1; i <= SL->length; i++)
	{
		cout << SL->date[i] << " ";
	}
	cout << endl;
	return SL;
}

//直接插入排序
void InsertSort(Sqlist* L)
{
	int i, j;
	for (i = 2; i <= L->length; i++)
	{
		L->date[0] = L->date[i];
		j = i - 1;
		while (L->date[0]<L->date[j])
		{
			L->date[j + 1] = L->date[j];
			j--;
		}
		L->date[j + 1] = L->date[0];
	}
	cout << "对链表进行直接插入排序后：" << endl;
	for (int i = 1; i <= L->length; i++)
	{
		cout << L->date[i] << " ";
	}
	cout << endl;
}

int main()
{
	Node* L = new Node;
	Node* M = new Node;
	InitList(L);
	InitList(M);
	cout << "请输入链表A的值（输入0结束)" << endl;
	GetList(L);
	cout << "请输入链表B的值（输入0结束)" << endl;
	GetList(M);
	cout<<"链表A：";
	PrintLink(L);
	cout << "A链表长度:" << ListLength(L) << endl;
	cout<<"链表B：";
	PrintLink(M);
	cout << "B链表长度:" << ListLength(M) << endl;
	Sqlist* SUM = Merge(L, M);
	InsertSort(SUM);
	return 0;
}
