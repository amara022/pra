#define _CRT_SECURE_NO_WARNINGS 1

typedef struct Node
{
	int val;
	Node* prev;      //前
	Node* next;      //后
}Node;
typedef struct freelist
{
	Node* head;      //头结点
	Node* last;      //尾结点
	int len;         //长
};