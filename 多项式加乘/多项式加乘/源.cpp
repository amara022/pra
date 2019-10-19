#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//���ṹ����
typedef struct Node
{
	float coe;    //ϵ��
	int exp;      //ָ��
	struct Node* next;
	struct Node* prev;
}Node;
//freelist��
class freelist
{
public:
	Node* front;
	Node* last;
	int n;     //����
	//����
	freelist()
	{
		front = NULL;
		last = front;
		n = 0;
	}
	//β��
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
		}
		else
		{
			last->next = c;
		}
		c->next = NULL;
		last = c;
	}
	//ǰ��
	void pushfront(float a,int b)
	{
		n++;
		Node* c = new Node[sizeof(Node)];
		c->coe = a;
		c->exp = b;
		if (front  == NULL)
		{
			front = c;
			c->next = NULL;
		}
		else
		{
			Node* n = front;
			n->next = front->next;
			n->prev = c;
			c->prev = NULL;
			c->next = n;
			front = c;
		}
	}
	//����Ҫ���ӡ����ʽ
	void Print()
	{
		Node* cur = this->front;
		for (int i = 0; i < this->n;i++)
		{
			cout << cur->coe << " " << cur->exp << endl;
			cur = cur->next;
		}
	}
	//��ɶ���ʽ����
	void In()
	{
		float a;
		int b;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			pushback(a, b);
		}
	}
	//�ӷ�����
	void operator+(const freelist& L)
	{
		freelist c;
		Node* cur1 = this->front;
		Node* cur2 = L.front;
		while (cur1!=NULL&&cur2!=NULL)
		{
			if (cur1->exp == cur2->exp)
			{
				c.pushback(cur1->coe + cur2->coe, cur1->exp);
				c.n += 1;
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			else if (cur1->exp > cur2->exp)
			{
				c.pushback(cur1->coe, cur1->exp);
				cur1 = cur1->next;
				c.n += 1;
			}
			else if (cur1->exp<cur2->exp)
			{
				c.pushback(cur2->coe, cur2->exp);
				cur2 = cur2->next;
				c.n+=1;
			}
		}
		if(cur1 == NULL)
		{
			while (cur2 != NULL)
			{
				c.pushback(cur2->coe, cur2->exp);
				cur2 = cur2->next;
				c.n += 1;
			}
		}
		else if (cur2 == NULL)
		{
			while (cur1 !=NULL)
			{
				c.pushback(cur1->coe, cur1->exp);
				cur1 = cur1->next;
				c.n += 1;
			}
		}
		cout << c.n << endl;
		c.Print();
	}
	//�˷�����
	void operator*(const freelist& L)
	{
		Node* cur1 = this->front;
		Node* cur2 = L.front;
		freelist r;
		for (cur1=this->front; cur1!=NULL; cur1=cur1->next)
		{
			for (cur2 = L.front; cur2 != NULL; cur2 = cur2->next)
			{
				r.pushback(cur1->coe*cur2->coe, cur1->exp + cur2->exp);
				r.n++;
			}
		}
		cout  << r.n << endl;
		r.Print();
	}
};


int main()
{
	freelist a;
	freelist b;
	//cout<<"�����������"
	cin >> a.n;
	cin >> b.n;
	a.In();
	b.In();
	//a.Print();
	//b.Print();
	a + b;
	a*b;
	return 0;
}

