#define _CRT_SECURE_NO_WARNINGS 1
#include<malloc.h>

//���Ա�ṹ
#define MAX 1000
typedef struct Sqlist
{
	int date[MAX];    //���Ա�����
	int length;
}Sqlist;
//������ṹ
typedef struct Node
{
	int val;
	struct Node* next;
}Node;

//������ת��Ϊ����
Node* GetNode(int arr1[])
{
	Node* head = nullptr;
	Node* last = nullptr;
	for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
	{
		Node* node = (Node*)malloc(sizeof(Node));
		node->val = arr1[i];
		node->next = nullptr;
		if (head == nullptr)
		{
				head = node;
				return head;
		}
		else
		{
			last->next = node;
		}
		last = node;
		node->next = nullptr;
	}
	return head;
}

int main()
{
	int arr1[MAX] = {};
	int arr2[MAX] = {};
	return 0;
}