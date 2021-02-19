#ifndef _ALL_H
#define _ALL_H
#include <stdio.h>
#include <conio.h>		//getch()函数需要 
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


char number[20],nam[20];   //全局定义变量，用以后面的删除对比修改 
int s;
char c[4];
int mark_1,mark_2,mark_3,mark_4; 

struct users				//声明用户输入的账户密码结构体
{
	char ac[30];
	char pw[30];
};
struct users use[50];	//定义用户输入的账户密码 

struct Node				//声明节点的结构体 
{
	struct student data;
	struct Node* next;
};

struct Nodecollege				//声明节点的结构体 
{
	COLLEGE college;
	struct Nodecollege* next;
};

struct Nodecollege* listcollege;
struct Node* list;		//定义链表头 


//登录系统相关函数 
void Hello();
void registerid();
void login();
 
//菜单和交互相关函数 
void menu();
void interaction();
void printListmemu();
void printlistinteract();
 
//输出学生成绩相关函数 
void printstu(struct Node* headNode);	
void sortbyname(struct Node* headNode);
void sortbyave(struct Node* headNode);
void putbycollege(struct Node* headNode);
void putbyfail(struct Node* headNode);

//增删改查学生信息函数 
void insertNodeByHead(struct Node* headNode);
void deleteNode(struct Node* headNode);
void change(struct Node* headNode);
struct Node* searchInfoByData(struct Node* headNode);

//读写文件函数 
void readFile(struct Node* headNode, char *fileName);
void writeFile(struct Node* headNode, char* fileName);
void writeFilecollege(struct Nodecollege* headNodecollege, char* fileName);
void readFilecollege(struct Nodecollege* headNodecollege, char *fileName);

//输出学院相关函数
void printcollege(struct Nodecollege* headNodecollege); 
void addcollege(struct Nodecollege* headNodecollege); 
void deleteNodecollege(struct Nodecollege * headNodecollege);



#endif
