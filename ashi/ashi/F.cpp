#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#define CLEAR system("cls")
#define TipForSaveFilePosition printf("\t\t输入文件名及保存位置(eg: D:\\\\example.txt)： ")
#define TipForReadFilePosition printf("\t\t文件名及其路径(eg: D:\\\\example.txt):  ")

#define maxFileNameLen 50 //保存的文件名的最大长度
int FLAG = 0;
int a = 1;
typedef struct TreeNode
{
	int  ChildNum; //记录这个人拥有几个儿女
	char Name[20];//记录这个人的姓名 
	char birthday[20];//生日
	int marriage;//婚否（1表示结婚，0表示没结婚）
	int death;//生死（1表示活着，0表示过世）
	char Kind;//标示节点的种类有女G男B
	char address[100];//住址
	char livemassage[50];//死亡日期（如果其已经死亡）
	struct TreeNode *NextNode[20];  //记录这个人的儿女 
	struct TreeNode *Parent;        //记录这个节点的父节点
}TreeNode, *tree;
void CreatTree(TreeNode *Tree);          //建立家谱
void OutPutAll(TreeNode *Tree);         //输出家谱
void OutBrith(TreeNode *Tree);          //输出但当天生日的人
void Menue(TreeNode *Tree);				//输出主菜单
void UserMenu(TreeNode *Tree);			//输出用户菜单
void SubMenue1(TreeNode * Tree);        //副菜单（修改）
void SubMenue2(TreeNode *Tree);         //副菜单
void Change(TreeNode * Tree);           //修改
void AddNew(TreeNode * Tree);           //添加
void DeletNode(TreeNode* Tree);         //删除
TreeNode * SearchTree(TreeNode *Tree, char name[], int length);      //根据名字查找
TreeNode * SearchTree1(TreeNode *Tree, char birth[], int length);    //根据生日查找
void SortByBirth(TreeNode *Tree);     //按出生日期排序家谱
int Relationship(TreeNode* Tree,char *A,char *B);      //查询两人是否为直系亲属
void OutPutMessage(TreeNode * Tree, char name[], int length);    //根据名字信息打印
void OutPutMessage1(TreeNode * Tree, char birth[], int length);     //根据生日信息打印
void SaveFamily(TreeNode *root);       //存到文件中

