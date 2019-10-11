#pragma once

#ifndef __NODE_H__
//#define __NODE_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//定义数据类型 int
typedef int DateType; 
//节点类型定义
typedef struct Node
{
	DateType data;
	struct Node *next;
}Node, *LinkList;

void InitList(LinkList *L);//初始化
void CreateFromTail(LinkList L);//尾插法建立单链表
void PrintLink(LinkList L);//打印链表
int ListLength(LinkList L);//求链表的长度
LinkList Merge(LinkList l, LinkList m);//合并两个链表
void InsertSort(Node *head);//直接插入排序法排序
#endif   //__NODE_H_