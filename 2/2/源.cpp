
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


 // 双向链表的结构体定义
typedef struct Node
{
	int data;
	struct Node *prior;
	struct Node *next;
}DLNode;

//双向链表的初始化
void ListInitiate(DLNode **head) 
{
	if ((*head = (DLNode *)malloc(sizeof(DLNode))) == NULL)
		exit(0);
	(*head)->prior = *head;
		(*head)->next = *head;
}

//双向链表的表长
int ListLength(DLNode *head) 
{
	DLNode *p = head;
	int size = 0;
	while (p->next != head)
	{
		p = p->next;
		size++;
	}
	return size;
}
//双向链表的数据插入
int ListInsert(DLNode *head, int i, int x) 
{
	DLNode *p, *s;
	int j;
	p = head->next;
	j = 0;
	while (p != head&&j<i)
	{
		p = p->next;
		j++;
	}
	if (j != i)
	{
		printf("\n插入位置不合法");
		return 0;
	}
	if ((s = (DLNode *)malloc(sizeof(DLNode))) == NULL) exit(0);
	s->data = x;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return 1;
}


//读入输入的数据 
int InputNumber(DLNode *head) 
{
int input, i = 0;
char c;
scanf("%d%c", &input, &c);
while (1)
{
	if (input<0 && i == 0)
	{
		head->data = 0;
		ListInsert(head, i, input);
	}
	else if (input >= 0 && i == 0)
	{
		head->data = 1;
		ListInsert(head, i, input);
	}
	else
	{
		if (head->next->data >= 0)
			ListInsert(head, i, input);
		else
		{
			input=-1*input;
			ListInsert(head, i, input);
		}
	}
	i++;
	if (c == ';') 
		break;
	scanf("%d%c", &input, &c);
}
return 1;
}

//从表尾输出数据元素 
void OutputNumber(DLNode *head, int sign) 
{
DLNode *r = head->next;
while (r->data == 0 && r != head->prior)
{
	r = r->next;
}
if (sign == 1)
{
	printf("结果是:");
}
else
{
	printf("结果是: -");
}
printf("%d", r->data);
r = r->next;
while (r != head)
{
	if (r->data<10)
	{
		printf("");
		printf("%d", r->data);
	}
	else if (r->data<100)
	{
		printf(",00");
		printf("%d", r->data);
	}
	else if (r->data<1000)
	{
		printf(",0");
		printf("%d", r->data);
	}
	else
	{
		printf(",%d", r->data);
	}
	r = r->next;
}
printf("\n");
}

DLNode* add(DLNode *head1, DLNode *head2){
	DLNode *p1 = head1->prior, *p2 = head2->prior;
	while (p1 != head1&&p2 != head2) //每个链表元素相加
	{
		p1->data += p2->data;
		p1 = p1->prior; 
		p2 = p2->prior;
	}
	p1 = head1->prior;
	while (p1 != head1->next) //处理链表元素
	{
		if (p1->data >= 10000)
		{
			p1->prior->data += p1->data / 10000;
			p1->data %= 10000;
		} 
		if (p1->data<0) //处理负数
		{
			if (head1->next->data != 0)
			{
				p1->prior->data -= 1;
				p1->data += 10000;
			}
		} p1 = p1->prior;
	}
	if (head1->next->data >= 10000) //处理最前面的数
	{
		ListInsert(head1, 0, head1->next->data / 10000);
		head1->next->next->data %= 10000;
	}
	if (head1->data <= -10000)
	{	
		ListInsert(head1, 0, head1->next->data / -10000);
		head1->next->next->data %= -10000;
	}
	return head1;
}

DLNode* jian(DLNode *h1, DLNode *h2) //两数相减
{
	DLNode *p1 = h1->prior, *p2 = h2->prior;
	while (p1 != h1&&p2 != h2) //每个链表元素相减
	{
		
		p1->data -= p2->data;
		p1 = p1->prior;
		p2 = p2->prior;
	}
	p1 = h1->prior;
	while (p1 != h1->next) //处理链表元素
	{
		if (p1->data >= 10000)
		{
			p1->prior->data += p1->data / 10000;
			p1->data %= 10000;
		}
		if (p1->data<0) //处理负数
		{
			if (h1->next != 0)
			{
				p1->prior->data -= 1;
				p1->data += 10000;
			}
		} 
		p1 = p1->prior;
	}
	if (h1->next->data >= 10000) //处理最前面的数
	{
		ListInsert(h1, 0, h1->next->data / -10000);
		h1->next->next->data %= 10000;
	}
	if (h1->data <= -10000)
	{
		ListInsert(h1, 0, h1->next->data / 10000);
		h1->next->next->data %= -10000;
	}
	return h1;
}

int main()
{
	char ch, ch1;
	while (1)
	{
		DLNode *a, *b, *c;
		ListInitiate(&a);
		ListInitiate(&b);
		ListInitiate(&c);
		printf("请输入数A(以分号结束):");
		InputNumber(a);

		printf("\n");
		printf("请输入数B(以分号结束):");
		
		InputNumber(b);
		printf("请选择操作符:<+,->:\n");
		scanf("%s", &ch1);
		{if (ch1 == '+')
		{
			DLNode* c=add(a, b);
			OutputNumber(c, 1);
		}
		else if (ch1 == '-')
		{
			DLNode* d=jian(a, b);
			OutputNumber(d, 1);
		}
		else
			printf("此版本不支持%c运算", ch1);
		}
		printf("要继续吗,(y/n) :");
		scanf("%s", &ch);
		if (ch == 'Y' || ch == 'y')
		{
			printf("\n");
			continue;
		}
		else exit(0);
	}
}
