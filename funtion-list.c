#include "all.h"
//����������
struct Node* createList()
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
};

//������㺯��
struct Node* createNode(struct student data)
{
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//����������
struct Nodecollege* createListcollege()
{
	struct Nodecollege* headNodecollege = (struct Nodecollege*)malloc(sizeof(struct Nodecollege));
	headNodecollege->next = NULL;
	return headNodecollege;
};

//������㺯��
struct Nodecollege* createNodecollege(COLLEGE college)
{
	struct Nodecollege* newNodecollege = (struct Nodecollege*) malloc(sizeof(struct Nodecollege));
	newNodecollege->college = college;
	newNodecollege->next = NULL;
	return newNodecollege;
}


