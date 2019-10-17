#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<iostream>
using namespace std;

//���д洢
struct City
{
	int rows[100];
	int cols[100];
	int distence[200][200];
	char name[200];          //�������
	int num;                //������и���
};

struct Edge
{
	char start[200];       //��С��������ʼ��
	int num;          //����
	int dis[200];         //��ǰ������СȨ��
	int vis[200];              //�Ƿ����
};

//����С��100�ĳ�������
void Getcity(City& c)
{
	cout << "�����������Ŀ\n";
	cin >> c.num;
	if (c.num >= 10)
	{
		cout << "�����������\n";
		for (int i = 1; i <= c.num; i++)
		{
			char name;
			cin >> name;
			c.name[i] = name;	
			int row = rand() % 100;
			int col = rand() % 100;
			c.rows[i] = row;
			c.cols[i] = col;
			for (int j = 1; j < i; j++)
			{
				if (c.name[i] == c.name[j])
				{
					cout << "�Ѿ����ڴ˳��У�����������" << endl;
					i--;

				}
			}
			//cout <<"����"<<i<< "��name=" << c.name[i] << "����=" << c.rows[i] <<" "<< c.cols[i]<<endl;
			//�����Ƿ����ɹ�
		}
	}
	else
	{
		cout << "������Ҫ10������,����������\n" << endl;
		Getcity(c);
	}
}

//��ȡ���м����
int distence(City &c,int a,int b)
{
	for (int i = 1; i <= c.num; i++)
	{
		for (int j = 1; j <= c.num; j++)
		{
			if (i == j)
				c.distence[i][j] = 0;
			else
			{
				if (c.cols[i] == c.cols[j])
				{
					if (c.rows[i] > c.rows[j])
						c.distence[i][j] = c.rows[i] - c.rows[j];
					else
						c.distence[i][j] = c.rows[j] - c.rows[i];
				}
				else if (c.rows[i] == c.rows[j])
				{
					if (c.cols[i] > c.cols[j])
						c.distence[i][j] = c.cols[i] - c.cols[j];
					else
						c.distence[i][j] = c.cols[j] - c.cols[i];
				}
				else if (c.cols[i] > c.cols[j] )
				{
					if (c.rows[i] > c.rows[j])
					{
						int a = pow(c.cols[i] - c.cols[j], 2);
						int b = pow(c.rows[i] - c.rows[j], 2);
						c.distence[i][j] = pow(a + b, 0.5);
					}
					if (c.rows[i] < c.rows[j])
					{
						int a = pow(c.cols[i] - c.cols[j], 2);
						int b = pow(c.rows[j] - c.rows[i], 2);
						c.distence[i][j] = pow(a + b, 0.5);
					}
				}
				else
				{
					if (c.rows[i]>c.rows[j])
					{
						int a = pow(c.cols[j] - c.cols[i], 2);
						int b = pow(c.rows[i] - c.rows[j], 2);
						c.distence[i][j] = pow(a + b, 0.5);
					}
					if (c.rows[i]<c.rows[j])
					{
						int a = pow(c.cols[j] - c.cols[i], 2);
						int b = pow(c.rows[j] - c.rows[i], 2);
						c.distence[i][j] = pow(a + b, 0.5);
					}
				}
			}
		}
	}//���distence
	return c.distence[a][b];
}


void Prim(City& c)
{
	Edge e;
	e.num = 1;
	e.start[1] = c.name[1];
	int j;
	int min = 100;
	for (j = 1; j < c.num;)
	{
		int i;
		int w = 0;
		for (i = 1; i < c.num; i++)
		{
			
			while (i != j&&c.distence[j][i]< min)
			{
				min = distence(c,j,i);
				w = i;
			}
		
		}
			cout <<  c.name[j]<< "->" << c.name[w] << "����" << min << endl;
			min = 100;
		if (i == c.num)
			j++;
		else
			j = w;
	}	
}


int main()
{
	City c;
	Getcity(c);
	Prim(c);
	//����distance
	/*for (int i = 1; i <= c.num; i++)
	{
		for (int j = 1; j <= c.num; j++)
		{
			cout << "��"<<i<<"��"<<j<<"����"<<c.distence[i][j] << endl;
			
		}
	}*/
	return 0;
}
