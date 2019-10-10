#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>

#if 0
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}Node;

struct ListNode* Merge(struct ListNode* l1, struct ListNode* l2){
	if (l1 == NULL) {
		return l2;
	}

	if (l2 == NULL) {
		return l1;
	}

	Node *rHead = NULL; // �������
	Node *last = NULL;  // ��¼ rHead �����һ�����
	Node *c1 = l1;  // ���� l1 ����
	Node *c2 = l2;  // ���� l2 ����

	while (c1 != NULL && c2 != NULL) {
		if (c1->val <= c2->val) {
			Node *next = c1->next;
			// �� c1 β�嵽 rHead
			c1->next = NULL;
			if (rHead == NULL) {
				rHead = c1;
			}
			else {
				last->next = c1;
			}
			last = c1;

			c1 = next;
		}
		else {
			Node *next = c2->next;
			// �� c2 β�嵽 rHead
			c2->next = NULL;
			if (rHead == NULL) {
				rHead = c2;
			}
			else {
				last->next = c2;
			}
			last = c2;

			c2 = next;
		}
	}

	// ֻ��һ������Ľ�㱻��������
	// ʣ��Ľ��һ�����ٱ� last �����ֵҪ��
	// last ������ rHead �е����һ�����
	if (c1 != NULL) {
		last->next = c1;
	}
	else {
		last->next = c2;
	}

	return rHead;
}
void Printlist(Node* Head)
{
	Node* cur = Head;
	while (cur != NULL)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
}
int main()
{
	Node* a = (Node*)malloc(sizeof(Node));
	Node* b = (Node*)malloc(sizeof(Node));
	Node* c = (Node*)malloc(sizeof(Node));
	Node* d = (Node*)malloc(sizeof(Node));
	Node* e = (Node*)malloc(sizeof(Node));
	Node* f = (Node*)malloc(sizeof(Node));
	a->val = 1; b->val = 3; c->val = 5; d->val = 7; e->val = 6; f->val = 9;
	a->next = b; b->next = d; d->next = NULL;
	c->next = e; e->next = f; f->next = NULL;
	Node* L1 = a;
	Node* L2 = c;
	Printlist(Merge(L1, L2));
	return 0;
}
#endif

 struct Node
{
	int val;
	struct Node* next;
};

 //��������(β��)
 struct Node* buildList(int* arr, int n)
 {
	 int i = 0;
	 struct Node *head, *r, *s;
	 head = (struct Node*)malloc(sizeof(struct Node));
	 head->next = NULL;
	 r = head;
	 for (i = 0; i<n; i++) {
		 s = (struct Node*)malloc(sizeof(struct Node));
		 s->val = arr[i];
		 r->next = s;
		 r = s;
	 }
	 r->next = NULL;
	 return head;
 }
 //β��Ԫ��
 void Ins(struct Node* L, int x)
 {
	 struct Node *s;
	 s = (struct Node*)malloc(sizeof(struct Node));
	 s->val = x;
	 L->next = s;
 }

 int Getlength(struct Node* head)
 {
	 struct Node* cur = head;
	 int count = 0;
	 while(cur != NULL)
	 {
		 count++;
		 cur = cur->next;
	 }
	 return count;
 }

 //�ϲ�����
 struct Node* Merge(struct Node* l1, struct Node* l2){
	 if (l1 == NULL) 
		 return l2;
	 if (l2 == NULL) 
		 return l1;
	 struct Node *p1, *p2, *pnew;
	 struct Node* LS;
	 LS = (struct Node*)malloc(sizeof(struct Node));
	 p1 = l1->next;
	 p2 = l2->next;
	 pnew = LS;
	 int count_1 = Getlength(p1), count_2 = Getlength(p2);
	 int sum = count_1 + count_2;
	 if (count_1 >= count_2)
	 {
		 while ((p1 != NULL) || (p2 != NULL))
		 {
			 if (p1 != NULL)
			 {
				 Ins(pnew, p1->val);
				 p1 = p1->next;
				 pnew = pnew->next;
			 }
			 if (p2 != NULL)
			 {
				 Ins(pnew, pnew->val);
				 p2 = p2->next;
				 pnew = pnew->next;
			 }
		 }
		 if (count_1 <= count_2)
		 {
			 while ((p1 != NULL) || (p2 != NULL))
			 {
				 if (p2 != NULL)
				 {
					 Ins(pnew, p2->val);
					 p2 = p2->next;
					 pnew = pnew->next;
				 }
				 if (p1 != NULL)
				 {
					 Ins(pnew, p1->val);
					 p1 = p1->next;
					 pnew = pnew->next;
				 }
			 }
		 }
		 pnew->next = NULL;
		
	 }
	 return LS;
 }

 //ֱ�Ӳ�������
 void InsertSort(struct Node *head)
 {
	 struct Node *p, *pre, *q, *r;
	 p = head->next;
	 head->next = NULL;
	 while (p)
	 {
		 pre = p->next;
		 r = head;
		 q = head->next;
		 while (q&&q->val<p->val)
		 {
			 r = q;
			 q = q->next;
		 }
		 p->next = r->next;
		 r->next = p;
		 p = pre;
	 }
 }


 //��ӡ����
 void printLinkedList(struct Node* head) 
 { 
	 struct Node *c = head->next;
	 while (c != NULL) 
	 {
		 printf(" %d", c->val);
		 c = c->next;
	 }
	 printf("\n");
 }

 //����
 int main()
 {
	 int arr1[] = { 30, 41, 15, 12, 56, 80 };
	 int arr2[] = { 23, 56, 78, 23, 12, 33, 79, 90, 55 };
	 struct Node* A = buildList(arr1, sizeof(arr1) / sizeof(arr1[0]));
	 struct Node* B = buildList(arr2, sizeof(arr2) / sizeof(arr2[0]));
	 printLinkedList(Merge(A, B));
	 return 0;
 }