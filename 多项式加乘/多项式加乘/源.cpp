#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

typedef struct Node
{
	float coe;    //ϵ��
	int exp;      //ָ��
	struct Node* next;
	struct Node* prev;
}Node;

class freelist
{
private:
	Node* front;
	Node* last;
	int n;     //����
public:
	freelist()
	{
		front = NULL;
		last = front;
		n = 0;
	}
	void pushback(float a, int b)
	{
		Node* c = new Node[sizeof(Node)];
		c->coe = a;
		c->exp = b;
		c->next = NULL;
		if (front==last&&last == NULL)
		{
			front = c;
			front->prev = NULL;
			last = c;
			n = 1;
		}
		else
		{
			last = c;
			n++;
		}
	}
};
