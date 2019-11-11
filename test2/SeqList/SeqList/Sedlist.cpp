#include<iostream>
using namespace std;
#define MAXSIZE 100
#define ElemType int
typedef struct
{
	ElemType Data[MAXSIZE];
	int length;
}List;

void GetElem(List *La, int i, ElemType *e)
{
	*e = La->Data[i];
}

int LocateElem(List *La, ElemType e)
{
	for (int i = 0; i<La->length; i++)
	if (e == La->Data[i])
		return 1;
	return 0;
}

void ListInsert(List* La, int e_loc, ElemType e)
{
	La->Data[e_loc] = e;
	La->length++;
}

void Union(List *La, List *Lb)//���Ĵ��� 
{
	int La_len = La->length, Lb_len = Lb->length;
	int i = 0;
	ElemType e;
	for (i = 0; i<Lb_len; i++)
	{
		GetElem(Lb, i, &e);
		if (!LocateElem(La, e))
			ListInsert(La, La_len++, e);
	}
}

int main()
{
	List La, Lb;
	cout << "�����������ϳ���" << endl;
	cin>>La.length;
	cin>>Lb.length;
	cout << "������A:" << endl;
	for (int i = 0; i<La.length; i++)
	{
		cin >> La.Data[i];
	}
	cout << "������B:" << endl;
	for (int i = 0; i<Lb.length; i++)
	{
		cin >>Lb.Data[i];
	}

	Union(&La, &Lb);
	int i = 0;
	cout << "�����ϵĲ�Ϊ:" << endl;
	while (i<La.length)
	{
		cout << La.Data[i] << " ";
		i++;
	}
	getchar();
	return 0;
}
