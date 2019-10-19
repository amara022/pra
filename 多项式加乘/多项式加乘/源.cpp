#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//结点结构定义
typedef struct Node
{
	float coe;    //系数
	int exp;      //指数
	struct Node* next;
	struct Node* prev;
}Node;
//freelist类
class freelist
{
public:
	Node* front;
	Node* last;
	int n;     //项数
	//构造
	freelist()
	{
		front = NULL;
		last = front;
		n = 0;
	}
	//尾插
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
	//前插
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
	//按照要求打印多项式
	void Print()
	{
		Node* cur = this->front;
		for (int i = 0; i < this->n;i++)
		{
			cout << cur->coe << " " << cur->exp << endl;
			cur = cur->next;
		}
	}
	//完成多项式输入
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
	//加法重载
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
	//乘法重载
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
	//cout<<"输出两个项数"
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

