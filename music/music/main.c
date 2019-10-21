#define _CRT_SECURE_NO_WARNINGS 1
#include "stdio.h"     
#include "stdlib.h"     
#include "string.h"        
typedef struct music
{
	char name[20];
	char singer[20];
	char authors[20];
	char compose[30];
	char album[20];
	char time[15];
	char company[30];
	struct music *next;
} music;
music *head = NULL;

void create()
{
	music *p1, *p2;
	int length = 0;
	p1 = (music *)malloc(sizeof(music));
	strcpy(p1->name, "-1");
	if (head == NULL)
		head = p1;
	printf("���������ֵĸ������ݳ��ߡ����ʡ�����������ר��������ʱ�䡢���湫˾��\n");
	while (1)  //����Ϊ0��ʱ���˳�     
	{
		p2 = (music *)malloc(sizeof(music));
		scanf("%s %s %s %s %s %s %s", p2->name, p2->singer, p2->authors, p2->compose, p2->album, p2->time, p2->company);
		if (strcmp(p2->name, "0") == 0)
		{
			printf("��������ɣ�\n");
			break;
		}
		length++; //����ĳ���     
		p1->next = p2;
		p2->next = NULL;
		p1 = p1->next;
	}
	return;
}

void chang()
{
	music *p = head->next;
	char name[20];
	printf("������Ҫ�޸ĵĸ����ĸ�����");
	getchar();
	scanf("%s", name);
	while (p != NULL)
	{
		if (strcmp(p->name, name) == 0)
		{
			printf("�޸�ǰ������Ϊ%s�ĸ�������Ϣ���£�\n", name);
			printf("���ֵĸ������ݳ��ߡ����ʡ�����������ר��������ʱ�䡢���湫˾��\n");
			printf("%s %s %s %s %s %s %s/n", p->name, p->singer, p->authors, p->compose, p->album, p->time, p->company);
			printf("������������µ�����ר����");
			getchar();
			scanf("%s", p->album);
			printf("������������³��湫˾��");
			getchar();
			scanf("%s", p->company);
			printf("�޸ĺ󣬸���Ϊ%s�ĸ�������Ϣ���£�\n", name);
			printf("���ֵĸ������ݳ��ߡ����ʡ�����������ר��������ʱ�䡢���湫˾��\n");
			printf("%s %s %s %s %s %s %s/n", p->name, p->singer, p->authors, p->compose, p->album, p->time, p->company);
			return;
		}
		p = p->next;
	}
	if (p == NULL)
	{
		printf("�ø��������ڣ�\n");
		return;
	}
}
void display()
{
	music *p = head->next;
	printf("���������еĸ�����Ϣ����:\n");
	printf("���ֵĸ������ݳ��ߡ����ʡ�����������ר��������ʱ�䡢���湫˾:\n");
	while (p != NULL)
	{
		printf("%s %s %s %s %s %s %s\n", p->name, p->singer, p->authors, p -> compose, p->album, p->time, p->company);
		p = p->next;
	}
	return;
}
void search()
{
	int num, x, flag;
	char name[20];
	music *p = head->next;
	printf("��ѡ���ѯ�ķ�ʽ��\n");
	printf("1����������ѯ\t 2�����ݳ��߲�ѯ\n");
	scanf("%d", &x);
	if (x == 1)
	{
		printf("��Ҫ���ҵĸ�������Ϊ��");
		getchar();
		scanf("%s", name);
		while (p != NULL)
		{
			if (strcmp(p->name, name) == 0)
			{
				printf("����Ϊ%s�ĸ�������Ϣ���£�\n", name);
				printf("���ֵĸ������ݳ��ߡ����ʡ�����������ר��������ʱ�䡢���湫˾��\n");
				printf("%s %s %s %s %s %s %s/n", p->name, p->singer, p->authors, p->compose, p->album, p->time, p->company);
				return;
			}
			p = p->next;
		}
		if (p == NULL)
			printf("û�����׸����ļ�¼��\n");
	}
	else if (x == 2)
	{
		flag = 0;
		printf("��Ҫ���ҵ��ݳ���Ϊ��");
		getchar();
		scanf("%s", name);
		p = head->next;
		while (p != NULL)
		{
			if (strcmp(p->singer, name) == 0)
			{
				if (flag == 0)
				{
					printf("�ݳ���Ϊ%s�ĸ�������Ϣ���£�\n", name);
					printf("���ֵĸ������ݳ��ߡ����ʡ�����������ר��������ʱ�䡢���湫˾��\n");
					flag = 1;
				}            printf("%s %s %s %s %s %s %s\n", p->name, p->singer, p->authors, p->compose, p->album, p->time, p->company);
			}
			p = p->next;
		}
		if (p == NULL && flag == 0)
		{
			printf("û�и��ݳ��ߵĸ�����¼��\n");
			return;
		}
	}
	return;
}
void Delete()
{
	char name[20];
	music *p, *q;
	q = head, p = head->next;
	printf("������Ҫɾ���ĸ����ĸ���:\n");
	getchar();
	scanf("%s", name);
	while (p != NULL)
	{
		if (strcmp(p->name, name) == 0)
		{
			q->next = p->next;
			free(p);
			length--;
			printf("ɾ���ɹ���\n");
			return;
		}
		p = p->next;
		q = q->next;
	}
	if (p == NULL)
	{
		printf("�Ҳ���Ҫɾ���ĸ�����\n");
		return;
	}
}
void menu()
{
	printf("________________________________________________________________\n");
	printf("|              ������������ϵͳ                       |\n");
	printf("|               0�� �˳�ϵͳ                          |\n");
	printf("|               1�� ¼�������Ϣ                      |\n");
	printf("|               2�� ��ʾ������Ϣ                      |\n");
	printf("|               3�� ���������е�ĳһ�׸���            |\n");
	printf("|               4�� ɾ��������ָ������                |\n");
	printf("|               5�� ָ����λ���ϲ���һ���½��        |\n");
	printf("|               6�� �޸ĸ�����Ϣ                      |\n");
	printf("________________________________________________________________\n");
	return;
}
int main(void)
{
	int a;
	menu();
	while (1)
	{
		printf("��ѡ����Ӧ�Ĺ��ܣ�");
		scanf("%d", &a);
		switch (a)
		{
		case 0:
			return 0;
		case 1:
			create();
			menu();
			break;
		case 2:
			if (head)
			{
				display();
				menu();
			}
			else
			{
				printf("����Ϊ�գ����Ƚ�������\n");
				menu();
			}
			break;
		case 3:
			if (head)
			{
				search();
				menu();
			}
			else
			{
				printf("����Ϊ�գ����Ƚ�������\n");
				menu();
			}
			break;
		case 4:
			if (head)
			{
				Delete();
				menu();
			}
			else
			{
				printf("����Ϊ�գ����Ƚ�������\n");
				menu();
			}
			break;
		//case 5:
		//	if (head)
		//	{
		//		insert();
		//		menu();
		//	}
		//	else
		//	{
		//		printf("����Ϊ�գ����Ƚ�������\n");
		//		menu();
		//	}
		//	break;
		//case 6:
		//	if (head)
		//	{
		//		ModifymusicInfo();
		//		menu();
		//	}
		//	else
		//	{
		//		printf("����Ϊ�գ����Ƚ�������\n");
		//		menu();
		//	}
		//	break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}