int main()//主函数
{
	TreeNode *Tree;
	Tree = (TreeNode *)malloc(sizeof(TreeNode));
	Tree->Parent = NULL;
	strcpy(Tree->Name, "0");
	int i;
	int r;
	char mima[20];
	printf("\n请选择您的登陆方式：1.普通用户   2.管理员（需输入密码）\n");
	scanf("%d", &i);
	if (i == 1)
	{
		UserMenu(Tree);
	}
	if (i == 2)
	{
		while (1)
		{
			printf("\n请输入登陆密码：");
			scanf("%s", mima);
			r = strcmp(mima, "123");
			if (r == 0)
			{
				Menue(Tree);
			}
			else
				printf("\n密码输入错误！请重新输入!\n");
		}
	}
	
	return 0;
}
void Menue(TreeNode *Tree)//输出主菜单
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
		printf("\n\n\t\t**********欢 迎 使 用 家 族 管 理 系 统**********\n\n");
		printf("\n\t\t            A:输入家谱信息建立树                ");
		printf("\n\t\t            B:输出整个家谱信息                ");
		printf("\n\t\t            C:按出生日期打印                  ");
		printf("\n\t\t            D:按出生日期查找某人              ");
		printf("\n\t\t            E:判断两人是否直系亲属              ");
		printf("\n\t\t            F:按姓名查找某人                      ");
		printf("\n\t\t            G:修改某个人的信息                    ");
		printf("\n\t\t            H:添加某个人的信息                    ");
		printf("\n\t\t            H:删除某个人的信息                    ");
		printf("\n\t\t            I:存盘                ");
		printf("\n\t\t            J:退出整个程序                      \n\t");
		c = getchar();
		switch (c)
		{
		case 'A':
			TreeNode * NewNode;
			NewNode = (TreeNode *)malloc(sizeof(TreeNode));
			printf("\n\t请输入姓名:");
			scanf("%s", Tree->Name);
			printf("\n\t请输入性别女G男B:");
			getchar();
			scanf("%c", &(Tree->Kind));
			Tree->Parent = NewNode;
			Tree->Parent = NULL;// 
			CreatTree(Tree);  //   
			printf("\n\t--------------家谱图已经建立成功---------------\n\n");
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			getchar();
			break;
		case 'B':
			if (strcmp(Tree->Name, "0") == 0)
			{
				printf("\n\t家谱图的多叉树尚未建立请先建立树\n");
				getchar();
				break;
			}
			printf("本天生日的有：");
			OutBrith(Tree);
			printf("\n\n\t整个家谱的主要信息如下:");
			OutPutAll(Tree);
			getchar();
			break;
		case 'C':
			if (strcmp(Tree->Name, "0") == 0)
			{
				printf("\n\t家谱图的树未建立，请先建立树\n");
				getchar();
				break;
			}
			SortByBirth(Tree);
			getchar();
			break;
		case 'D':
			if (strcmp(Tree->birthday, "0") == 0)
			{
				printf("\n\t家谱图的多叉树尚未建立请先建立树\n");
				getchar();
				break;
			}
			printf("\n\t请输入你要查找的出生日期:");
			scanf("%s", birth);
			OutPutMessage1(SearchTree1(Tree, birth, 20), birth, 20);
			printf("\n\n\t-----*----*----*----*----*----*----*----*----*----*----\n\t");
			getchar();
			break;
		case 'E':
			if (strcmp(Tree->Name, "0") == 0)
			{
				printf("\n\t家谱图的多叉树尚未建立请先建立树\n");
				getchar();
				break;
			}
			if (strcmp(Tree->NextNode[0]->Name, "0") == 0)
			{
				printf("\n\t不足两人无法判断\n");
				getchar();
				break;
			}
			printf("请输入两姓名");
			char a[20];
			scanf("%s", a);
			char b[20];
			scanf("%s", b);
			if (Relationship(Tree,a, b))
				printf("是直系亲属");
			else
				printf("不是直系亲属");
			break;
		case 'F':
			if (strcmp(Tree->Name, "0") == 0)
			{
				printf("\n\t家谱图的多叉树尚未建立请先建立树\n");
				getchar();
				break;
			}
			printf("\n\t请输入你要查找的人的姓名:");
			scanf("%s", name);
			OutPutMessage(SearchTree(Tree, name, 20), name, 20);
			printf("\n\n\t-----*----*----*----*----*----*----*----*----*----*----\n\t");
			getchar();
			break;
		case 'G':
			if (strcmp(Tree->Name, "0") == 0)
			{
				printf("\n\t家谱图的多叉树尚未建立请先建立树\n");
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
				printf("\n\t家谱图的多叉树尚未建立请先建立树\n");
				getchar();
				break;
			}
			SaveFamily(Tree);
			getchar();
			break;
		case 'K':
			printf("\n\n\t-----------------本次服务到此结束------------------");
			printf("\n\t------------------欢迎下次使用---------------------");
			printf("\n\t----------------------谢谢-------------------------\n\n");
			break;
		case '\n':
			break;
		default:
			printf("\n\n\t--------对不起!你的选择不在服务范围之内!-----------");
			printf("\n\t-----------请您再次选择所需的服务项!---------------");
			printf("\n\t------------------谢谢------------------------\n\t");
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
			printf("不存在此人");
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
		printf("\n\n\t\t**********欢 迎 使 用 家 族 管 理 系 统**********\n\n");
		printf("\n\t\t            A:按出生日期查找某人              ");
		printf("\n\t\t            B:按姓名查找某人                      ");
		printf("\n\t\t            C:退出整个程序                      \n\t");
		c = getchar();
		switch (c)
		{
		case 'A':
			if (strcmp(Tree->birthday, "0") == 0)
			{
				printf("\n\t家谱图的多叉树尚未建立请先建立树\n");
				getchar();
				break;
			}
			printf("\n\t请输入你要查找的出生日期:");
			scanf("%s", birth);
			OutPutMessage1(SearchTree1(Tree, birth, 20), birth, 20);
			printf("\n\n\t-----*----*----*----*----*----*----*----*----*----*----\n\t");
			getchar();
			break;
		case 'B':
			if (strcmp(Tree->Name, "0") == 0)
			{
				printf("\n\t家谱图的多叉树尚未建立请先建立树\n");
				getchar();
				break;
			}
			printf("\n\t请输入你要查找的人的姓名:");
			scanf("%s", name);
			OutPutMessage(SearchTree(Tree, name, 20), name, 20);
			printf("\n\n\t-----*----*----*----*----*----*----*----*----*----*----\n\t");
			getchar();
			break;
		case 'C':
			printf("\n\n\t-----------------本次服务到此结束------------------");
			printf("\n\t------------------欢迎下次使用---------------------");
			printf("\n\t----------------------谢谢-------------------------\n\n");
			break;
		case '\n':
			break;
		default:
			printf("\n\n\t--------对不起!你的选择不在服务范围之内!-----------");
			printf("\n\t-----------请您再次选择所需的服务项!---------------");
			printf("\n\t------------------谢谢------------------------\n\t");
			getchar();
			break;
		}
		if (c=='C')
			break;
		getchar();
	}
}

