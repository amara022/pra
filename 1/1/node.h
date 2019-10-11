#pragma once

#ifndef __NODE_H__
//#define __NODE_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//������������ int
typedef int DateType; 
//�ڵ����Ͷ���
typedef struct Node
{
	DateType data;
	struct Node *next;
}Node, *LinkList;

void InitList(LinkList *L);//��ʼ��
void CreateFromTail(LinkList L);//β�巨����������
void PrintLink(LinkList L);//��ӡ����
int ListLength(LinkList L);//������ĳ���
LinkList Merge(LinkList l, LinkList m);//�ϲ���������
void InsertSort(Node *head);//ֱ�Ӳ�����������
#endif   //__NODE_H_