#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#define CLEAR system("cls")
#define TipForSaveFilePosition printf("\t\t�����ļ���������λ��(eg: D:\\\\example.txt)�� ")
#define TipForReadFilePosition printf("\t\t�ļ�������·��(eg: D:\\\\example.txt):  ")

#define maxFileNameLen 50 //������ļ�������󳤶�
int FLAG = 0;
int a = 1;
typedef struct TreeNode
{
	int  ChildNum; //��¼�����ӵ�м�����Ů
	char Name[20];//��¼����˵����� 
	char birthday[20];//����
	int marriage;//���1��ʾ��飬0��ʾû��飩
	int death;//������1��ʾ���ţ�0��ʾ������
	char Kind;//��ʾ�ڵ��������ŮG��B
	char address[100];//סַ
	char livemassage[50];//�������ڣ�������Ѿ�������
	struct TreeNode *NextNode[20];  //��¼����˵Ķ�Ů 
	struct TreeNode *Parent;        //��¼����ڵ�ĸ��ڵ�
}TreeNode, *tree;
void CreatTree(TreeNode *Tree);          //��������
void OutPutAll(TreeNode *Tree);         //�������
void OutBrith(TreeNode *Tree);          //������������յ���
void Menue(TreeNode *Tree);				//������˵�
void UserMenu(TreeNode *Tree);			//����û��˵�
void SubMenue1(TreeNode * Tree);        //���˵����޸ģ�
void SubMenue2(TreeNode *Tree);         //���˵�
void Change(TreeNode * Tree);           //�޸�
void AddNew(TreeNode * Tree);           //���
void DeletNode(TreeNode* Tree);         //ɾ��
TreeNode * SearchTree(TreeNode *Tree, char name[], int length);      //�������ֲ���
TreeNode * SearchTree1(TreeNode *Tree, char birth[], int length);    //�������ղ���
void SortByBirth(TreeNode *Tree);     //�����������������
int Relationship(TreeNode* Tree,char *A,char *B);      //��ѯ�����Ƿ�Ϊֱϵ����
void OutPutMessage(TreeNode * Tree, char name[], int length);    //����������Ϣ��ӡ
void OutPutMessage1(TreeNode * Tree, char birth[], int length);     //����������Ϣ��ӡ
void SaveFamily(TreeNode *root);       //�浽�ļ���

