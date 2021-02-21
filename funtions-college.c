#include "all.h"
//整个文件输出学院信息
void printcollege(struct Nodecollege* headNodecollege)
{
	struct Nodecollege* pMove = headNodecollege->next;
	printf("学院代号\t学院名称\n");
	while (pMove)
		{
			printf("%s\t\t%s\n", pMove->college.id, pMove->college.c);
			pMove = pMove->next;
		}
	printf("\n");
}
//学院录入功能
void addcollege(struct Nodecollege* headNodecollege)
{
	COLLEGE college;
	struct Nodecollege* pMove= headNodecollege->next;
	printf("请分别输入学院代号，学院名称\n");
	scanf("%s\t%s",college.id,college.c);
	while (pMove != NULL)
		{
			if (strcmp(pMove->college.id,college.id) == 0)
				{
					printf("录入信息代号重复，请重新录入信息\n");
					return;
				}
			break;
		}
	struct Nodecollege* newNodecollege = createNodecollege(college);
	newNodecollege->next = headNodecollege->next;
	headNodecollege->next = newNodecollege;
}

//学院删除功能
void deleteNodecollege(struct Nodecollege * headNodecollege)
{
	printf("请输入删除的学院代号:\n");
	scanf("%s",number);
	struct Nodecollege* posNode = headNodecollege->next;
	struct Nodecollege* posFrontNode = headNodecollege;

	if (posNode == NULL)
		{
			printf("数据为空，无法删除！\n");
			return;
		}
	while (strcmp(posNode->college.id, number))
		{
			posFrontNode = posNode;
			posNode = posFrontNode->next;
			if (posNode == NULL)
				{
					printf("未找到指定学生，无法删除！\n");
					return;
				}
		}
	posFrontNode->next = posNode->next;
	free(posNode);
	printf("学院代号为%s学校信息已经删除！\n",number);
}

