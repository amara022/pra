#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<stdlib.h>

struct ListNode
{
	int val;
	ListNode* next;
}Node;

//头插实现链表的反转
ListNode* Reverse(ListNode* head)
{
	if (head == nullptr)
		return head;
	ListNode* cur = head;
	ListNode* newhead = nullptr;
	while (cur != nullptr)
	{
		ListNode* next = cur->next;
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}
	return newhead;
}
void Printflist(ListNode* head)
{
	ListNode* cur = head;
	while (cur != nullptr)
	{
		cout << cur->val<<' ';
		cur = cur->next;
	}
	cout << endl;
}

int main()
{
	ListNode* a = new ListNode();
	ListNode* head = a;
	ListNode* b = new ListNode();
	ListNode* c = new ListNode();
	head->next = a; a->next = b; b->next = c; c->next = nullptr;
	a->val = 2; b->val = 6; c->val = 9;
	Printflist(head);
	Printflist(Reverse(head));
	system("pause");
}