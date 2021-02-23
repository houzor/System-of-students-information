#include <stdio.h>
#include <string.h>
#include "list-stu.h"
#include "list-college.h"
#include "file-stu.h"
extern struct Nodecollege *listcollege;
//学生信息文件的读取
void readFile(struct Node *headNode, char *fileName)
{

	FILE *fp; //文件指针名
	struct student data;
	char tg;
	fp = fopen(fileName, "rt"); //先以读的形式打开信息文件
	if (fp == NULL)
	{
		fopen(fileName, "wt+");			//文件不存在则创建
		memset(&data, 0, sizeof(data)); //初始化/清空结构体的数据
	}

	else
	{
		memset(&data, 0, sizeof(data)); // 初始化结构体数据
		//从文件中读取数据，保存到结构体中
		while (fscanf(fp, "%s\t%s\t%d\t%s\t%d\t%d\t%d\t%d\t", data.num, data.name, &data.sid.id, data.cid.id, &data.mark.score_1, &data.mark.score_2, &data.mark.score_3, &data.mark.score_4) != EOF)
		{
			data.mark.ave = data.mark.score_1 + data.mark.score_2 + data.mark.score_3 + data.mark.score_4;
			data.mark.ave /= 4;
			struct Nodecollege *pMove = listcollege->next;
			tg = 0;
			while (pMove != NULL)
			{
				if (strcmp(pMove->college.id, data.cid.id) == 0)
				{
					strcpy(data.cid.c, pMove->college.c);
					tg = 1;
				}
				pMove = pMove->next;
			}
			if (tg == 0)
			{
				strcpy(data.cid.c, data.cid.id);
				strcat(data.cid.c, "找不到对应学院");
			}
			struct Node *newNode = createNode(data); //为这个结构体创建新节点，然后连接
			newNode->next = headNode->next;
			headNode->next = newNode;
		}
	}
	fclose(fp);
}

//学生信息文件的存储
void writeFile(struct Node *headNode, char *fileName)
{
	FILE *fp;
	fp = fopen(fileName, "w"); //以写的方式打开文件
	if (fp == NULL)
	{
		printf("文件打开失败！\n");
	}
	struct Node *pMove = headNode->next; //创建一个用来移动的指针，首先指向了第一个节点
	while (pMove)
	{
		// 将结构体指针里的内容写入文件
		fprintf(fp, "%s\t%s\t%d\t%s\t%d\t%d\t%d\t%d\n", pMove->data.num, pMove->data.name, pMove->data.sid.id, pMove->data.cid.id, pMove->data.mark.score_1, pMove->data.mark.score_2, pMove->data.mark.score_3, pMove->data.mark.score_4);
		pMove = pMove->next;
	}
	fclose(fp);
}
