#ifndef _LISTSTU_H_
#define _LISTSTU_H_
//声明学院的结构体
typedef struct
{
	char id[4];
	char c[32];
} COLLEGE;

//声明节点的结构体
struct Nodecollege
{
	COLLEGE college;
	struct Nodecollege *next;
};


//声明创建链表函数和节点函数
struct Nodecollege *createListcollege();
struct Nodecollege *createNodecollege(COLLEGE college);
#endif