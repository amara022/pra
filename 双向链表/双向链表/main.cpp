#define _CRT_SECURE_NO_WARNINGS 1

typedef struct Node
{
	int val;
	Node* prev;      //ǰ
	Node* next;      //��
}Node;
typedef struct freelist
{
	Node* head;      //ͷ���
	Node* last;      //β���
	int len;         //��
};