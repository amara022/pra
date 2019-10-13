#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//�ڵ����Ͷ���
typedef struct Node
{
	int date;
	struct Node*next;
}*LinkList;




void InitL(LinkList *L)
{
	L = (LinkList*)malloc(sizeof(Node));
	(*L)->next = NULL;
}

void?CreateFromTail(LinkList?L)//β�巨����������
{
	Node?*r, *s;
	DateType?c? = 1;
	r? = L;

	while?(c)
	{
		s? = (Node*)malloc(sizeof(Node));
		scanf_s("%d", &c);
		if?(c? == 0)
		{
			r->next? = NULL;
			return;
		}
		s->data? = c;
		r->next? = s;
		r? = s;
	}

}

void PrintL(LinkList?L)//��ӡ����
{
	LinkList?P? = L->next;
	while?(P? != NULL)
	{
		printf("%d?", P->data);
		P? = P->next;
	}
	printf("\n");
}

int?ListLength(LinkList?L)//��������
{
	Node?*p;
	p? = L;
	int?j? = 0;
	while?(p? != NULL)
	{
		p? = p->next;
		j++;
	}
	return?j;
}

void?Ins(LinkList?*L, DateType?x)//β��Ԫ��
{
	Node?*s;
	s? = (Node?*)malloc(sizeof(Node));
	s->data? = x;
	(*L)->next? = s;
}

LinkList?Merge(LinkList?l, LinkList?m)//�ϲ���������
{
	Node?*pl, *pm, *pls;
	LinkList?LS;
	InitList(&LS);
	pl? = l->next;
	pm? = m->next;
	pls? = LS;
	int?count_l? = ListLength(pl), count_m? = ListLength(pm);
	int?sum? = count_l? + count_m;
	if?(count_l? >= count_m)
	{
		while?((pl? != NULL) || (pm? != NULL))
		{
			if?(pl? != NULL)
			{
				Ins(&pls, pl->data);
				pl? = pl->next;
				pls? = pls->next;
			}
			if?(pm? != NULL)
			{
				Ins(&pls, pm->data);
				pm? = pm->next;
				pls? = pls->next;
			}
		}
	}

	if?(count_l? <= count_m)
	{
		while?((pl? != NULL) || (pm? != NULL))
		{
			if?(pm? != NULL)
			{
				Ins(&pls, pm->data);
				pm? = pm->next;
				pls? = pls->next;
			}
			if?(pl? != NULL)
			{
				Ins(&pls, pl->data);
				pl? = pl->next;
				pls? = pls->next;
			}
		}
	}
	pls->next? = NULL;
	return?LS;
}

void?InsertSort(Node?*head)??//ֱ�Ӳ�������
{
	Node?*p, *pre, *q, *r;
	p? = head->next;
	head->next? = NULL;
	while?(p)
	{
		pre? = p->next;
		r? = head;
		q? = head->next;
		while?(q&&q->data<p->data)
		{
			r? = q;
			q? = q->next;
		}
		p->next? = r->next;
		r->next? = p;
		p? = pre;
	}
}

//*************test.c*****����ʵ��***********

#include"Node.h"


void?Test1()
{
	LinkList?L, M, SUM;
	int?sum? = 0;
	InitList(&L);
	InitList(&M);
	InitList(&SUM);
	printf("����������L��Ԫ�ص�ֵ������0������\n");
	CreateFromTail(L);
	printf("\n");
	printf("����������M��Ԫ�ص�ֵ������0������\n");
	CreateFromTail(M);
	printf("\n");

	printf("����?L?=");
	PrintLink(L);
	printf("L?������?%d\n", ListLength(L));
	printf("\n");
	printf("����?M?=");
	PrintLink(M);
	printf("M?������=?%d\n", ListLength(M));
	printf("\n");

	SUM? = Merge(L, M);
	printf("����?SUM?=?");
	PrintLink(SUM);
	sum? = ListLength(L) + ListLength(M);
	InsertSort(SUM);
	PrintLink(SUM);
}

int?main()
{
	Test1();
	system("pause");
	return?0;
}