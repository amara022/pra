#include<stdio.h>
#include<malloc.h>

//删除链表中所有val
typedef struct ListNode
{
	struct ListNode* next;
	int val;
}Node;
Node* getNode(int val)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;
	return node;
}
void myPrint(Node* head)
{
	Node* cur = head;
	while (cur != NULL)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

//反转链表
Node* reverseList(Node* head){
	if (head == NULL)
		return NULL;
	Node* rhead = NULL;
	Node* cur = head;
	Node* next = NULL;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = rhead;
		rhead = cur;
		cur = next;
	}
	return rhead;
}
//返回中间结点
struct ListNode* middleNode(struct ListNode* head){
	if (head == NULL)
		return NULL;
	struct ListNode* cur = head;
	int count = 0;
	while (cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	cur = head;
	for (int i = 0; i<count / 2; i++)
	{
		cur = cur->next;
	}
	return cur;
}
//倒数第k个结点
Node* GetKnode(Node* head, int k)
{
	if (head == NULL||k<0)
		return NULL;
	Node* cur = head;
	int count = 0;
	while (cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	cur = head;
	for (int i = 0; i<(count - k); i++)
	{
		cur = cur->next;
	}
	return cur;
}
//删除所有val
Node* removeElements(Node* head, int val){
	Node* prev = head;
	while (true){
		if (head == NULL)
			return NULL;
		if (prev->val == val){
			prev = prev->next;
			head = prev;
		}
		else
			break;
	}
	while (prev->next != NULL){
		if (prev->next->val == val)
			prev->next = prev->next->next;
		else
		{
			prev = prev->next;
		}
	}
	return head;
}



void test()
{
	Node* a = getNode(1);
	Node* b = getNode(3);
	Node* c = getNode(4);
	Node* d = getNode(9);
	Node* e = getNode(6);
	Node* f = getNode(7);
	Node*head = NULL;
	head = a; a->next = b; b->next = c; c->next = d; d->next = e; e->next = f; f->next = NULL;
	myPrint(head);
	GetKnode(head, 2);
}