int main()//������
{
	TreeNode *Tree;
	Tree = (TreeNode *)malloc(sizeof(TreeNode));
	Tree->Parent = NULL;
	strcpy(Tree->Name, "0");
	int i;
	int r;
	char mima[20];
	printf("\n��ѡ�����ĵ�½��ʽ��1.��ͨ�û�   2.����Ա�����������룩\n");
	scanf("%d", &i);
	if (i == 1)
	{
		UserMenu(Tree);
	}
	if (i == 2)
	{
		while (1)
		{
			printf("\n�������½���룺");
			scanf("%s", mima);
			r = strcmp(mima, "123");
			if (r == 0)
			{
				Menue(Tree);
			}
			else
				printf("\n���������������������!\n");
		}
	}
	
	return 0;
}
void Menue(TreeNode *Tree)//������˵�
{
	/*TreeNode **Tree1;
	Tree1=&Tree;*/
	char c;
	char name[20];
	char birth[20];
	while (1)
	{
		system("cls");
		printf("\t");
		printf("\n\n\t\t**********�� ӭ ʹ �� �� �� �� �� ϵ ͳ**********\n\n");
		printf("\n\t\t            A:���������Ϣ������                ");
		printf("\n\t\t            B:�������������Ϣ                ");
		printf("\n\t\t            C:���������ڴ�ӡ                  ");
		printf("\n\t\t            D:���������ڲ���ĳ��              ");
		printf("\n\t\t            E:�ж������Ƿ�ֱϵ����              ");
		printf("\n\t\t            F:����������ĳ��                      ");
		printf("\n\t\t            G:�޸�ĳ���˵���Ϣ                    ");
		printf("\n\t\t            H:���ĳ���˵���Ϣ                    ");
		printf("\n\t\t            H:ɾ��ĳ���˵���Ϣ                    ");
		printf("\n\t\t            I:����                ");
		printf("\n\t\t            J:�˳���������                      \n\t");
		c = getchar();
		switch (c)
		{
		case 'A':
			TreeNode * NewNode;
			NewNode = (TreeNode *)malloc(sizeof(TreeNode));
			printf("\n\t����������:");
			scanf("%s", Tree->Name);
			printf("\n\t�������Ա�ŮG��B:");
			getchar();
			scanf("%c", &(Tree->Kind));
			Tree->Parent = NewNode;
			Tree->Parent = NULL;// 
			CreatTree(Tree);  //   
			printf("\n\t--------------����ͼ�Ѿ������ɹ�---------------\n\n");
			printf("\n\n\t--------------�밴Enter����������--------------");
			getchar();
			break;
		case 'B':
			if (strcmp(Tree->Name, "0") == 0)
			{
				printf("\n\t����ͼ�Ķ������δ�������Ƚ�����\n");
				getchar();
				break;
			}
			printf("�������յ��У�");
			OutBrith(Tree);
			printf("\n\n\t�������׵���Ҫ��Ϣ����:");
			OutPutAll(Tree);
			getchar();
			break;
		case 'C':
			if (strcmp(Tree->Name, "0") == 0)
			{
				printf("\n\t����ͼ����δ���������Ƚ�����\n");
				getchar();
				break;
			}
			SortByBirth(Tree);
			getchar();
			break;
		case 'D':
			if (strcmp(Tree->birthday, "0") == 0)
			{
				printf("\n\t����ͼ�Ķ������δ�������Ƚ�����\n");
				getchar();
				break;
			}
			printf("\n\t��������Ҫ���ҵĳ�������:");
			scanf("%s", birth);
			OutPutMessage1(SearchTree1(Tree, birth, 20), birth, 20);
			printf("\n\n\t-----*----*----*----*----*----*----*----*----*----*----\n\t");
			getchar();
			break;
		case 'E':
			if (strcmp(Tree->Name, "0") == 0)
			{
				printf("\n\t����ͼ�Ķ������δ�������Ƚ�����\n");
				getchar();
				break;
			}
			if (strcmp(Tree->NextNode[0]->Name, "0") == 0)
			{
				printf("\n\t���������޷��ж�\n");
				getchar();
				break;
			}
			printf("������������");
			char a[20];
			scanf("%s", a);
			char b[20];
			scanf("%s", b);
			if (Relationship(Tree,a, b))
				printf("��ֱϵ����");
			else
				printf("����ֱϵ����");
			break;
		case 'F':
			if (strcmp(Tree->Name, "0") == 0)
			{
				printf("\n\t����ͼ�Ķ������δ�������Ƚ�����\n");
				getchar();
				break;
			}
			printf("\n\t��������Ҫ���ҵ��˵�����:");
			scanf("%s", name);
			OutPutMessage(SearchTree(Tree, name, 20), name, 20);
			printf("\n\n\t-----*----*----*----*----*----*----*----*----*----*----\n\t");
			getchar();
			break;
		case 'G':
			if (strcmp(Tree->Name, "0") == 0)
			{
				printf("\n\t����ͼ�Ķ������δ�������Ƚ�����\n");
				getchar();
				break;
			}
			Change(Tree);
			getchar();
			break;
		case 'H':
			SubMenue2(Tree);
			break;
		case 'I':
			DeletNode(Tree);
			break;
		case 'J':
			if (strcmp(Tree->Name, "0") == 0)
			{
				printf("\n\t����ͼ�Ķ������δ�������Ƚ�����\n");
				getchar();
				break;
			}
			SaveFamily(Tree);
			getchar();
			break;
		case 'K':
			printf("\n\n\t-----------------���η��񵽴˽���------------------");
			printf("\n\t------------------��ӭ�´�ʹ��---------------------");
			printf("\n\t----------------------лл-------------------------\n\n");
			break;
		case '\n':
			break;
		default:
			printf("\n\n\t--------�Բ���!���ѡ���ڷ���Χ֮��!-----------");
			printf("\n\t-----------�����ٴ�ѡ������ķ�����!---------------");
			printf("\n\t------------------лл------------------------\n\t");
			getchar();
			break;
		}
		if (c == 'K')
			break;
		getchar();
	}
}
void DeletNode(TreeNode* Tree)
{
	char c[20];
	scanf("%s", &c);
	for (int i = 0; i < Tree->ChildNum; i++)
	{
		if (Tree->Name == c)
		{
			if (Tree->NextNode[0])
			{
				Tree = Tree->NextNode[0];
				Tree->ChildNum--;
			}
			else
				Tree = NULL;
		}
		else if (Tree->NextNode[i]->Name == c)
		{
			for (int j = i; j <= Tree->ChildNum; j++)
			{
				Tree->NextNode[j] = Tree->NextNode[j + 1];
				Tree->ChildNum--;
			}
		}
		else
			printf("�����ڴ���");
	}
}
void UserMenu(TreeNode *Tree)
{
	/*TreeNode **Tree1;
	Tree1=&Tree;*/
	char c;
	char name[20];
	char birth[20];
	while (1)
	{
		system("cls");
		printf("\t");
		printf("\n\n\t\t**********�� ӭ ʹ �� �� �� �� �� ϵ ͳ**********\n\n");
		printf("\n\t\t            A:���������ڲ���ĳ��              ");
		printf("\n\t\t            B:����������ĳ��                      ");
		printf("\n\t\t            C:�˳���������                      \n\t");
		c = getchar();
		switch (c)
		{
		case 'A':
			if (strcmp(Tree->birthday, "0") == 0)
			{
				printf("\n\t����ͼ�Ķ������δ�������Ƚ�����\n");
				getchar();
				break;
			}
			printf("\n\t��������Ҫ���ҵĳ�������:");
			scanf("%s", birth);
			OutPutMessage1(SearchTree1(Tree, birth, 20), birth, 20);
			printf("\n\n\t-----*----*----*----*----*----*----*----*----*----*----\n\t");
			getchar();
			break;
		case 'B':
			if (strcmp(Tree->Name, "0") == 0)
			{
				printf("\n\t����ͼ�Ķ������δ�������Ƚ�����\n");
				getchar();
				break;
			}
			printf("\n\t��������Ҫ���ҵ��˵�����:");
			scanf("%s", name);
			OutPutMessage(SearchTree(Tree, name, 20), name, 20);
			printf("\n\n\t-----*----*----*----*----*----*----*----*----*----*----\n\t");
			getchar();
			break;
		case 'C':
			printf("\n\n\t-----------------���η��񵽴˽���------------------");
			printf("\n\t------------------��ӭ�´�ʹ��---------------------");
			printf("\n\t----------------------лл-------------------------\n\n");
			break;
		case '\n':
			break;
		default:
			printf("\n\n\t--------�Բ���!���ѡ���ڷ���Χ֮��!-----------");
			printf("\n\t-----------�����ٴ�ѡ������ķ�����!---------------");
			printf("\n\t------------------лл------------------------\n\t");
			getchar();
			break;
		}
		if (c=='C')
			break;
		getchar();
	}
}

