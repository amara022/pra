#include<stdio.h>
#include<malloc.h>
#include<assert.h>
// ��ʽ�ṹ����ʾ���� 
typedef struct QNode
{
	struct QNode* Next;
	int val;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* front;
	QNode* rear;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q)
{
	q->front = q->rear = NULL;
}

// ��β����� 
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

// ��ͷ������ 
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

// ��ȡ���ж�βԪ�� 
int QueueBack(Queue* q)
{
	assert(q->front != NULL);
	return q->rear->val;
}

// ��ȡ��������ЧԪ�ظ��� 
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

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	if (q->front == q->rear)
		return 1;
	return 0;
}

// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	assert(q->front != q->rear);
	q->front = q->rear = NULL;
}

//8. �ܽ�ջ�Ͷ��е�����