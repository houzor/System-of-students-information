#ifndef _LISTSTU_
#define _LISTSTU_
#include "list-college.h"
//声明学生信息相关的结构体
typedef struct
{
	int id;
	char s[2];
} SEX;

typedef struct
{
	int score_1;
	int score_2;
	int score_3;
	int score_4;
	double ave;
} SCORE;

struct student
{
	char num[20];
	char name[20];
	SEX sid;
	COLLEGE cid;
	SCORE mark;
};

//声明节点的结构体
struct Node
{
	struct student data;
	struct Node *next;
};



//声明创建链表函数和创建节点函数
struct Node *createList();
struct Node *createNode(struct student data);

#endif