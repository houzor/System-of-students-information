#include "all.h"
//ѧ����Ϣ¼�빦��
void insertNodeByHead(struct Node* headNode)
{
	struct student data;
	struct Node* pMove = headNode->next;
	printf("��ֱ�����ѧ�ţ��������Ա���룬ѧԺ���룬�ĿƵĳɼ�\n");
	scanf("%s\t%s\t%d\t%s\t%d\t%d\t%d\t%d",data.num,data.name,&data.sid.id,data.cid.id,&data.mark.score_1,&data.mark.score_2,&data.mark.score_3,&data.mark.score_4);
	data.mark.ave = data.mark.score_1+data.mark.score_2+data.mark.score_3+data.mark.score_4;
	data.mark.ave  /= 4;
	while (pMove != NULL)
		{
			if (strcmp(pMove->data.num, data.num) == 0)
				{
					printf("¼����Ϣѧ���ظ���������¼����Ϣ\n");
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
			strcat(data.cid.c,"�Ҳ�����ӦѧԺ") ;
		}
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}


//ѧ����Ϣɾ������
void deleteNode(struct Node* headNode)
{
	printf("������ɾ����ѧ��ѧ��:\n");
	scanf("%s", &number);
	struct Node* posNode = headNode->next;
	struct Node* posFrontNode = headNode;

	if (posNode == NULL)
		{
			printf("����Ϊ�գ��޷�ɾ����\n");
			return;
		}
	while (strcmp(posNode->data.num, number))
		{
			posFrontNode = posNode;
			posNode = posFrontNode->next;
			if (posNode == NULL)
				{
					printf("δ�ҵ�ָ��ѧ�����޷�ɾ����\n");
					return;
				}
		}
	posFrontNode->next = posNode->next;
	free(posNode);
	printf("ѧ��Ϊ%sѧ������Ϣ�Ѿ�ɾ����\n",number);
}

//ѧ����Ϣ�޸Ĺ���
void change(struct Node* headNode)
{
	printf("������Ҫ�޸���Ϣ��ѧ��ѧ�ţ�\n");
	scanf("%s", &number);
	struct Node* changeNode = headNode->next;
	while(1)
		{
			if (changeNode == NULL)
				{
					printf("����Ϊ�գ��޷��޸ģ�\n");
					break;
				}
			else
				{
					if (0 == strcmp(changeNode->data.num, number))
						{
							printf("�������ѧ��Ҫ�ı����Ϣѡ�1.ѧ�� 2.���� 3.�Ա���� 4.ѧԺ���� 5.�ĿƳɼ�:");
							int choose;
							scanf("%d", &choose);
							switch (choose)
								{
									case 1:
										printf("��������Ҫ�޸ĵ�ѧ��\n");
										scanf("%s", &number);
										printf("�޸ĺ��ѧ��Ϊ��%s\n", number);
										strcpy(changeNode->data.num,number);
										printf("�޸�ѧ�ųɹ���\n");
										break;

									case 2:
										printf("��������Ҫ�޸ĵ����֣�");
										scanf("%s", nam);
										printf("��ѧ���µ�����Ϊ��%s\n", nam);
										strcpy(changeNode->data.name,nam);
										printf("�޸����ֳɹ���\n");
										break;

									case 3:
										printf("��������Ҫ�޸ĵ��Ա����");
										scanf("%d", &s);
										printf("��ѧ���µ��Ա����Ϊ��%d\n",s);
										changeNode->data.sid.id = s;
										printf("�޸��Ա����ɹ���\n");
										break;

									case 4:
										printf("��������Ҫ�޸ĵ�ѧԺ����");
										scanf("%s", c);
										printf("��ѧ���µ�ѧԺ����Ϊ��%s\n",c);
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
												strcat(changeNode->data.cid.c,"�Ҳ�����ӦѧԺ") ;
											}
										printf("�޸�ѧԺ����ɹ���\n");
										break;

									case 5:
										printf("�����������µĳɼ�");
										scanf("%d%d%d%d", &mark_1,&mark_2,&mark_3,&mark_4);
										printf("��ѧ���µĳɼ�Ϊ��%d\t%d\t%d\t%d\n",mark_1,mark_2,mark_3,mark_4);
										changeNode->data.mark.score_1 = mark_1;
										changeNode->data.mark.score_2 = mark_2;
										changeNode->data.mark.score_3 = mark_3;
										changeNode->data.mark.score_4 = mark_4;
										changeNode->data.mark.ave = changeNode->data.mark.score_1+changeNode->data.mark.score_2+changeNode->data.mark.score_3+changeNode->data.mark.score_4;
										changeNode->data.mark.ave /= 4;
										printf("�޸ĸ�ѧ���ɼ��ɹ���\n");
										break;
									default:
										printf("�������ѡ��ԣ���������ȷ��ѡ�\n");
										break;
								}
							break;
						}
				}
			changeNode = changeNode->next;
		}
}

//ѧ����Ϣ���ҹ���
struct Node* searchInfoByData(struct Node* headNode)
{
	printf("������Ҫ���ҵ�ѧ��ѧ��:\n");
	scanf("%s", &number);
	struct Node* pMove = headNode->next;
	while (strcmp(pMove->data.num, number))
		{
			pMove = pMove->next;
			if(pMove == NULL)
				{
					printf("δ�ҵ������Ϣ!\n");
					return NULL;
				}
		}
	printf("ѧ��\t����\t�Ա����\tѧԺ����\t��Ŀһ\t��Ŀ��\t��Ŀ��\t��Ŀ��\tƽ���ɼ�\n");
	printf("%s\t%s\t%d\t\t%s\t%d\t%d\t%d\t%d\t%f\n", pMove->data.num, pMove->data.name, pMove->data.sid.id, pMove->data.cid.c, pMove->data.mark.score_1, pMove->data.mark.score_2, pMove->data.mark.score_3, pMove->data.mark.score_4,pMove->data.mark.ave);
	return NULL;
}





