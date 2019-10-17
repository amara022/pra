#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<iostream>
using namespace std;

//城市存储
struct City
{
	int rows[100];
	int cols[100];
	int distence[200][200];
	char name[200];          //保存城市
	int num;                //保存城市个数
};

struct Edge
{
	char start[200];       //最小生成树开始后
	int num;          //点数
	int dis[200];         //当前相连最小权重
	int vis[200];              //是否访问
};

//产生小于100的城市坐标
void Getcity(City& c)
{
	cout << "请输入城市数目\n";
	cin >> c.num;
	if (c.num >= 10)
	{
		cout << "请输入城市名\n";
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
					cout << "已经存在此城市，请重新输入" << endl;
					i--;

				}
			}
			//cout <<"城市"<<i<< "的name=" << c.name[i] << "坐标=" << c.rows[i] <<" "<< c.cols[i]<<endl;
			//测试是否建立成功
		}
	}
	else
	{
		cout << "至少需要10个城市,请重新输入\n" << endl;
		Getcity(c);
	}
}

//获取城市间距离
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
	}//获得distence
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
			cout <<  c.name[j]<< "->" << c.name[w] << "距离" << min << endl;
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
	//测试distance
	/*for (int i = 1; i <= c.num; i++)
	{
		for (int j = 1; j <= c.num; j++)
		{
			cout << "第"<<i<<"到"<<j<<"距离"<<c.distence[i][j] << endl;
			
		}
	}*/
	return 0;
}