void CreatTree(TreeNode *Node) //������
{
	int i;
	TreeNode *NewNode;
	NewNode = (TreeNode *)malloc(sizeof(TreeNode));
	Node->NextNode[0] = NewNode;
	Node->NextNode[0] = NULL;
	printf("\n\t������������ڣ�");
	scanf("%s", Node->birthday);
	printf("\n\t�������ͥסַ��"); getchar();
	scanf("%s", Node->address);
	printf("\n\t�������Ƿ���(1-�ǻ�0-��)��");
	scanf("%d", &(Node->death));
	if (Node->death == 0)
	{
		printf("\n\t������ȥ�����ڣ�");
		scanf("%s", Node->livemassage);
	}
	else if (Node->death == '1')
		printf("\n\t��Ȼ����");
	printf("\n\t������%s����ż������(����0����û���):", Node->Name);
	scanf("%s", NewNode->Name);
	if (strcmp(NewNode->Name, "0") != 0)
	{
		printf("\t��������ż�ĳ������ڣ�");
		scanf("%s", NewNode->birthday);
		printf("\n\t�������ͥסַ��"); getchar();
		scanf("%s", NewNode->address);
		printf("\n\t�������Ƿ���(1-�ǻ�0-��)��");
		scanf("%d", &(NewNode->death));
		if (NewNode->death == 0)
		{
			printf("\n\t������ȥ�����ڣ�");
			scanf("%s", NewNode->livemassage);
		}
		else if (NewNode->death == '1')
			printf("\n\t��Ȼ����");
	}
	printf("\n\t������%s����Ů����Ŀ(����Ů����0ʱ��ֹͣ����ó�Ա�й���Ϣ):", Node->Name);
	scanf("%d", &(Node->ChildNum));
	if ((Node->ChildNum) == 0 && strcmp(NewNode->Name, "0") == 0)
		return;
	if (Node->Kind == 'G' || Node->Kind == 'g')
		NewNode->Kind = 'B';
	else
		NewNode->Kind = 'G';
	NewNode->ChildNum = 0;
	NewNode->NextNode[0] = NULL;
	Node->NextNode[0] = NewNode;
	Node->NextNode[0]->Parent = Node;//���ӵĸ�ĸ
	for (i = 1; i <= Node->ChildNum; i++)
	{
		NewNode = (TreeNode *)malloc(sizeof(TreeNode)); a++;
		printf("\n\t������%s�ĵ�%d��Ů������:", Node->Name, i);
		scanf("%s", NewNode->Name);
		printf("\n\t������%s�ĵ�%d��Ů���Ա�ŮG��B:", Node->Name, i);
		getchar();
		scanf("%c", &NewNode->Kind);
		NewNode->ChildNum = -1;
		NewNode->Parent = Node;
		Node->NextNode[i] = NewNode;
		CreatTree(Node->NextNode[i]); //����Ů����Ŀ��ʼ
	}
}

