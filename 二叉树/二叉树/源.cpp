#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>

typedef struct Node {
	char value;
	struct Node *left;	// ָ���ҵ�����
	struct Node *right;	// ָ���ҵ��Һ���
}	Node;
typedef struct ReturnType {
	Node * root;	// ���������ĸ��ڵ�
	int	used;		// �������������õ���ֵ����
}	ReturnType;

//ǰ������
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
	// left.root;	�����õ��������ĸ����
	// left.used;	����������������ʹ�õ���ֵ����
	ReturnType right = createTree(preorder + 1 + left.used,
		size - 1 - left.used);

	root->left = left.root;
	root->right = right.root;

	ReturnType returnValue;
	returnValue.root = root;
	returnValue.used = 1 + left.used + right.used;

	return returnValue;
}




// ǰ�����
void preOrderTraversal(Node *root) {
	if (root == NULL) {
		return;
	}

	// ��
	printf("%c ", root->value);

	// ��������ǰ�����
	preOrderTraversal(root->left);

	// ��������ǰ�����
	preOrderTraversal(root->right);
}

// �������
void inOrderTraversal(Node *root) {
	if (root == NULL) {
		return;
	}

	// ���������������
	inOrderTraversal(root->left);

	// ��
	printf("%c ", root->value);

	// ���������������
	inOrderTraversal(root->right);
}


// �������
void postOrderTraversal(Node *root) {
	if (root == NULL) {
		return;
	}

	// �������ĺ������
	postOrderTraversal(root->left);

	// �������ĺ������
	postOrderTraversal(root->right);

	// ��
	printf("%c ", root->value);
}

int main()
{
	char arr[1000] = {};
	gets(arr);
	ReturnType a=createTree(arr, sizeof(arr) / sizeof(arr[0]));
	printf("ǰ�����:\n");
	preOrderTraversal(a.root);
	printf("\n");
	printf("ǰ�����:\n");
	inOrderTraversal(a.root);
	printf("\n");
	printf("ǰ�����:\n");
	postOrderTraversal(a.root);
	return 0;
}