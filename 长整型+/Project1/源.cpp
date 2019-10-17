#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<malloc.h>
using namespace std;


//����˫������ṹ
typedef struct node{
	int info;
	struct node *prior, *next;
}DLink;


//��������
DLink *Dcreat()
{
	DLink *head, *p, *last;
	char c;
	int num;
	int flag = 0; //�����Ƿ�Ϸ�
	int len = 0;//����������
	head = (DLink *)malloc(sizeof(DLink));
	head->next = NULL;
	head->prior = NULL;
	head->info = 1;//��ʼ����λΪ1
	last = head;
	while ((c = getchar()) != ';')
	{
		if (c == '-')
		{
			head->info = -1;//����λ
			continue;
		}
		if (c == ',')
		{
			continue;
		}
		num = c - '0';
		if (num > 9 || num <0){
			flag = 1; //���벻�Ϸ�
			break;
		}
		p = (DLink*)malloc(sizeof(DLink));
		p->info = num;
		len++;
		if (head->next == NULL)
		{
			head->next = p;
			p->prior = head;
			last = p;
		}
		else
		{
			p->prior = last;
			last->next = p;
			last = p;
		}
	}
	if (flag == 0)
	{
		last->next = NULL;
		head->prior = last;
		head->info = (head->info)*len;
	}
	else
	{
		head->info = 0;
	}
	return head;
}

//ʵ�ּӷ�
DLink *addition(DLink *a, DLink *b)
{
	int symbol = abs(a->info) / (a->info);
	int len_a = abs(a->info);
	int len_b = abs(b->info);
	DLink *upper, *lower;
	if (len_a > len_b)
	{
		upper = a;
		lower = b;
	}
	else
	{
		upper = b;
		lower = a;
	}
	int len_up = abs(upper->info);
	int len_low = abs(lower->info);
	int cnt = 0;
	int carry = 0; //��λ            
	while (cnt != len_up)
	{
		upper = upper->prior; //��λ��ʼ
		lower = lower->prior;
		if (cnt < len_low)
		{
			upper->info = upper->info + lower->info + carry;
		}
		else
		{
			upper->info = upper->info + carry;
		}
		carry = 0;
		if (upper->info >= 10)
		{
			upper->info -= 10, carry = 1;
		}
		++cnt;
	}
	if (carry)
	{
		DLink *p;
		p = (DLink *)malloc(sizeof(DLink));
		p->info = carry;
		p->prior = upper->prior;
		upper->prior->next = p;
		p->next = upper;
		upper->prior = p;
		upper = p;
		++len_up;
	}
	upper = upper->prior;
	upper->info = symbol*len_up;
	return upper;
}

//ʵ�ּ���
DLink *subtraction(DLink *a, DLink *b)
{
	int len_a = abs(a->info);
	int len_b = abs(b->info);
	DLink *upper = NULL, *lower = NULL;
	if (len_a > len_b)
	{
		upper = a;
		lower = b;
	}
	else if (len_a < len_b)
	{
		upper = b;
		lower = a;
	}
	else
	{
		DLink *tmp1 = a, *tmp2 = b;
		int cnt = 0;
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
		while (cnt != len_a)
		{
			if (tmp1->info > tmp2->info)
			{
				upper = a;
				lower = b;
				break;
			}
			else if (tmp1->info < tmp2->info)
			{
				upper = b;
				lower = a;
				break;
			}
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
			++cnt;
		}
		if (cnt == len_a)
		{
			upper = a;
			lower = b;
		}
	}
	int len_up = abs(upper->info);
	int len_low = abs(lower->info);
	int symbol = abs(upper->info) / (upper->info);
	int cnt = 0;
	int carry = 0;  // ��λ
	while (cnt != len_up)
	{
		upper = upper->prior;
		lower = lower->prior;
		if (cnt < len_low)
		{
			upper->info = upper->info - lower->info - carry;
		}
		else
		{
			upper->info = upper->info - carry;
		}
		carry = 0;
		if (upper->info < 0)
		{
			upper->info += 10, carry = 1;
		}
		++cnt;
	}
	upper = upper->prior;
	upper->info = symbol*len_up;
	return upper;
}

//�����ע���Ƿ�Ϊ��-��
void printDlink(DLink *head)
{
	DLink *p;
	p = head;
	int len = abs(p->info);
	int cnt = 1;
	if (p->info < 0)
	{
		printf("-");
	}
	p = p->next;
	while (p->info == 0 && p->next != NULL)
	{
		p = p->next;
		--len;
	}
	while (len)
	{
		printf("%d", p->info);
		p = p->next;
		--len;
		if (!(len % 4) && len) putchar(',');
	}
}

void main()
{
	printf("��������Ҫ������������������ԷֺŸ���(�磺-9999,9999;1,0000,0000)\n");
	DLink *a;
	a = Dcreat();
	if (a->info == 0)
	{
		printf("invalid input");
	}
	else
	{
		DLink *b;
		b = Dcreat();
		if (b->info == 0)
		{
			printf("invalid input");
		}
		else
		{
			DLink *c;
			if ((a->info)*(b->info)<0)
			{
				c = subtraction(a, b);
			}
			else
			{
				c = addition(a, b);
			}
			printDlink(c);
		}
	}
}