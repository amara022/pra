#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
struct BTreeNode
{
	ElemType data;
	struct BTreeNode* left;
	struct BTreeNode* right;
};

//哈夫曼树
void PrintBTree_int(struct BTreeNode* BT)
{
	if (BT != NULL)
	{
		printf("%d", BT->data); //输出根结点的值
		if (BT->left != NULL || BT->right != NULL)
		{
			printf("(");
			PrintBTree_int(BT->left); //输出左子树
			if (BT->right != NULL)
				printf(",");
			PrintBTree_int(BT->right); //输出右子树
			printf(")");
		}
	}
}

//2、根据数组 a 中 n 个权值建立一棵哈夫曼树，返回树根指针
struct BTreeNode* CreateHuffman(ElemType a[], int n)
{
	int i, j;
	struct BTreeNode **b;
	struct BTreeNode *q = (BTreeNode*)malloc(sizeof(BTreeNode));
	b = (BTreeNode**)malloc(n*sizeof(struct BTreeNode));
	for (i = 0; i < n; i++) //初始化b指针数组，使每个指针元素指向a数组中对应的元素结点
	{
		b[i] = (BTreeNode*)malloc(sizeof(struct BTreeNode));
		b[i]->data = a[i];
		b[i]->left = b[i]->right = NULL;
	}
	for (i = 1; i < n; i++)//进行 n-1 次循环建立哈夫曼树
	{
		//k1表示森林中具有最小权值的树根结点的下标，k2为次最小的下标
		int k1 = -1, k2;
		for (j = 0; j < n; j++)//让k1初始指向森林中第一棵树，k2指向第二棵
		{
			if (b[j] != NULL && k1 == -1)
			{
				k1 = j;
				continue;
			}
			if (b[j] != NULL)
			{
				k2 = j;
				break;
			}
		}
		for (j = k2; j < n; j++)//从当前森林中求出最小权值树和次最小
		{
			if (b[j] != NULL)
			{
				if (b[j]->data < b[k1]->data)
				{
					k2 = k1;
					k1 = j;
				}
				else if (b[j]->data < b[k2]->data)
					k2 = j;
			}
		}
		q = (BTreeNode*)malloc(sizeof(struct BTreeNode));
		q->data = b[k1]->data + b[k2]->data;
		q->left = b[k1];
		q->right = b[k2];

		b[k1] = q;
		b[k2] = NULL;
	}
	free(b); 
	return q; 
}

//带权路径长度
ElemType WeightPathLength(struct BTreeNode* FBT, int len)//len初始为0
{
	if (FBT == NULL) 
		return 0;
	else
	{
		if (FBT->left == NULL && FBT->right == NULL)
			return FBT->data * len;
		else 
			return WeightPathLength(FBT->left, len + 1) + WeightPathLength(FBT->right, len + 1);
	}
}

//编码
void HuffManCoding(struct BTreeNode* FBT, int len)//len初始值为0
{
	static int a[10];
	if (FBT != NULL)
	{
		if (FBT->left == NULL && FBT->right == NULL)
		{
			int i;
			printf("结点权值为%d的编码：", FBT->data);
			for (i = 0; i < len; i++)
				printf("%d", a[i]);
			printf("\n");
		}
		else
		{   
			a[len] = 0;
			HuffManCoding(FBT->left, len + 1);
			a[len] = 1;
			HuffManCoding(FBT->right, len + 1);
		}
	}
}

//主函数
int main()
{
	int n, i;
	ElemType* a;
	struct BTreeNode* fbt;
	printf("从键盘输入待构造的哈夫曼树中带权叶子结点数n：");
	while (1)
	{
		scanf("%d", &n);
		if (n > 1)
			break;
		else
			printf("重输n值：");
	}
	a = (ElemType*)malloc(n*sizeof(ElemType));
	printf("从键盘输入%d个整数作为权值：", n);
	for (i = 0; i < n; i++)
		scanf(" %d", &a[i]);
	fbt = CreateHuffman(a, n);
	printf("哈夫曼树：");
	PrintBTree_int(fbt);
	printf("\n");
	printf("带权路径长度：");
	printf("%d\n", WeightPathLength(fbt, 0));
	printf("树中每个叶子结点的哈夫曼编码：\n");
	HuffManCoding(fbt, 0);
	return 0;
}