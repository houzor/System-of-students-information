#include "all.h"
//学生信息录入功能
void insertNodeByHead(struct Node* headNode)
{
	struct student data;
	struct Node* pMove = headNode->next;
	printf("请分别输入学号，姓名，性别代码，学院代码，四科的成绩\n");
	scanf("%s\t%s\t%d\t%s\t%d\t%d\t%d\t%d",data.num,data.name,&data.sid.id,data.cid.id,&data.mark.score_1,&data.mark.score_2,&data.mark.score_3,&data.mark.score_4);
	data.mark.ave = data.mark.score_1+data.mark.score_2+data.mark.score_3+data.mark.score_4;
	data.mark.ave  /= 4;
	while (pMove != NULL)
		{
			if (strcmp(pMove->data.num, data.num) == 0)
				{
					printf("录入信息学号重复，请重新录入信息\n");
					return;
				}
			pMove = pMove->next;

		}
	struct Nodecollege* pMovecollege = listcollege->next;
	int tg = 0;
	while(pMovecollege != NULL)
		{
			if(strcmp(pMovecollege->college.id,data.cid.id) == 0)
				{
					strcpy(data.cid.c,pMovecollege->college.c);
					tg = 1;
				}
			pMovecollege = pMovecollege->next;
		}
	if(tg == 0)
		{
			strcpy(data.cid.c,data.cid.id);
			strcat(data.cid.c,"找不到对应学院") ;
		}
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}


//学生信息删除功能
void deleteNode(struct Node* headNode)
{
	printf("请输入删除的学生学号:\n");
	scanf("%s", &number);
	struct Node* posNode = headNode->next;
	struct Node* posFrontNode = headNode;

	if (posNode == NULL)
		{
			printf("数据为空，无法删除！\n");
			return;
		}
	while (strcmp(posNode->data.num, number))
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
	printf("学号为%s学生的信息已经删除！\n",number);
}

//学生信息修改功能
void change(struct Node* headNode)
{
	printf("请输入要修改信息的学生学号：\n");
	scanf("%s", &number);
	struct Node* changeNode = headNode->next;
	while(1)
		{
			if (changeNode == NULL)
				{
					printf("数据为空，无法修改！\n");
					break;
				}
			else
				{
					if (0 == strcmp(changeNode->data.num, number))
						{
							printf("请输入该学生要改变的信息选项：1.学号 2.姓名 3.性别代码 4.学院代码 5.四科成绩:");
							int choose;
							scanf("%d", &choose);
							switch (choose)
								{
									case 1:
										printf("请输入您要修改的学号\n");
										scanf("%s", &number);
										printf("修改后的学号为：%s\n", number);
										strcpy(changeNode->data.num,number);
										printf("修改学号成功！\n");
										break;

									case 2:
										printf("请输入您要修改的名字：");
										scanf("%s", nam);
										printf("该学生新的名字为：%s\n", nam);
										strcpy(changeNode->data.name,nam);
										printf("修改名字成功！\n");
										break;

									case 3:
										printf("请输入您要修改的性别代码");
										scanf("%d", &s);
										printf("该学生新的性别代码为：%d\n",s);
										changeNode->data.sid.id = s;
										printf("修改性别代码成功！\n");
										break;

									case 4:
										printf("请输入您要修改的学院代码");
										scanf("%s", c);
										printf("该学生新的学院代码为：%s\n",c);
										strcpy(changeNode->data.cid.id,c);
										struct Nodecollege* pMove = listcollege->next;
										int tg = 0;
										while(pMove != NULL)
											{
												if(strcmp(pMove->college.id,c) == 0)
													{
														strcpy(changeNode->data.cid.c,pMove->college.c);
														tg = 1;
													}
												pMove = pMove->next;
											}
										if(tg == 0)
											{
												strcpy(changeNode->data.cid.c,changeNode->data.cid.id);
												strcat(changeNode->data.cid.c,"找不到对应学院") ;
											}
										printf("修改学院代码成功！\n");
										break;

									case 5:
										printf("请依次输入新的成绩");
										scanf("%d%d%d%d", &mark_1,&mark_2,&mark_3,&mark_4);
										printf("该学生新的成绩为：%d\t%d\t%d\t%d\n",mark_1,mark_2,mark_3,mark_4);
										changeNode->data.mark.score_1 = mark_1;
										changeNode->data.mark.score_2 = mark_2;
										changeNode->data.mark.score_3 = mark_3;
										changeNode->data.mark.score_4 = mark_4;
										changeNode->data.mark.ave = changeNode->data.mark.score_1+changeNode->data.mark.score_2+changeNode->data.mark.score_3+changeNode->data.mark.score_4;
										changeNode->data.mark.ave /= 4;
										printf("修改该学生成绩成功！\n");
										break;
									default:
										printf("您输入的选项不对，请输入正确的选项！\n");
										break;
								}
							break;
						}
				}
			changeNode = changeNode->next;
		}
}

//学生信息查找功能
struct Node* searchInfoByData(struct Node* headNode)
{
	printf("请输入要查找的学生学号:\n");
	scanf("%s", &number);
	struct Node* pMove = headNode->next;
	while (strcmp(pMove->data.num, number))
		{
			pMove = pMove->next;
			if(pMove == NULL)
				{
					printf("未找到相关信息!\n");
					return NULL;
				}
		}
	printf("学号\t姓名\t性别代码\t学院名称\t科目一\t科目二\t科目三\t科目四\t平均成绩\n");
	printf("%s\t%s\t%d\t\t%s\t%d\t%d\t%d\t%d\t%f\n", pMove->data.num, pMove->data.name, pMove->data.sid.id, pMove->data.cid.c, pMove->data.mark.score_1, pMove->data.mark.score_2, pMove->data.mark.score_3, pMove->data.mark.score_4,pMove->data.mark.ave);
	return NULL;
}





