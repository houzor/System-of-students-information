#ifndef _ALL_H
#define _ALL_H
#include <stdio.h>
#include <conio.h>		//getch()������Ҫ 
#include<string.h>		 
#include<stdlib.h>
#include<math.h>
typedef struct{
	int id;
	char s[2];
}SEX;
	
typedef struct{
	char id[4];
	char c[32];
}COLLEGE;

typedef struct{
	int score_1;
	int score_2;
	int score_3;
	int score_4;
	float ave;
}SCORE;

struct student{
	char num[20];
	char name[20];
	SEX sid;
	COLLEGE cid;
	SCORE mark; 
};


char number[20],nam[20];   //ȫ�ֶ�����������Ժ����ɾ���Ա��޸� 
int s;
char c[4];
int mark_1,mark_2,mark_3,mark_4; 

struct users				//�����û�������˻�����ṹ��
{
	char ac[30];
	char pw[30];
};
struct users use[50];	//�����û�������˻����� 

struct Node				//�����ڵ�Ľṹ�� 
{
	struct student data;
	struct Node* next;
};

struct Nodecollege				//�����ڵ�Ľṹ�� 
{
	COLLEGE college;
	struct Nodecollege* next;
};

struct Nodecollege* listcollege;
struct Node* list;		//��������ͷ 


//��¼ϵͳ��غ��� 
void Hello();
void registerid();
void login();
 
//�˵��ͽ�����غ��� 
void menu();
void interaction();
void printListmemu();
void printlistinteract();
 
//���ѧ���ɼ���غ��� 
void printstu(struct Node* headNode);	
void sortbyname(struct Node* headNode);
void sortbyave(struct Node* headNode);
void putbycollege(struct Node* headNode);
void putbyfail(struct Node* headNode);

//��ɾ�Ĳ�ѧ����Ϣ���� 
void insertNodeByHead(struct Node* headNode);
void deleteNode(struct Node* headNode);
void change(struct Node* headNode);
struct Node* searchInfoByData(struct Node* headNode);

//��д�ļ����� 
void readFile(struct Node* headNode, char *fileName);
void writeFile(struct Node* headNode, char* fileName);
void writeFilecollege(struct Nodecollege* headNodecollege, char* fileName);
void readFilecollege(struct Nodecollege* headNodecollege, char *fileName);

//���ѧԺ��غ���
void printcollege(struct Nodecollege* headNodecollege); 
void addcollege(struct Nodecollege* headNodecollege); 
void deleteNodecollege(struct Nodecollege * headNodecollege);



#endif
