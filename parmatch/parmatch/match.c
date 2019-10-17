#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX 100
#include<assert.h>
typedef int SDataType;


typedef struct Stack
{
	SDataType val;
	SDataType array[MAX];
	int top;
} Stack;


void StackInit(Stack* stack)
{
	stack->top = 0;
}


void StackDestroy(Stack* stack)
{
	stack->top = 0;
}

void StackPush(Stack* stack, SDataType val)
{
	assert(stack);
	assert(stack->top < MAX);
	stack->array[stack->top] = val;
	++stack->top;
}


void StackPop(Stack* stack)
{
	assert(stack);
	assert(stack->top > 0);
	--stack->top;
}


SDataType stackTop(Stack* stack)
{
	assert(stack);
	return stack->array[stack->top - 1];
}


int StackEmpty(Stack* stack)
{
	return stack->top > 0 ? 0 : 1;
}


int StackSize(Stack* stack)
{
	return stack->top;
}

int ParenMatch(char x[], int n)
{
	Stack *s=(Stack*)malloc(sizeof(Stack));
	StackInit(s);
	char ch;
	for (int i = 0; i < n; i++)
	{
		if ((x[i] == '{') || (x[i] == '[') || (x[i] == '('))
		{
			StackPush(s, x[i]);	
		}
		else if ((x[i] == '}') || (x[i] == ']') || (x[i] == ')'))
		{
			if (StackEmpty(s))
				return 0;
			ch = stackTop(s);
			if ((ch == '{'&&x[i] == '}')
				|| (ch == '['&&x[i] == ']')
				|| (ch == '('&&x[i] == ')'))
				StackPop(s);
			else
				return 0;
		}
	}
	if (StackEmpty(s))
		return 1;
	else
		return 0;
}

int main()
{
	char c[100]; int i = 0;
	printf("please input£º\n");
	while (c[i] != '.')
	{
		scanf("%c", &c[++i]);
	}

	if (ParenMatch(c, sizeof(c) / sizeof(c[0])))
		printf("match");
	else
		printf("not match");
	return 0;
}