#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>

typedef struct Node{
	int val;
	struct Node* next;
}Node;
Node* head1 = NULL;
Node* head2 = NULL;
Node* geNode(int val)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;
	return node;
}
void MyPrint(Node* head){
	Node* c = head;
	while (c != NULL){
		printf("%d ", c->val);
		c = c->next;
	}
	printf("\n");
}
Node * front(Node* head,int val)
{
	Node* node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->next = head;
	return node;
}
Node *last(Node* head, int val){
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	if (head == NULL)
	{
		return node;
	}
	else
	{
		Node* last = head;
		while (last->next != NULL){
			last = last->next;
		}
		last->next = node;
		node->next = NULL;
		return head;
	}
}
Node* Revers(Node* head){
	Node * RHead = (Node*)malloc(sizeof(Node));
	RHead = NULL;
	if (head == NULL)
		return NULL;
	else
	{
		Node* cur = head;
		while (cur != NULL)
		{
			Node* next = cur->next;
			cur->next = RHead;
			RHead = cur;
			
			cur = next;
		}
	}return RHead;
}
Node* Mid(Node*head){
	Node* cur = head;
	int count = 0;
	while (cur != NULL){
		count++;
		cur = cur->next;
	}
	cur = head;
	for (int i = 0; i <= (count / 2); i++){

		cur = cur->next;
	}
	return cur;
}
Node* hebing(Node* head1, Node* head2){
	Node* Rhead = NULL;
	Node* last = NULL;
	Node* c1 = head1;
	Node* c2 = head2;
	Node* next1 = c1->next;
	Node* next2 = c2->next;
	while (c1 != NULL && c2 != NULL){
		if (c1 <= c2)
		{
			if (Rhead == NULL)
			{
				Rhead = c1;
				c1->next = NULL;
			}
			else
			{
				last->next = c1;
			}
			last = c1;
			c1 = next1;
		}
		else
		{
			if (Rhead == NULL)
			{
				Rhead = c2;
				c2->next = NULL;
			}
			else
			{
				last->next = c2;
			}
			last = c2;
			c2 = next2;
		}
	}
	return Rhead;
}
Node* copy(Node* head){
	Node* Rhead = NULL;
	Node* cur = head;
	Node* last = NULL;
	while (cur != NULL){
		Node* p = (Node*)malloc(sizeof(Node));
		p->val = cur->val;
		if (Rhead == NULL){
			Rhead = p;
			p->next = NULL;
		}
		else
		{
			last->next = p;
		}
		last = p;
		cur = cur->next;
	}
	last->next = NULL;
	return Rhead;
}

void test()
{
	Node* head = NULL;
	Node* a = geNode(2);
	Node* b = geNode(5);
	Node* e = geNode(10);
	Node* c = geNode(9);
	Node* d = geNode(7);
	head = a;
	a->next = b; b->next = c; c->next = d; d->next = e; e->next = NULL;
	Node* head2 = copy(a);
	MyPrint(head);
	MyPrint(head2);
	Node* mid = Mid(head);
	printf("%d\n", mid->val);	
}