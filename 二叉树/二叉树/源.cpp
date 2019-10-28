#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>

typedef struct Node {
	char value;
	struct Node *left;	// 指向我的左孩子
	struct Node *right;	// 指向我的右孩子
}	Node;
typedef struct ReturnType {
	Node * root;	// 创建好树的根节点
	int	used;		// 创建树过程中用掉的值个数
}	ReturnType;

//前序输入
ReturnType createTree(char preorder[], int size) {
	char rootValue = preorder[0];
	if (rootValue == ' ') {
		ReturnType returnValue;
		returnValue.root = NULL;
		returnValue.used = 1;
		return returnValue;
	}

	Node * root = (Node *)malloc(sizeof(Node));
	root->value = rootValue;

	ReturnType left = createTree(preorder + 1, size - 1);
	// left.root;	创建好的左子树的根结点
	// left.used;	创建左子树过程中使用掉的值个数
	ReturnType right = createTree(preorder + 1 + left.used,
		size - 1 - left.used);

	root->left = left.root;
	root->right = right.root;

	ReturnType returnValue;
	returnValue.root = root;
	returnValue.used = 1 + left.used + right.used;

	return returnValue;
}




// 前序遍历
void preOrderTraversal(Node *root) {
	if (root == NULL) {
		return;
	}

	// 根
	printf("%c ", root->value);

	// 左子树的前序遍历
	preOrderTraversal(root->left);

	// 右子树的前序遍历
	preOrderTraversal(root->right);
}

// 中序遍历
void inOrderTraversal(Node *root) {
	if (root == NULL) {
		return;
	}

	// 左子树的中序遍历
	inOrderTraversal(root->left);

	// 根
	printf("%c ", root->value);

	// 右子树的中序遍历
	inOrderTraversal(root->right);
}


// 后序遍历
void postOrderTraversal(Node *root) {
	if (root == NULL) {
		return;
	}

	// 左子树的后序遍历
	postOrderTraversal(root->left);

	// 右子树的后序遍历
	postOrderTraversal(root->right);

	// 根
	printf("%c ", root->value);
}

int main()
{
	char arr[1000] = {};
	gets(arr);
	ReturnType a=createTree(arr, sizeof(arr) / sizeof(arr[0]));
	printf("前序输出:\n");
	preOrderTraversal(a.root);
	printf("\n");
	printf("前序输出:\n");
	inOrderTraversal(a.root);
	printf("\n");
	printf("前序输出:\n");
	postOrderTraversal(a.root);
	return 0;
}