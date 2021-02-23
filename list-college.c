#include <stdio.h>
#include "stdlib.h"
#include "list-college.h"
//创建链表函数
struct Nodecollege *createListcollege()
{
	struct Nodecollege *headNodecollege = (struct Nodecollege *)malloc(sizeof(struct Nodecollege));
	headNodecollege->next = NULL;
	return headNodecollege;
};

//创建结点函数
struct Nodecollege *createNodecollege(COLLEGE college)
{
	struct Nodecollege *newNodecollege = (struct Nodecollege *)malloc(sizeof(struct Nodecollege));
	newNodecollege->college = college;
	newNodecollege->next = NULL;
	return newNodecollege;
}
