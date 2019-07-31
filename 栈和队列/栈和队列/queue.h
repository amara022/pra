#include<stdio.h>
#include<malloc.h>
#include<assert.h>
// 链式结构：表示队列 
typedef struct QNode
{
	struct QNode* Next;
	int val;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* front;
	QNode* rear;
}Queue;

// 初始化队列 
void QueueInit(Queue* q)
{
	q->front = q->rear = NULL;
}

// 队尾入队列 
void QueuePush(Queue* q, int data)
{
	QNode* c = (QNode*)malloc(sizeof(QNode));
	c->val = data;
	if (q->front == NULL)
	{
		q->front = q->rear = c;
	}
	q->rear->Next = c;
	q->rear = c;
	c->Next = NULL;
}

// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q->front != NULL);
	q->front = q->front->Next;
}

int QueueFront(Queue* q)
{
	assert(q->front != NULL);
	return q->front->val;
}

// 获取队列队尾元素 
int QueueBack(Queue* q)
{
	assert(q->front != NULL);
	return q->rear->val;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	if (q->front == NULL)
		return 0;
	QNode* cur = q->front;
	int count = 0;
	while (cur!=NULL)
	{
		count++;
		cur == cur->Next;
	}
	return count;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	if (q->front == q->rear)
		return 1;
	return 0;
}

// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q->front != q->rear);
	q->front = q->rear = NULL;
}

//8. 总结栈和队列的区别