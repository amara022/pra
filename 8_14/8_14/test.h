#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node{
	int val;
	struct Node* next;
}Node;

//倒数第k个结点
Node*  getlK(Node* head, int k)
{
	Node* cur = head;
	int count = 0;
	while (cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	cur = head;
	for (int i = 0; i < count - k; i++)
	{
		cur = cur->next;
	}
	return cur;
}

Node* getlist()
{
	Node* a = (Node*)malloc(sizeof(Node));
	a->val = 4;
	Node* b = (Node*)malloc(sizeof(Node));
	b->val = 9;
	Node* c = (Node*)malloc(sizeof(Node));
	c->val = 8;
	Node* d = (Node*)malloc(sizeof(Node));
	d->val = 5;
	Node* e = (Node*)malloc(sizeof(Node));
	e->val = 7;
	a->next = b; b->next = c; c->next = d; d->next = e; e->next = NULL;
	return a;
}
void Printnode(Node* head)
{
	Node* cur = head;
	while (cur != NULL)
	{
		printf("%d ", cur->val);
	}
}
void test()
{
	Node* head = getlist();
	Node* c = getlK(head, 2);
	printf("%d\n", c->val);//5
	system("pause");
}