void OutPutAll(TreeNode *Tree)
{
	int i, flag = 0;
	printf("\n\t---****---***---***---***---***---***---***---***---***---");
	printf("\n\t����:%s        ��������:%s    ��ͥסַ��%s  �Ա�: %c", Tree->Name, Tree->birthday, Tree->address, Tree->Kind);
	if (Tree->Kind == 'G' || Tree->Kind == 'g')
	{
		flag = 1;
		printf("Ů");
	}
	else
		printf("��");
	printf("\t�Ƿ���(1-���ڣ�0-ȥ��)��");
	if (Tree->death == 1) printf("1");
	else if (Tree->death == 0) printf("0");
	if (!(Tree->NextNode[0]))
	{
		printf("\n\t����û����ż����Ů\n");
		return;
	}
	if (flag == 1)
		printf("\n\t�ɷ� ����:%s", Tree->NextNode[0]->Name);
	else
		printf("\n\t���� ����:%s", Tree->NextNode[0]->Name);
	printf("\t�Ƿ���(1-���ڣ�0-ȥ��)��");
	if (Tree->death == 1) printf("1");
	else if (Tree->death == 0) printf("0");
	for (i = 1; i <= Tree->ChildNum; i++)
	{
		printf("\n\t��%d����Ů������:%s  ��������:%s  ��ͥסַ��%s  �Ա�%c", i, Tree->NextNode[i]->Name, Tree->NextNode[i]->birthday, Tree->NextNode[i]->address, Tree->NextNode[i]->Kind);
		if (Tree->NextNode[i]->Kind == 'G' || Tree->NextNode[i]->Kind == 'g')
			printf("Ů");
		else
			printf("��");
		printf("\t�Ƿ���(1-���ڣ�0-ȥ��)��");
		if (Tree->death == 1) printf("1");
		else if (Tree->death == 0) printf("0");
	}
	printf("\n\t");
	for (i = 1; i <= Tree->ChildNum; i++)
	{
		OutPutAll(Tree->NextNode[i]);
	}
}
//�������յ�����
void OutBrith(TreeNode *Tree)
{
	time_t timep;
	struct tm *p;
	char t[20]="" ;
	time(&timep);
	p = gmtime(&timep);
	t[0]= p->tm_mon; 
	t[4] = p->tm_mday;
	TreeNode* cur = (TreeNode*)malloc(sizeof(TreeNode));
	cur = Tree;
	for (int i = 0; i < Tree->ChildNum; i++)
	{
		if (cur->birthday+5 == t+0)
			printf("%s", cur->Name);
		cur = cur->NextNode[i];
	}
}
//����������
void SortByBirth(TreeNode* Tree)
{
	TreeNode *NextNode;
	int i, j;
	for (i = 0; i<(Tree->ChildNum) - 1; i++)
	{
		for (j = i + 1; j <= (Tree->ChildNum); j++)
		{
			if (strcmp(Tree->NextNode[i]->birthday, Tree->NextNode[i]->birthday)>0)
			{
				NextNode = Tree->NextNode[i];
				Tree->NextNode[i] = Tree->NextNode[j];
				Tree->NextNode[j] = NextNode;
			}
		}
	}
	for (i = 0; i < Tree->ChildNum; i++)
	{
		printf("\n\t  ��������:%s  ��ͥסַ��%s  �Ա�%c", Tree->NextNode[i]->Name, Tree->NextNode[i]->birthday, Tree->NextNode[i]->address, Tree->NextNode[i]->Kind);
	}
}
int Relationship(TreeNode* tree,char *A, char *B)
{
	TreeNode* cur = tree;
	TreeNode* NA = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* NB = (TreeNode*)malloc(sizeof(TreeNode));
	for (int i = 0; i < tree->ChildNum; i++)
	{
		if (cur->Name != A&&cur->Name != B)
		{
			cur = cur->NextNode[i];
		}
		else if (cur->Name == A)
			NA = cur;
		else
			NB = cur;
	}
	if (NA->Parent == NB->Parent)
		return 1;
	else
		return 0;
}
TreeNode * SearchTree(TreeNode *Tree, char name[], int length)
{
	int i;
	TreeNode *NewNode;
	if (strcmp(Tree->Name, name) == 0)
	{
		if (length == 0)
			FLAG = 1;
		else
			FLAG = 0;
		return Tree;
	}
	if (Tree->NextNode[0] == NULL)
		return NULL;
	for (i = 0; i <= Tree->ChildNum; i++)
	{
		if (i == 0)
			NewNode = SearchTree(Tree->NextNode[i], name, 0);
		else
			NewNode = SearchTree(Tree->NextNode[i], name, 20);
		if (NewNode != NULL)
			return NewNode;
	}
	return NULL;
}
void OutPutMessage(TreeNode * Tree, char name[], int length)
{
	int flag = 0, i;
	TreeNode *NewNode;
	printf("\n\n\t-----*----*----*----*----*----*----*----*----*----*----");
	if (Tree == NULL)
	{
		printf("\n\n\t****�ü���ͼ��û��%s����˵���Ϣ��ȷ���Ƿ��������*****\n", name);
		return;
	}
	printf("\n\n\t����Ҫ�ҵ����Ѿ��ҵ���Ϣ������ʾ:");
	printf("\n\n\t����:%s��������:%s ��ͥסַ��%s �Ա�:%c", name, Tree->birthday, Tree->address, Tree->Kind);
	if (Tree->Kind == 'G' || Tree->Kind == 'g')
	{
		flag = 1;          //�����(��)���Ա� 
		printf("Ů");
	}
	else
		printf("��");
	printf("\t�Ƿ���(1-���ڣ�0-ȥ��)��");
	if (Tree->death == 1) printf("1");
	else if (Tree->death == 0) printf("0");
	NewNode = Tree->Parent;
	if (FLAG == 1)
	{
		if (flag == 1)
		{
			printf("\n\n\t���Ǽ���˼��������������ĸ��Ϣ���ڼ����ڰ���");
			printf("\n\t�ɷ� ����:%s", NewNode->Name);
		}
		else
		{
			printf("\n\n\t������׸�˼��������������ĸ��Ϣ���ڼ����ڰ���");
			printf("\n\t��������:%s", NewNode->Name);
		}
		if ((NewNode->ChildNum)>0)  //�ж���(��)�Ƿ��к���
		{
			printf("\n\t�ĺ��ӵ���Ϣ����:"); //�����(��)�ĺ��ӵ���Ϣ
			for (i = 1; i <= NewNode->ChildNum; i++)
			{
				printf("\n\t����:%s �Ա�:", NewNode->NextNode[i]->Name);
				if (NewNode->NextNode[i]->Kind == 'G' || NewNode->Kind == 'g')
					printf("Ů");
				else
					printf("��");
				printf("\t�Ƿ���(1-���ڣ�0-ȥ��)��");
				if (Tree->death == 1) printf("1");
				else if (Tree->death == 0) printf("0");
			}
		}
		return;
	}
	if (NewNode == NULL)//�ж����ǲ��Ǹ��ڵ�����ǵĻ���û�и�ĸ�ֵ���Ϣ   
		printf("\n\t���������ͼ�����곤����", name);
	else
	{
		if (NewNode->Kind == 'G' || NewNode->Kind == 'g')  //�жϸ��׽ڵ��Ǹ��׻���ĸ��
		{
			printf("\n\tĸ�� ����:%s", NewNode->Name);//������������ĸ�ĸ�׵���Ϣ   
			printf("\n\t���� ����:%s", NewNode->NextNode[0]->Name);
		}
		else
		{
			printf("\n\tĸ�� ����:%s", NewNode->NextNode[0]->Name);
			printf("\n\t���� ����:%s", NewNode->Name);
		}
		if (Tree->NextNode[0] != NULL) //�ж���(��)�Ƿ�����ż 
		{
			if (flag == 1)//�����(��)����ż����Ϣ
				printf("\n\t�ɷ� ����:%s", Tree->NextNode[0]->Name);
			else
				printf("\n\t���� ����:%s", Tree->NextNode[0]->Name);
			if (Tree->ChildNum>0) //�ж���(��)�Ƿ��к���
			{
				printf("\n\t�ĺ��ӵ���Ϣ����:"); //�����(��)�ĺ��ӵ���Ϣ
				for (i = 1; i <= Tree->ChildNum; i++)
				{
					printf("\n\t����:%s  �Ա�:", Tree->NextNode[i]->Name);
					if (Tree->NextNode[i]->Kind == 'G' || Tree->Kind == 'g')
						printf("Ů");
					else
						printf("��");
					printf("\t�Ƿ���(1-���ڣ�0-ȥ��)��");
					if (Tree->death == 1) printf("1");
					else if (Tree->death == 0) printf("0");
				}
			}
			else
				printf("\n\t%s����û�к���", name);
		}
		else
			printf("\n\t%s����û����ż�ͺ���\n", Tree->Name);
	}
}
TreeNode * SearchTree1(TreeNode *Tree, char birth[], int length)
{
	int i;
	TreeNode *NewNode;
	if (strcmp(Tree->birthday, birth) == 0)
	{
		if (length == 0)
			FLAG = 1;
		else
			FLAG = 0;
		return Tree;
	}
	if (Tree->NextNode[0] == NULL)
		return NULL;
	for (i = 0; i <= Tree->ChildNum; i++)
	{
		if (i == 0)
			NewNode = SearchTree1(Tree->NextNode[i], birth, 0);
		else
			NewNode = SearchTree1(Tree->NextNode[i], birth, 20);
		if (NewNode != NULL)
			return NewNode;
	}
	return NULL;
}
void OutPutMessage1(TreeNode * Tree, char birth[], int length)
{
	int flag = 0;
	TreeNode *NewNode;
	printf("\n\n\t-----*----*----*----*----*----*----*----*----*----*----");
	if (Tree == NULL)
	{
		printf("\n\n\t****�ü���ͼ��û�г�������Ϊ%s����˵���Ϣ��ȷ���Ƿ��������*****\n", birth);
		return;
	}
	printf("\n\n\t����Ҫ�ҵ����Ѿ��ҵ���Ϣ������ʾ:");
	printf("\n\n\t����:%s��������:%s ��ͥסַ��%s �Ա�:%c", Tree->Name, Tree->birthday, Tree->address, Tree->Kind);
	if (Tree->Kind == 'G' || Tree->Kind == 'g')
	{
		flag = 1;          //�����(��)���Ա� 
		printf("Ů");
	}
	else
		printf("��");
}
void Change(TreeNode * Tree) //�޸�ĳ���˵���Ϣ
{
	char name[20];
	TreeNode * NewNode;
	printf("\n\t��������Ҫ�޸ĵ��˵�����:\n\t");
	scanf("%s", name);
	NewNode = SearchTree(Tree, name, 20);
	if (NewNode == NULL)
	{
		printf("\n\n\t****�ü���ͼ��û��%s����˵���Ϣ��ȷ���Ƿ��������*****\n", name);
		return;
	}
	else
	{
		SubMenue1(NewNode);
	}
}
void SubMenue1(TreeNode * Tree) //������˵�
{
	char c;
	int  flag, i;
	char name[20];
	char birth[20];
	char address1[50];
	char Parent[2][20];
	TreeNode * NewNode;
	getchar();
	while (1)
	{
		system("cls");
		printf("\t");
		printf("\n\n\t          ---*****---��ѡ����Ĳ���---****---                ");
		printf("\n\t---*---*---*---A:�޸ĸ��˵���Ϣ---*---*---*---*---*---*----    ");
		printf("\n\t---*---*---*---B:�޸ĸ�ĸ����Ϣ---*---*---*---*---*---*----    ");
		printf("\n\t---*---*---*---C:�޸���Ů����Ϣ---*---*---*---*---*---*----    ");
		printf("\n\t---*---*---*---D:�˳�-*---*---*---*---*---*---*---*---*----\n\t");
		c = getchar();
		switch (c)
		{
		case 'A':
			printf("\n\n\t�������޸ĵ�����:�������Ҫ�޸ľ����롮0��Ȼ��Enter������\n\t");
			scanf("%s", name);
			if (strcmp(name, "0") != 0)
				strcpy(Tree->Name, name);
			printf("\n\n\t�Ƿ�Ҫ�޸��Ա�:�����Ҫ������'1'����Ҫ�޸ľ�����'0'Ȼ��Enter������\n\t");
			scanf("%d", &flag);
			if (flag == 1)
			{
				if (Tree->Kind == 'G' || Tree->Kind == 'g')
					Tree->Kind = 'B';
				else Tree->Kind = 'G';
			}
			printf("\n\n\t�������޸ĵĳ�������:�������Ҫ�޸ľ����롮0��Ȼ��Enter������\n\t");
			scanf("%s", birth);
			if (strcmp(birth, "0") != 0)
				strcpy(Tree->birthday, birth);
			printf("\n\n\t�������޸ĵļ�ͥ��ַ:�������Ҫ�޸ľ����롮0��Ȼ��Enter������\n\t");
			scanf("%s", address1);
			if (strcmp(address1, "0") != 0)
				strcpy(Tree->address, address1);
			printf("\n\n\t������Ϣ�޸ĳɹ�");
			break;
		case 'B':
			if (Tree->Parent == NULL) //�ж��ǲ���ͷ�ڵ�       
			{
				printf("\n\t���������ͼ����˵���û�и�ĸ��Ϣ!", name);
				break;
			}
			if (FLAG == 1)          //�ж��ǲ�����׸�����˼�� 
			{
				if (Tree->Kind == 'G' || Tree->Kind == 'g')
				{
					printf("\n\n\t���Ǽ���˼�����Ը�ĸ��Ϣ���ڼ����ڰ���");
				}
				else
				{
					printf("\n\n\t������׸�˼�����Ը�ĸ��Ϣ���ڼ����ڰ���");
				}
				break;
			}
			if (Tree->Parent->Kind == 'G' || Tree->Parent->Kind == 'g')
			{
				strcpy(Parent[0], "ĸ��");
				strcpy(Parent[1], "����");
			}
			else
			{
				strcpy(Parent[0], "����");
				strcpy(Parent[1], "ĸ��");
			}
			printf("\n\n\t������%sҪ�޸ĵ�����:�������Ҫ�޸ľ����롮0��Ȼ��Enter������\n\t", Parent[0]);
			scanf("%s", name);
			if (strcmp(name, "0") != 0)
				strcpy(Tree->Parent->Name, name);
			printf("\n\n\t������%sҪ�޸ĵ�����:�������Ҫ�޸ľ����롮0��Ȼ��Enter������\n\t", Parent[1]);
			scanf("%s", name);
			if (strcmp(name, "0") != 0)
				strcpy(Tree->Parent->NextNode[0]->Name, name);
			printf("\n\n\t-------------��ĸ����Ϣ�޸ĳɹ�----------------");
			break;
		case 'C':
			if (Tree->ChildNum == 0)
			{
				printf("\n\n\t����û����Ů");
				break;
			}
			if (Tree->Parent != NULL)
			if (strcmp(Tree->Name, Tree->Parent->NextNode[0]->Name) == 0)//���������׸�����Ǽ���ľ�������ż�ڵ�����޸�   
			{
				Tree = Tree->Parent;
			}
			for (i = 1; i <= Tree->ChildNum; i++)
			{
				printf("\n\n\t������%s�޸ĵ�����:�������Ҫ�޸ľ����롮0��Ȼ��Enter������\n\t", Tree->NextNode[i]->Name);
				scanf("%s", name);
				if (strcmp(name, "0") != 0)
					strcpy(Tree->NextNode[i]->Name, name);
				printf("\n\n\t�Ƿ�Ҫ�޸��Ա�:�����Ҫ������'1'����Ҫ�޸ľ�����'0'Ȼ��Enter������\n\t");
				scanf("%d", &flag);
				if (flag == 1)
				{
					if (Tree->NextNode[i]->Kind == 'G' || Tree->NextNode[i]->Kind == 'g')
						Tree->NextNode[i]->Kind = 'B';
					else Tree->NextNode[i]->Kind = 'G';
				}
			}
			printf("\n\n\t---------------��Ů����Ϣ�޸ĳɹ�----------------");
			break;
		case 'D':
			printf("\n\n\t----------------������񵽴˽���-----------------");
			break;
		case '\n':
			break;
		default:
			printf("\n\n\t--------�Բ���!���ѡ���ڷ���Χ֮��!---------");
			printf("\n\t-----------�����ٴ�ѡ������ķ�����!-------------");
			printf("\n\t------------------лл����!----------------------\n\t");
			break;
		}
		if (c == 'D' || c == 'd')
			break;
		printf("\n\n\t--------------�밴Enter����������--------------");
		getchar();
		getchar();
	}
}
void SubMenue2(TreeNode *Tree)
{
	char c;
	int num;
	char name[20];
	TreeNode * NewNode;
	getchar();
	while (1)
	{
		system("cls");
		printf("ѡ����\n");
		printf("A:�����Ů��Ϣ\n");
		printf("B:�����ż��Ϣ\n");
		printf("��ѡ����Ӧ���ܣ�\n");
		c = getchar();
		switch (c)
		{
		case 'A':    //�����Ů��Ϣ
			printf("�����뱻�����������\n");
			scanf("%s", name);
			Tree = SearchTree(Tree, name, 20);    //���Ҵ���
			if (Tree = NULL)
			{
				printf("�����в�û�д��ˣ���ȷ�Ϻ���������\n");
				break;
			}
			if (Tree->Parent == NULL && Tree->NextNode[0] == NULL || Tree->Parent != NULL && Tree->Name != Tree->Parent->NextNode[0]->Name)
			{
				printf("����Ŀǰ������ż�����������ż\n");
				break;
			}
			if (Tree->Parent == NULL && (Tree->ChildNum > 20 || Tree->ChildNum < 0))
				Tree->ChildNum = 0;
			if (FLAG == 1)
				Tree = Tree->Parent;
			NewNode = (TreeNode *)malloc(sizeof(TreeNode));
			printf("�����������Ա����:\n");
			scanf("%s", NewNode->Name);
			printf("�����������Ա�Ա�ŮF��M:\n");
			scanf("%1s", &NewNode->Kind);
			num = Tree->ChildNum;
			NewNode->NextNode[0] = (TreeNode *)malloc(sizeof(TreeNode));
			NewNode->NextNode[0] = NULL;
			NewNode->ChildNum = 0;
			NewNode->Parent = Tree;
			Tree->NextNode[num + 1] = NewNode;
			Tree->ChildNum = Tree->ChildNum + 1;
			printf("��Ů����Ϣ��ӳɹ�\n");
			break;
		case 'B':
			printf("�������Ǹ��˵�����:\n");
			scanf("%s", name);
			Tree = SearchTree(Tree, name, 20);
			if (Tree->Parent != NULL && strcmp(Tree->Name, Tree->Parent->NextNode[0]->Name) == 0 || Tree->NextNode[0] != NULL)
			{
				printf("�Ѿ�����ż\n");
				break;
			}
			NewNode = (TreeNode *)malloc(sizeof(TreeNode));
			printf("�����������Ա����:\n");
			scanf("%s", NewNode->Name);
			printf("�����������Ա�Ա�ŮF��M:\n");
			scanf("%1s", &NewNode->Kind);
			NewNode->Parent = Tree;
			Tree->NextNode[0] = NewNode;
			break;
		case'C':
			printf("\n\n\t----------������񵽴˽�����----------");
			break;
		case '\n':
			break;
		default:
			printf("\n\n\t----------��Ǹ������ѡ���ڷ���Χ�ڣ�----------");
			printf("\n\n\t----------���ٴ�ѡ������Ҫʹ�õĹ��ܣ�----------");
			break;
		}
		if (c == 'c' || c == 'C')
			break;
		printf("\n\n\t----------�밴Enter������������----------");
		getchar();
		getchar();
	}
}

