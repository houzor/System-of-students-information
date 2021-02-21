#include "all.h"
//学院代号文件的读取
void readFilecollege(struct Nodecollege* headNodecollege, char *fileName)
{

	FILE* fp;//文件指针名
	COLLEGE college;
	fp = fopen(fileName, "rt");       //先以读的形式打开信息文件
	if (fp == NULL)
		{
			fopen(fileName, "wt+");       //文件不存在则创建
			memset(&college, 0, sizeof(college));     //初始化/清空结构体的数据
		}

	else
		{
			memset(&college, 0, sizeof(college));     // 初始化结构体数据
			//从文件中读取数据，保存到结构体中
			while (fscanf(fp,"%s\t%s\n",college.id,college.c) != EOF)
				{
					struct Nodecollege* newNodecollege = createNodecollege(college);     //为这个结构体创建新节点，然后连接
					newNodecollege->next = headNodecollege->next;
					headNodecollege->next = newNodecollege;
				}
		}
	fclose(fp);
}

//学院代号文件的存储
void writeFilecollege(struct Nodecollege * headNodecollege, char* fileName)
{
	FILE* fp;
	fp = fopen(fileName, "w");        //以写的方式打开文件
	if (fp == NULL)
		{
			printf("文件打开失败！\n");
		}
	struct Nodecollege* pMove = headNodecollege->next;   //创建一个用来移动的指针，首先指向了第一个节点
	while (pMove)
		{
			// 将结构体指针里的内容写入文件
			fprintf(fp,"%s\t%s\n", pMove->college.id, pMove->college.c);
			pMove = pMove->next;
		}
	fclose(fp);
}
