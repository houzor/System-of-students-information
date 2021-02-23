#include "list-stu.h"
#include "funtions-print.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
extern char number[20];
//整个文件输出学生信息
void printstu(struct Node *headNode)
{
	struct Node *pMove = headNode->next;
	printf("学号\t姓名\t性别代码\t学院名称\t\t科目一\t科目二\t科目三\t科目四\t平均成绩\n");
	while (pMove)
	{
		printf("%s\t%s\t%d\t\t%s\t\t%d\t%d\t%d\t%d\t%f\n", pMove->data.num, pMove->data.name, pMove->data.sid.id, pMove->data.cid.c, pMove->data.mark.score_1, pMove->data.mark.score_2, pMove->data.mark.score_3, pMove->data.mark.score_4, pMove->data.mark.ave);
		pMove = pMove->next;
	}
	printf("\n");
}

//按姓名排序
void sortbyname(struct Node *headNode)
{
	struct Node *pMove = headNode->next;
	struct Node temp;
	int junge;
	while (1)
	{
		printf("是否按从大到小顺序排序是请输入1 否请输入0：");
		scanf("%d", &junge);
		if (junge == 1 || junge == 0)
		{
			break;
		}
		else
		{
			printf("输入的数不是0或1请从新输入：");
		}
	}
	while (pMove->next != NULL)
	{
		struct Node *pMove_junge = pMove->next;
		while (pMove_junge)
		{
			if (junge == 0)
			{
				if (strcmp(pMove->data.name, pMove_junge->data.name) > 0)
				{
					temp.data = pMove->data;
					pMove->data = pMove_junge->data;
					pMove_junge->data = temp.data;
				}
			}
			else
			{
				if (strcmp(pMove->data.name, pMove_junge->data.name) < 0)
				{
					temp.data = pMove->data;
					pMove->data = pMove_junge->data;
					pMove_junge->data = temp.data;
				}
			}
			pMove_junge = pMove_junge->next;
		}
		pMove = pMove->next;
	}
	printstu(headNode);
	return;
}
//按平均成绩排序
void sortbyave(struct Node *headNode)
{
	struct Node *pMove = headNode->next;
	struct Node temp;
	int junge;
	while (1)
	{
		printf("是否按从大到小顺序排序是请输入1 否请输入0：");
		scanf("%d", &junge);
		if (junge == 1 || junge == 0)
		{
			break;
		}
		else
		{
			printf("输入的数不是0或1请从新输入：");
		}
	}
	while (pMove->next != NULL)
	{
		struct Node *pMove_junge = pMove->next;
		while (pMove_junge)
		{
			if (junge == 1)
			{
				if (pMove->data.mark.ave < pMove_junge->data.mark.ave)
				{
					temp.data = pMove->data;
					pMove->data = pMove_junge->data;
					pMove_junge->data = temp.data;
				}
			}
			else
			{
				if (pMove->data.mark.ave > pMove_junge->data.mark.ave)
				{
					temp.data = pMove->data;
					pMove->data = pMove_junge->data;
					pMove_junge->data = temp.data;
				}
			}
			pMove_junge = pMove_junge->next;
		}
		pMove = pMove->next;
	}
	printstu(headNode);
	return;
}

//按学院输出
void putbycollege(struct Node *headNode)
{
	struct Node *pMove = headNode->next;
	int junge = 0;
	printf("请输入一个学院代码来列举这个这个学院里的学生：");
	scanf("%s", number);
	while (pMove)
	{
		if (strcmp(pMove->data.cid.id, number) == 0)
		{
			junge++;
			if (junge == 1)
			{
				printf("在%s %s的学生信息如下\n", number, pMove->data.cid.c);
				printf("学号\t姓名\t性别代码\t学院名称\t科目一\t科目二\t科目三\t科目四\t平均成绩\n");
			}
			printf("%s\t%s\t%d\t\t%s\t\t%d\t%d\t%d\t%d\t%f\n", pMove->data.num, pMove->data.name, pMove->data.sid.id, pMove->data.cid.c, pMove->data.mark.score_1, pMove->data.mark.score_2, pMove->data.mark.score_3, pMove->data.mark.score_4, pMove->data.mark.ave);
		}
		pMove = pMove->next;
	}
	if (junge == 0)
	{
		printf("没有找到这个学院的学生");
	}
	printf("\n");
}
//输出挂科学生
void putbyfail(struct Node *headNode)
{
	struct Node *pMove = headNode->next;
	int junge = 0;
	while (pMove)
	{
		if ((pMove->data.mark.score_1 < 60) || (pMove->data.mark.score_2 < 60) || (pMove->data.mark.score_3 < 60) || (pMove->data.mark.score_4 < 60))
		{
			junge++;
			if (junge == 1)
			{
				printf("在挂科的学生为%s %s\n", number, pMove->data.cid.c);
				printf("学号\t姓名\t性别代码\t学院名称\t\t挂科科目\n");
			}
			printf("%s\t%s\t%d\t\t%s\t\t", pMove->data.num, pMove->data.name, pMove->data.sid.id, pMove->data.cid.c);
			if (pMove->data.mark.score_1 < 60)
			{
				printf("科目一 ");
			}
			if (pMove->data.mark.score_2 < 60)
			{
				printf("科目二 ");
			}
			if (pMove->data.mark.score_3 < 60)
			{
				printf("科目三 ");
			}
			if (pMove->data.mark.score_4 < 60)
			{
				printf("科目四 ");
			}
			printf("\n");
		}
		pMove = pMove->next;
	}
	if (junge == 0)
	{
		printf("没有找到挂科的学生");
	}
	printf("\n");
}