void CreatTree(TreeNode *Node) //创建树
{
	int i;
	TreeNode *NewNode;
	NewNode = (TreeNode *)malloc(sizeof(TreeNode));
	Node->NextNode[0] = NewNode;
	Node->NextNode[0] = NULL;
	printf("\n\t请输入出生日期：");
	scanf("%s", Node->birthday);
	printf("\n\t请输入家庭住址："); getchar();
	scanf("%s", Node->address);
	printf("\n\t请输入是否建在(1-是或0-否)：");
	scanf("%d", &(Node->death));
	if (Node->death == 0)
	{
		printf("\n\t请输入去世日期：");
		scanf("%s", Node->livemassage);
	}
	else if (Node->death == '1')
		printf("\n\t仍然建在");
	printf("\n\t请输入%s的配偶的姓名(输入0代表没结婚):", Node->Name);
	scanf("%s", NewNode->Name);
	if (strcmp(NewNode->Name, "0") != 0)
	{
		printf("\t请输入配偶的出生日期：");
		scanf("%s", NewNode->birthday);
		printf("\n\t请输入家庭住址："); getchar();
		scanf("%s", NewNode->address);
		printf("\n\t请输入是否建在(1-是或0-否)：");
		scanf("%d", &(NewNode->death));
		if (NewNode->death == 0)
		{
			printf("\n\t请输入去世日期：");
			scanf("%s", NewNode->livemassage);
		}
		else if (NewNode->death == '1')
			printf("\n\t仍然建在");
	}
	printf("\n\t请输入%s的子女的数目(当子女输入0时便停止输入该成员有关信息):", Node->Name);
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
	Node->NextNode[0]->Parent = Node;//孩子的父母
	for (i = 1; i <= Node->ChildNum; i++)
	{
		NewNode = (TreeNode *)malloc(sizeof(TreeNode)); a++;
		printf("\n\t请输入%s的第%d子女的名字:", Node->Name, i);
		scanf("%s", NewNode->Name);
		printf("\n\t请输入%s的第%d子女的性别女G男B:", Node->Name, i);
		getchar();
		scanf("%c", &NewNode->Kind);
		NewNode->ChildNum = -1;
		NewNode->Parent = Node;
		Node->NextNode[i] = NewNode;
		CreatTree(Node->NextNode[i]); //从子女的数目开始
	}
}

