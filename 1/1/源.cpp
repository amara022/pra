#define _CRT_SECURE_NO_WARNINGS 1

#include"node.h"


void InitList(LinkList *L)//初始化
{
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
}

void CreateFromTail(LinkList L)//尾插法建立单链表
{
	Node *r, *s;
	DateType c = 1;
	r = L;
	//scanf_s("%d", &c);
	//r->data = c;
	while(c)
	{
		s = (Node*)malloc(sizeof(Node));
		scanf_s("%d", &c);
		if(c == 0)
		{
			r->next = NULL;
			return;
		}
		s->data = c;
		r->next = s;
		r = s;
	}

}

void PrintLink(LinkList L)//打印链表
{
	LinkList P = L->next;
	while(P != NULL)
	{
		printf("%d ", P->data);
		P = P->next;
	}
	printf("\n");
}

int ListLength(LinkList L)//求链表长度
{
	Node *p;
	p = L;
	int j = 0;
	while(p != NULL)
	{
		p = p->next;
		j++;
	}
	return j;
}

void Ins(LinkList *L, DateType x)//尾插元素
{
	Node *s;
	s = (Node *)malloc(sizeof(Node));
	s->data  = x;
	(*L)->next = s;
}

LinkList Merge(LinkList l, LinkList m)//合并两个链表
{
	Node *pl, *pm, *pls;
	LinkList LS;
	InitList(&LS);
	pl = l->next;
	pm = m->next;
	pls = LS;
	int count_l = ListLength(pl), count_m = ListLength(pm);
	int sum = count_l + count_m;
	if(count_l >= count_m)
	{
		while((pl != NULL) || (pm != NULL))
		{
			if(pl != NULL)
			{
				Ins(&pls, pl->data);
				pl = pl->next;
				pls = pls->next;
			}
			if(pm != NULL)
			{
				Ins(&pls, pm->data);
				pm = pm->next;
				pls = pls->next;
			}
		}
	}

	if(count_l <= count_m)
	{
		while((pl != NULL) || (pm != NULL))
		{
			if(pm != NULL)
			{
				Ins(&pls, pm->data);
				pm = pm->next;
				pls = pls->next;
			}
			if(pl != NULL)
			{
				Ins(&pls, pl->data);
				pl = pl->next;
				pls = pls->next;
			}
		}
	}
	pls->next = NULL;
	return LS;
}

//直接插入排序
void InsertSort(Node *head)
{
	Node *p, *pre, *q, *r;
	p = head->next;
	head->next = NULL;
	while(p)
	{
		pre = p->next;
		r = head;
		q = head->next;
		while(q&&q->data<p->data)
		{
			r = q;
			q = q->next;
		}
		p->next = r->next;
		r->next = p;
		p = pre;
	}
}

//测试

#include"Node.h"


void Test1()
{
	LinkList L, M, SUM;
	int sum = 0;
	InitList(&L);
	InitList(&M);
	InitList(&SUM);
	printf("请输入链表A各元素的值（输入0结束\n");
	CreateFromTail(L);
	printf("\n");
	printf("请输入链表B各元素的值（输入0结束\n");
	CreateFromTail(M);
	printf("\n");

	printf("输出链表A：");
	PrintLink(L);
	printf("A链表长度%d\n", ListLength(L));
	printf("\n");
	printf("输出链表B：");
	PrintLink(M);
	printf("B链表长度%d\n", ListLength(M));
	printf("\n");

	SUM = Merge(L, M);
	printf("链表合并后为：\n");
	PrintLink(SUM);
	sum = ListLength(L) + ListLength(M);
	InsertSort(SUM);
	printf("对链表进行直接插入排序后：\n");
	PrintLink(SUM);
}

int main()
{
	Test1();
	system("pause");
	return 0;
}