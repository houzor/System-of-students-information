#include <stdio.h>
#include "stdlib.h"
#include "list-stu.h"
//创建链表函数
struct Node *createList()
{
	struct Node *headNode = (struct Node *)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
};

//创建结点函数
struct Node *createNode(struct student data)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