void OutPutAll(TreeNode *Tree)
{
	int i, flag = 0;
	printf("\n\t---****---***---***---***---***---***---***---***---***---");
	printf("\n\t姓名:%s        出生日期:%s    家庭住址：%s  性别: %c", Tree->Name, Tree->birthday, Tree->address, Tree->Kind);
	if (Tree->Kind == 'G' || Tree->Kind == 'g')
	{
		flag = 1;
		printf("女");
	}
	else
		printf("男");
	printf("\t是否健在(1-健在，0-去世)：");
	if (Tree->death == 1) printf("1");
	else if (Tree->death == 0) printf("0");
	if (!(Tree->NextNode[0]))
	{
		printf("\n\t至今没有配偶和子女\n");
		return;
	}
	if (flag == 1)
		printf("\n\t丈夫 姓名:%s", Tree->NextNode[0]->Name);
	else
		printf("\n\t妻子 姓名:%s", Tree->NextNode[0]->Name);
	printf("\t是否健在(1-健在，0-去世)：");
	if (Tree->death == 1) printf("1");
	else if (Tree->death == 0) printf("0");
	for (i = 1; i <= Tree->ChildNum; i++)
	{
		printf("\n\t第%d个子女的姓名:%s  出生日期:%s  家庭住址：%s  性别%c", i, Tree->NextNode[i]->Name, Tree->NextNode[i]->birthday, Tree->NextNode[i]->address, Tree->NextNode[i]->Kind);
		if (Tree->NextNode[i]->Kind == 'G' || Tree->NextNode[i]->Kind == 'g')
			printf("女");
		else
			printf("男");
		printf("\t是否健在(1-健在，0-去世)：");
		if (Tree->death == 1) printf("1");
		else if (Tree->death == 0) printf("0");
	}
	printf("\n\t");
	for (i = 1; i <= Tree->ChildNum; i++)
	{
		OutPutAll(Tree->NextNode[i]);
	}
}
//当天生日的人名
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
//按生日排序
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
		printf("\n\t  出生日期:%s  家庭住址：%s  性别%c", Tree->NextNode[i]->Name, Tree->NextNode[i]->birthday, Tree->NextNode[i]->address, Tree->NextNode[i]->Kind);
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
		printf("\n\n\t****该家谱图中没有%s这个人的信息请确认是否输入错误*****\n", name);
		return;
	}
	printf("\n\n\t您所要找的人已经找到信息如下所示:");
	printf("\n\n\t姓名:%s出生日期:%s 家庭住址：%s 性别:%c", name, Tree->birthday, Tree->address, Tree->Kind);
	if (Tree->Kind == 'G' || Tree->Kind == 'g')
	{
		flag = 1;          //标记他(她)的性别 
		printf("女");
	}
	else
		printf("男");
	printf("\t是否健在(1-健在，0-去世)：");
	if (Tree->death == 1) printf("1");
	else if (Tree->death == 0) printf("0");
	NewNode = Tree->Parent;
	if (FLAG == 1)
	{
		if (flag == 1)
		{
			printf("\n\n\t她是嫁入此家族的所以亲生父母信息不在家谱内包括");
			printf("\n\t丈夫 姓名:%s", NewNode->Name);
		}
		else
		{
			printf("\n\n\t他是入赘此家族的所以亲生父母信息不在家谱内包括");
			printf("\n\t妻子姓名:%s", NewNode->Name);
		}
		if ((NewNode->ChildNum)>0)  //判断他(她)是否有孩子
		{
			printf("\n\t的孩子的信息如下:"); //输出他(她)的孩子的信息
			for (i = 1; i <= NewNode->ChildNum; i++)
			{
				printf("\n\t姓名:%s 性别:", NewNode->NextNode[i]->Name);
				if (NewNode->NextNode[i]->Kind == 'G' || NewNode->Kind == 'g')
					printf("女");
				else
					printf("男");
				printf("\t是否健在(1-健在，0-去世)：");
				if (Tree->death == 1) printf("1");
				else if (Tree->death == 0) printf("0");
			}
		}
		return;
	}
	if (NewNode == NULL)//判断它是不是根节点如果是的话就没有父母兄弟信息   
		printf("\n\t是这个家谱图里最年长的人", name);
	else
	{
		if (NewNode->Kind == 'G' || NewNode->Kind == 'g')  //判断父亲节点是父亲还是母亲
		{
			printf("\n\t母亲 姓名:%s", NewNode->Name);//输出他（她）的父母亲的信息   
			printf("\n\t父亲 姓名:%s", NewNode->NextNode[0]->Name);
		}
		else
		{
			printf("\n\t母亲 姓名:%s", NewNode->NextNode[0]->Name);
			printf("\n\t父亲 姓名:%s", NewNode->Name);
		}
		if (Tree->NextNode[0] != NULL) //判断他(她)是否有配偶 
		{
			if (flag == 1)//输出他(她)的配偶的信息
				printf("\n\t丈夫 姓名:%s", Tree->NextNode[0]->Name);
			else
				printf("\n\t妻子 姓名:%s", Tree->NextNode[0]->Name);
			if (Tree->ChildNum>0) //判断他(她)是否有孩子
			{
				printf("\n\t的孩子的信息如下:"); //输出他(她)的孩子的信息
				for (i = 1; i <= Tree->ChildNum; i++)
				{
					printf("\n\t姓名:%s  性别:", Tree->NextNode[i]->Name);
					if (Tree->NextNode[i]->Kind == 'G' || Tree->Kind == 'g')
						printf("女");
					else
						printf("男");
					printf("\t是否健在(1-健在，0-去世)：");
					if (Tree->death == 1) printf("1");
					else if (Tree->death == 0) printf("0");
				}
			}
			else
				printf("\n\t%s至今还没有孩子", name);
		}
		else
			printf("\n\t%s至今还没有配偶和孩子\n", Tree->Name);
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
		printf("\n\n\t****该家谱图中没有出生日期为%s这个人的信息请确认是否输入错误*****\n", birth);
		return;
	}
	printf("\n\n\t您所要找的人已经找到信息如下所示:");
	printf("\n\n\t姓名:%s出生日期:%s 家庭住址：%s 性别:%c", Tree->Name, Tree->birthday, Tree->address, Tree->Kind);
	if (Tree->Kind == 'G' || Tree->Kind == 'g')
	{
		flag = 1;          //标记他(她)的性别 
		printf("女");
	}
	else
		printf("男");
}
void Change(TreeNode * Tree) //修改某个人的信息
{
	char name[20];
	TreeNode * NewNode;
	printf("\n\t请输入你要修改的人的姓名:\n\t");
	scanf("%s", name);
	NewNode = SearchTree(Tree, name, 20);
	if (NewNode == NULL)
	{
		printf("\n\n\t****该家谱图中没有%s这个人的信息请确认是否输入错误*****\n", name);
		return;
	}
	else
	{
		SubMenue1(NewNode);
	}
}
void SubMenue1(TreeNode * Tree) //输出副菜单
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
		printf("\n\n\t          ---*****---请选择你的操作---****---                ");
		printf("\n\t---*---*---*---A:修改个人的信息---*---*---*---*---*---*----    ");
		printf("\n\t---*---*---*---B:修改父母的信息---*---*---*---*---*---*----    ");
		printf("\n\t---*---*---*---C:修改子女的信息---*---*---*---*---*---*----    ");
		printf("\n\t---*---*---*---D:退出-*---*---*---*---*---*---*---*---*----\n\t");
		c = getchar();
		switch (c)
		{
		case 'A':
			printf("\n\n\t请输入修改的姓名:如果不需要修改就输入‘0’然后按Enter键继续\n\t");
			scanf("%s", name);
			if (strcmp(name, "0") != 0)
				strcpy(Tree->Name, name);
			printf("\n\n\t是否要修改性别:如果需要就输入'1'不需要修改就输入'0'然后按Enter键继续\n\t");
			scanf("%d", &flag);
			if (flag == 1)
			{
				if (Tree->Kind == 'G' || Tree->Kind == 'g')
					Tree->Kind = 'B';
				else Tree->Kind = 'G';
			}
			printf("\n\n\t请输入修改的出生日期:如果不需要修改就输入‘0’然后按Enter键继续\n\t");
			scanf("%s", birth);
			if (strcmp(birth, "0") != 0)
				strcpy(Tree->birthday, birth);
			printf("\n\n\t请输入修改的家庭地址:如果不需要修改就输入‘0’然后按Enter键继续\n\t");
			scanf("%s", address1);
			if (strcmp(address1, "0") != 0)
				strcpy(Tree->address, address1);
			printf("\n\n\t个人信息修改成功");
			break;
		case 'B':
			if (Tree->Parent == NULL) //判断是不是头节点       
			{
				printf("\n\t是这个家谱图里最顶端的人没有父母信息!", name);
				break;
			}
			if (FLAG == 1)          //判断是不是入赘或加入此间的 
			{
				if (Tree->Kind == 'G' || Tree->Kind == 'g')
				{
					printf("\n\n\t她是嫁入此间的所以父母信息不在家谱内包括");
				}
				else
				{
					printf("\n\n\t他是入赘此间的所以父母信息不在家谱内包括");
				}
				break;
			}
			if (Tree->Parent->Kind == 'G' || Tree->Parent->Kind == 'g')
			{
				strcpy(Parent[0], "母亲");
				strcpy(Parent[1], "父亲");
			}
			else
			{
				strcpy(Parent[0], "父亲");
				strcpy(Parent[1], "母亲");
			}
			printf("\n\n\t请输入%s要修改的姓名:如果不需要修改就输入‘0’然后按Enter键继续\n\t", Parent[0]);
			scanf("%s", name);
			if (strcmp(name, "0") != 0)
				strcpy(Tree->Parent->Name, name);
			printf("\n\n\t请输入%s要修改的姓名:如果不需要修改就输入‘0’然后按Enter键继续\n\t", Parent[1]);
			scanf("%s", name);
			if (strcmp(name, "0") != 0)
				strcpy(Tree->Parent->NextNode[0]->Name, name);
			printf("\n\n\t-------------父母的信息修改成功----------------");
			break;
		case 'C':
			if (Tree->ChildNum == 0)
			{
				printf("\n\n\t至今还没有子女");
				break;
			}
			if (Tree->Parent != NULL)
			if (strcmp(Tree->Name, Tree->Parent->NextNode[0]->Name) == 0)//如果他是入赘或者是嫁入的就需用配偶节点完成修改   
			{
				Tree = Tree->Parent;
			}
			for (i = 1; i <= Tree->ChildNum; i++)
			{
				printf("\n\n\t请输入%s修改的姓名:如果不需要修改就输入‘0’然后按Enter键继续\n\t", Tree->NextNode[i]->Name);
				scanf("%s", name);
				if (strcmp(name, "0") != 0)
					strcpy(Tree->NextNode[i]->Name, name);
				printf("\n\n\t是否要修改性别:如果需要就输入'1'不需要修改就输入'0'然后按Enter键继续\n\t");
				scanf("%d", &flag);
				if (flag == 1)
				{
					if (Tree->NextNode[i]->Kind == 'G' || Tree->NextNode[i]->Kind == 'g')
						Tree->NextNode[i]->Kind = 'B';
					else Tree->NextNode[i]->Kind = 'G';
				}
			}
			printf("\n\n\t---------------子女的信息修改成功----------------");
			break;
		case 'D':
			printf("\n\n\t----------------本项服务到此结束-----------------");
			break;
		case '\n':
			break;
		default:
			printf("\n\n\t--------对不起!你的选择不在服务范围之内!---------");
			printf("\n\t-----------请您再次选择所需的服务项!-------------");
			printf("\n\t------------------谢谢合作!----------------------\n\t");
			break;
		}
		if (c == 'D' || c == 'd')
			break;
		printf("\n\n\t--------------请按Enter键继续操作--------------");
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
		printf("选择功能\n");
		printf("A:添加子女信息\n");
		printf("B:添加配偶信息\n");
		printf("请选择相应功能：\n");
		c = getchar();
		switch (c)
		{
		case 'A':    //添加子女信息
			printf("请输入被添加人姓名：\n");
			scanf("%s", name);
			Tree = SearchTree(Tree, name, 20);    //查找此人
			if (Tree = NULL)
			{
				printf("家谱中并没有此人，请确认后重新输入\n");
				break;
			}
			if (Tree->Parent == NULL && Tree->NextNode[0] == NULL || Tree->Parent != NULL && Tree->Name != Tree->Parent->NextNode[0]->Name)
			{
				printf("此人目前还无配偶，请先添加配偶\n");
				break;
			}
			if (Tree->Parent == NULL && (Tree->ChildNum > 20 || Tree->ChildNum < 0))
				Tree->ChildNum = 0;
			if (FLAG == 1)
				Tree = Tree->Parent;
			NewNode = (TreeNode *)malloc(sizeof(TreeNode));
			printf("请输入添加人员姓名:\n");
			scanf("%s", NewNode->Name);
			printf("请输入添加人员性别女F男M:\n");
			scanf("%1s", &NewNode->Kind);
			num = Tree->ChildNum;
			NewNode->NextNode[0] = (TreeNode *)malloc(sizeof(TreeNode));
			NewNode->NextNode[0] = NULL;
			NewNode->ChildNum = 0;
			NewNode->Parent = Tree;
			Tree->NextNode[num + 1] = NewNode;
			Tree->ChildNum = Tree->ChildNum + 1;
			printf("子女的信息添加成功\n");
			break;
		case 'B':
			printf("请输入那个人的名字:\n");
			scanf("%s", name);
			Tree = SearchTree(Tree, name, 20);
			if (Tree->Parent != NULL && strcmp(Tree->Name, Tree->Parent->NextNode[0]->Name) == 0 || Tree->NextNode[0] != NULL)
			{
				printf("已经有配偶\n");
				break;
			}
			NewNode = (TreeNode *)malloc(sizeof(TreeNode));
			printf("请输入添加人员姓名:\n");
			scanf("%s", NewNode->Name);
			printf("请输入添加人员性别女F男M:\n");
			scanf("%1s", &NewNode->Kind);
			NewNode->Parent = Tree;
			Tree->NextNode[0] = NewNode;
			break;
		case'C':
			printf("\n\n\t----------本项服务到此结束！----------");
			break;
		case '\n':
			break;
		default:
			printf("\n\n\t----------抱歉！您的选择不在服务范围内！----------");
			printf("\n\n\t----------请再次选择您需要使用的功能！----------");
			break;
		}
		if (c == 'c' || c == 'C')
			break;
		printf("\n\n\t----------请按Enter键继续操作！----------");
		getchar();
		getchar();
	}
}

void SaveFamily(TreeNode *root)//保存家谱至指定文件
{
	char saveFileName[maxFileNameLen];
	FILE* fp;
	TreeNode *queue[50], *head;
	int i, front, rear;//队列的头指针，尾指针
	printf("        *****    保存家谱    *****\n\n");
	if (root == NULL)
	{
		printf("\t\t家谱中无成员，无法保存！\n");
		return;
	}
	TipForSaveFilePosition;//文件及其绝对路径格式
	scanf("%s", saveFileName);
	getchar();
	fp = fopen(saveFileName, "w");//不存在则新建。存在,则从文件起始位置写,原内容将被覆盖。
	if (fp == NULL)
	{
		printf("\t\t新建文件失败！\n");
		return;
	}
	else
		printf("\t\t新建文件成功，文件及其路径为： %s\n", saveFileName);
	/*利用宽度优先搜索遍历家族多叉树*/
	fwrite(root, sizeof(TreeNode), 1, fp); //将根结点存入文件(二进制形式)
	front = rear = 0;//初始化空队
	queue[rear++] = root;//根结点进队
	while (front != rear)//队列不为空
	{
		head = queue[front++];//队头元素出队
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