#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// ��������������������
const int SIZE = 1000;

// ˫��ѭ��������
struct DualNode
{
	int data;           // ����ÿ������ֵ
	int len;            // ����ĳ���
	DualNode* prior;    // ǰ�̽��
	DualNode* next;     // ��̽��
};
typedef DualNode* DuLinkList;


void InitList(DuLinkList *L, char *str)
{
	DuLinkList p, q;
	(*L) = (DuLinkList)malloc(sizeof(DualNode));
	(*L)->prior = NULL;
	(*L)->next = NULL;
	(*L)->data = '+';           // Ĭ�Ϸ���λΪ'+'
	p = (*L);

	int len = strlen(str);
	int cc = 1;
	int LEN = 0;

	int end = 0;
	if (str[0] == '-')
	{
		(*L)->data = '-';
		end = 1;    // ����Ƿ��ţ� ��ֻҪ���ַ����ڶ����ַ�λ��
	}

	for (int i = len - 1; i >= end; --i)
	{
		if (cc % 5)
		{
			q = (DuLinkList)malloc(sizeof(DualNode));
			q->data = str[i] - '0';         // �ַ�����ȥ'0'����intֵ
			q->prior = p;
			p->next = q;
			p = q;
			++LEN;
		}
		++cc;
	}

	// ѭ������
	p->next = (*L);
	(*L)->prior = p;
	(*L)->len = LEN;                    // ��¼����ĳ���-1 �������� ��������λ�ĳ���
}

// ���ӷ�
DuLinkList add(DuLinkList a1, DuLinkList b1)
{
	int len1 = a1->len;
	int len2 = b1->len;
	DuLinkList a, b;        // aΪ�ϳ����������� bΪ�϶̵���������
	if (len1 > len2)
	{
		a = a1;
		b = b1;
	}
	else
	{
		a = b1;
		b = a1;
	}
	len1 = a->len;          // �ϳ�������
	len2 = b->len;          // �϶�������

	int cnt = 0;
	int ex = 0;             // �����λֵ
	while (cnt != len1)
	{
		a = a->next;
		b = b->next;

		if (cnt >= len2)    // �Ѿ������϶������ȣ����Բ���Ҫ��b->data
			a->data = a->data + ex;
		else
			a->data = a->data + b->data + ex;
		ex = 0;
		if (a->data >= 10) a->data -= 10, ex = 1;   // ����10��ʾ�н�λֵ
		++cnt;
	}

	if (ex)
	{   
		DuLinkList p = (DuLinkList)malloc(sizeof(DualNode));
		p->data = ex;

		p->next = a->next;
		a->next->prior = p;
		p->prior = a;
		a->next = p;

		a = p;
		++len1;
	}
	a = a->next;       // �ص�����λ
	a->len = len1;      // ע��ͷ�����ȱ仯
	return a;
}

