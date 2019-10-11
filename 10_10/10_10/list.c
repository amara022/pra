#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>

 struct Node
{
	int val;
	struct Node* next;
};

 //建立链表(尾插)
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
 //尾插元素
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

 //合并链表
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

 //直接插入排序
 struct listNode* ListInsertSort(struct Node *L)
 {
	 struct Node *originListNode;   
	 struct Node *nodeScan;         
	 struct Node *preNode;          
	 struct Node *newNode;         

	 originListNode = L->next;
	 L->next = NULL;


	 while (originListNode != NULL)
	 {
		 preNode = NULL;
		 newNode = originListNode;
		 nodeScan = L;         
		 while ((nodeScan != NULL) && (nodeScan->val < newNode->val))
		 {
			 preNode = nodeScan;
			 nodeScan = nodeScan->next;
		 }

		 originListNode = originListNode->next;

		 if (nodeScan == L)
			 L = newNode;
		 else
			 preNode->next = newNode;

		 newNode->next = nodeScan;

		 return L;
	 }
 }



 //打印链表
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

 //测试
 int main()
 {
	 int arr1[6] = { 30, 41, 15, 12, 56, 80 };
	 int arr2[9] = { 23, 56, 78, 23, 12, 33, 79, 90, 55 };
	 struct Node* A = buildList(arr1, sizeof(arr1) / sizeof(arr1[0]));
	 struct Node* B = buildList(arr2, sizeof(arr2) / sizeof(arr2[0]));
	 printLinkedList(A);
	 printLinkedList(B);
	 struct Node* C=Merge(A, B);
	 printLinkedList(C);
	 struct Node*D = ListInsertSort(C);
	 printLinkedList(D);
	 return 0;
 }