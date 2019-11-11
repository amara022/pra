#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct character
{
	char str;
	int ?count;
	int index;
} character;
//一棵树需要左孩子，右孩子，非叶子节点上的数字?
typedef struct Tree
{

	int left;
	int right;
	int count;
	int index;
	char str;
	char code[256];
}Tree;
//统计字符串的各字符的频率，以及记录不同字符的个数，排序
character *getCharCount(int *count, char *String);
//输出统计后各个字符，频率?
void showChar(Tree *tree, int count);
//形成一个二叉树?
void proTree(Tree *tree, int count, character *chars);
//形成编码
void decode(Tree *tree, int root, int index, char *code);
//编码
void afterDecode(Tree *tree, char *String, int count, char *afterString);
//编码后输出
void putcode(char *String);
void putcode(char *String)
{
	puts(String);
}
void afterDecode(Tree *tree, char *String, int count, char *afterString)
{
	int i, j;
	for (i = 0; String[i]; i++)
	{
		for (j = 0; j<count; j++)
		{
			if (tree[j].str == String[i])
			{
				strcat(afterString, tree[j].code);
			}
		}
	}
	strcpy(String, afterString);
}
void decode(Tree *tree, int root, int index, char *code)
{
	if (tree[root].left == -1)
	{
		code[index] = 0;
		strcpy(tree[root].code, code);
	}
	else
	{
		code[index] = '1';
		decode(tree, tree[root].left, index + 1, code);
		code[index] = '0';
		decode(tree, tree[root].right, index + 1, code);
	}
}
void proTree(Tree *tree, int count, character *chars)
{
	int i;
	int j;
	for (i = 0; i<count; i++)
	{
		tree[i].index = i;
		tree[i].left = -1;
		tree[i].right = -1;
		tree[i].count = chars[i].count;
		tree[i].str = chars[i].str;
	}

	for (i = count, j = i - 2; i<2 * count - 1; i++)
	{
		tree[i].index = i;
		tree[i].left = tree[i - 1].index;
		tree[i].right = tree[j].index;
		tree[i].count = tree[i - 1].count + tree[j--].count;
		tree[i].str = ' ';
	}

}
void showChar(Tree *tree, int count)
{
	int i;
	printf("下标 ?字符 ? 频率 ? ? 编码 ? ?左孩子 ? ?右孩子\n");
	for (i = 0; i<2 * count - 1; i++)
	{
		printf("%2d ?%5c ?%4d ? %7s ? %5d ? ?%6d\n", tree[i].index, tree[i].str, tree[i].count, tree[i].code, tree[i].left, tree[i].right);
	}
}
character *getCharCount(int *count, char *String)
{
	character *p = NULL;
	character t;
	int i, j = 0;
	int k = 0;
	int chars[256] = { 0 };
	for (i = 0; String[i]; i++)
		chars[String[i]]++;
	for (i = 0; i<256; i++)
	{
		if (chars[i])
		{
			k++;
		}
	}
	*count = k;

	p = (character *)(calloc(sizeof(character), k));

	for (i = 0; i<256; i++)
	{
		if (chars[i])
		{
			p[j].str = i;
			p[j++].count = chars[i];
		}
	}
	for (i = 0; i<k; i++)
	for (j = 0; j<k - i - 1; j++)
	if (p[j].count<p[j + 1].count)
	{
		t = p[j];
		p[j] = p[j + 1];
		p[j + 1] = t;
	}
	for (i = 0; i<k; i++)
		p[i].index = i;
	return p;

}


int main()
{
	char String[256];
	char afterString[256] = { 0 };
	character *chars;
	Tree *tree;
	int count;
	char code[256];
	printf("请输入一串字符串：\n");
	gets(String);
	chars = getCharCount(&count, String);
	tree = (Tree *)(calloc(sizeof(Tree), 2 * count - 1));
	proTree(tree, count, chars);
	decode(tree, 2 * count - 2, 0, code);
	showChar(tree, count);
	afterDecode(tree, String, count, afterString);
	putcode(String);
	free(chars);
	free(tree);


}