int B(DuLinkList a1, DuLinkList b1)
{
	DuLinkList a, b;        // aΪ�ϳ����������� bΪ�϶̵���������
	int len1 = a1->len;
	int len2 = b1->len;
	if (len1 > len2)
	{
		return 1;
	}
	else if (len1<len2)
	{
		return 0;
	}
	else
	{
		DuLinkList tmp1 = a1, tmp2 = b1;
		int cnt = 0;
		tmp1 = tmp1->prior;
		tmp2 = tmp2->prior;
		if (len1<len2)
			len1 = len2;
		while (cnt != len1)
		{
			if (tmp1->data > tmp2->data)
			{
				return 1;
			}
			else if (tmp1->data < tmp2->data)
			{
				return 0;
			}
			tmp1 = tmp1->prior;
			tmp2 = tmp2->prior;
			++cnt;
		}
	}
}
int h(DuLinkList a1, DuLinkList b1)
{
	if (!(a1->data ^ b1->data))
	{   // ͬ��
		return 1;
	}
	else
	{   // ���
		return 0;
	}
}
// ������
DuLinkList sub(DuLinkList a1, DuLinkList b1)
{
	int len1 = a1->len;
	int len2 = b1->len;
	DuLinkList a = new DualNode;
	DuLinkList b = new DualNode;// aΪ�ϳ����������� bΪ�϶̵���������
	if (len1 > len2)
	{
		a = a1;
		b = b1;
	}
	else if (len1 < len2)
	{
		a = b1;
		b = a1;
	}
	else
	{
		// ��������ͬʱ�� �Ծ���ֵ�����Ϊ����a
		DuLinkList tmp1 = a1, tmp2 = b1;
		int cnt = 0;
		tmp1 = tmp1->prior;
		tmp2 = tmp2->prior;
		while (cnt != len1)
		{
			if (tmp1->data > tmp2->data)
			{
				a = a1;
				b = b1;
				break;
			}
			else if (tmp1->data < tmp2->data)
			{
				a = b1;
				b = a1;
				break;
			}
			tmp1 = tmp1->prior;
			tmp2 = tmp2->prior;
			++cnt;
		}
		if (cnt == len1)
		{ // �����������һ���Ļ��� �͵�ִ��������
			a = a1;
			b = b1;
		}
	}

	len1 = a->len;          // �ϳ�������
	len2 = b->len;          // �϶�������

	int cnt = 0;
	int ex = 0;             // �����λֵ
	while (cnt != len1)
	{
		a = a->next;
		b = b->next;
		
		if (cnt >= len2)    // �Ѿ������϶������ȣ����Բ���Ҫ��b->data
			a->data = a->data - ex;
		else
			a->data = a->data - b->data - ex;
		ex = 0;
		if (a->data < 0) a->data += 10, ex = 1;   // С��0��ʾ�н�λ
		++cnt;
	}

	// �����ǽϴ�ľ���ֵ��ȥ��С�ľ���ֵ�� �������ղ��������λ�Ľ�λ
	a = a->next;       // �ص�����λ
	a->len = len1;      // ע��ͷ�����ȱ仯
	return a;
}




// �������Ľ��
void print(DuLinkList a)
{
	int len = a->len;

	DuLinkList tmp = a;
	if (a->data == '-')
	{
		printf("%c", a->data);
		a = a->prior;
		while (a->data == 0 && a->prior != tmp)
		{ // �ڶ��������Ǳ���� 0 �Ľ��ȥ��
			a = a->prior; // ȥ��ǰ����
			--len;
		}
	}
	else
	{
		a = a->prior;
		while (a->data == 0 && a->prior != tmp)
		{ // �ڶ��������Ǳ���� 0 �Ľ��ȥ��
			a = a->prior; // ȥ��ǰ����
			--len;
		}
	}
	while (len)
	{ // ��ͷ��ʼ�������
		printf("%d", a->data);
		a = a->prior;
		--len;
		if (!(len % 4) && len) putchar(',');
	}
	puts("");
}

int main(int argc, char const *argv[])
{
	char a1[SIZE], b1[SIZE];
	char ch;
	printf("�������һ������(ÿ��λһ�飬����ö��Ÿ���): ");
	scanf("%s", a1);

	printf("�������һ������(ÿ��λһ�飬����ö��Ÿ���): ");
	scanf("%s", b1);

	DuLinkList *a = (DuLinkList*)malloc(sizeof(DuLinkList));
	DuLinkList *b = (DuLinkList*)malloc(sizeof(DuLinkList));
	InitList(a, a1);    // ��ʼ������
	InitList(b, b1);    // ��ʼ������
	DuLinkList res;
	printf("��ѡ�������:<+,->:\n");
	scanf("%s", &ch);
	if (ch == '+')
	{
		if (h(*a,*b))
			res = add(*a, *b);
		else
			res = sub(*a, *b);
	}
	else if (ch == '-')
	{
		if (h(*a, *b))
		{
			if (B(*a, *b))
				res = sub(*a, *b);
			else
			{
				res = sub(*a, *b);
				res->data = ' ';
			}
		}
		else
		{
			if (B(*a,*b))
				res = sub(*a, *b);
			else
			{
				res = sub(*a, *b);
				res->data = '-';
			}
		}
	}
	else
		printf("�˰汾��֧�ִ���������");
	printf("���: ");
	print(res);

	return 0;
}