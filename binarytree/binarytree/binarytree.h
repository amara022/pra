#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
typedef struct Node {
	int val;
	struct Node *left;
	struct Node *right;
} Node;

bool isSameTree(Node* p, Node* q)
{
	if (p == NULL && q == NULL)
		return true;
	if (p == NULL)
		return false;
	if (q == NULL)
		return false;
	if (p->val == q->val)
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	return false;


}
int GetLeafNodeCount(Node* root)
{
	if (root == NULL)
		return 0;
	if (root->right == NULL&&root->left == NULL)
		return 1;
	int left = GetLeafNodeCount(root->left);
	int right = GetLeafNodeCount(root->right);
	return right + left;
}

int GetKLevelNodeCount(Node* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return GetKLevelNodeCount(root->left, k - 1) + GetKLevelNodeCount(root->right, k - 1);
}
typedef struct ReturnType {
	Node * root; // 创建好树的根节点
	int used;  // 创建树过程中用掉的值个数
} ReturnType;
ReturnType createTree(int preorder[], int size) {
	char rootValue = preorder[0];
	if (rootValue == '#') {
		ReturnType returnValue;
		returnValue.root = NULL;
		returnValue.used = 1;
		return returnValue;
	}
	Node * root = (Node *)malloc(sizeof(Node));
	root->val = rootValue;
	ReturnType left = createTree(preorder + 1, size - 1);
	ReturnType right = createTree(preorder + 1 + left.used, size - 1 - left.used);
	root->left = left.root;
	root->right = right.root;

	ReturnType returnValue;
	returnValue.root = root;
	returnValue.used = +left.used + right.used;

	return returnValue;
}

//前序遍历
void PreorderTraval(Node* root)
{
	printf("%c ", root->val);
	PreorderTraval(root->left);
	PreorderTraval(root->right);
}

//中序遍历
void inorderTraval(Node* root)
{
	PreorderTraval(root->left);
	printf("%c ", root->val);
	PreorderTraval(root->right);
}
//后序遍历
void postorderTraval(Node* root)
{
	PreorderTraval(root->left);
	PreorderTraval(root->right);
	printf("%c ", root->val);
}

#include<queue>

void levelorder(Node* root)
{
	if (root == NULL)
		return;
	std::queue<Node*> q;
	q.push(root);

	if (!q.empty())
	{
		Node* front = q.front();
		q.pop();
		printf("%c ", front->val);
		if (front->left != NULL)
			q.push(front->left);
		if (front->right != NULL)
			q.push(front->right);
	}
}


Node* CopyBinTree(Node* root)
{
	if (root == NULL)
		return NULL;
	char returnval = root->val;
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = returnval;
	node->left = CopyBinTree(root->left);
	node->right = CopyBinTree(root->right);
}
int GetNodeCount(Node* root)
{
	if (root == NULL)
		return 0;
	int left = GetNodeCount(root->left);
	int right = GetNodeCount(root->right);
	return left + right + 1;
}

int Max(int a, int b)
{
	return a > b ? a : b;

}
int Height(Node* root)
{
	if (root == NULL)
		return 0;
	int left = Height(root->left);
	int right = Height(root->right);
	return Max(left, right) + 1;
}


void test(){
	int array[] = { 1, 2, 5, 6, 3, 7, 5, 6, 4, 9 };
	createTree(array, sizeof(array) / sizeof(array[0]));
}