void SaveFamily(TreeNode *root)//���������ָ���ļ�
{
	char saveFileName[maxFileNameLen];
	FILE* fp;
	TreeNode *queue[50], *head;
	int i, front, rear;//���е�ͷָ�룬βָ��
	printf("        *****    �������    *****\n\n");
	if (root == NULL)
	{
		printf("\t\t�������޳�Ա���޷����棡\n");
		return;
	}
	TipForSaveFilePosition;//�ļ��������·����ʽ
	scanf("%s", saveFileName);
	getchar();
	fp = fopen(saveFileName, "w");//���������½�������,����ļ���ʼλ��д,ԭ���ݽ������ǡ�
	if (fp == NULL)
	{
		printf("\t\t�½��ļ�ʧ�ܣ�\n");
		return;
	}
	else
		printf("\t\t�½��ļ��ɹ����ļ�����·��Ϊ�� %s\n", saveFileName);
	/*���ÿ����������������������*/
	fwrite(root, sizeof(TreeNode), 1, fp); //�����������ļ�(��������ʽ)
	front = rear = 0;//��ʼ���ն�
	queue[rear++] = root;//��������
	while (front != rear)//���в�Ϊ��
	{
		head = queue[front++];//��ͷԪ�س���
		if (head->NextNode[0] != NULL)
		{
			fwrite(head->NextNode[0], sizeof(TreeNode), 1, fp);
		}
		for (i = 1; i <= head->ChildNum; i++)
		{
			fwrite(head->NextNode[i], sizeof(TreeNode), 1, fp);
			queue[rear++] = head->NextNode[i];
		}
	}
	fclose(fp);
	fp = NULL;
}