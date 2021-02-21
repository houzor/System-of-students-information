#include "all.h"
//�����ļ����ѧ����Ϣ
void printstu(struct Node* headNode)
{
	struct Node* pMove = headNode->next;
	printf("ѧ��\t����\t�Ա����\tѧԺ����\t\t��Ŀһ\t��Ŀ��\t��Ŀ��\t��Ŀ��\tƽ���ɼ�\n");
	while (pMove)
		{
			printf("%s\t%s\t%d\t\t%s\t\t%d\t%d\t%d\t%d\t%f\n", pMove->data.num, pMove->data.name, pMove->data.sid.id, pMove->data.cid.c, pMove->data.mark.score_1, pMove->data.mark.score_2, pMove->data.mark.score_3, pMove->data.mark.score_4,pMove->data.mark.ave);
			pMove = pMove->next;
		}
	printf("\n");
}

//����������
void sortbyname(struct Node*headNode)
{
	struct Node* pMove = headNode->next;
	struct Node temp;
	int junge;
	while(1)
		{
			printf("�Ƿ񰴴Ӵ�С˳��������������1 ��������0��");
			scanf("%d",&junge);
			if(junge == 1||junge == 0)
				{
					break;
				}
			else
				{
					printf("�����������0��1��������룺");
				}
		}
	while(pMove->next != NULL)
		{
			struct Node* pMove_junge = pMove->next;
			while(pMove_junge)
				{
					if(junge == 0)
						{
							if(strcmp(pMove->data.name,pMove_junge->data.name) > 0)
								{
									temp.data= pMove->data;
									pMove->data = pMove_junge->data;
									pMove_junge->data = temp.data;
								}
						}
					else
						{
							if(strcmp(pMove->data.name,pMove_junge->data.name) < 0)
								{
									temp.data= pMove->data;
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
//��ƽ���ɼ�����
void sortbyave(struct Node*headNode)
{
	struct Node* pMove = headNode->next;
	struct Node temp;
	int junge;
	while(1)
		{
			printf("�Ƿ񰴴Ӵ�С˳��������������1 ��������0��");
			scanf("%d",&junge);
			if(junge == 1||junge == 0)
				{
					break;
				}
			else
				{
					printf("�����������0��1��������룺");
				}
		}
	while(pMove->next != NULL)
		{
			struct Node* pMove_junge = pMove->next;
			while(pMove_junge)
				{
					if(junge == 1)
						{
							if(pMove->data.mark.ave < pMove_junge->data.mark.ave)
								{
									temp.data= pMove->data;
									pMove->data = pMove_junge->data;
									pMove_junge->data = temp.data;
								}
						}
					else
						{
							if(pMove->data.mark.ave > pMove_junge->data.mark.ave)
								{
									temp.data= pMove->data;
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

//��ѧԺ���
void putbycollege(struct Node* headNode)
{
	struct Node* pMove = headNode->next;
	int junge = 0;
	printf("������һ��ѧԺ�������о�������ѧԺ���ѧ����");
	scanf("%s",number);
	while (pMove)
		{
			if(strcmp(pMove->data.cid.id,number) == 0)
				{
					junge++;
					if(junge == 1)
						{
							printf("��%s %s��ѧ����Ϣ����\n",number,pMove->data.cid.c);
							printf("ѧ��\t����\t�Ա����\tѧԺ����\t��Ŀһ\t��Ŀ��\t��Ŀ��\t��Ŀ��\tƽ���ɼ�\n");
						}
					printf("%s\t%s\t%d\t\t%s\t\t%d\t%d\t%d\t%d\t%f\n", pMove->data.num, pMove->data.name, pMove->data.sid.id, pMove->data.cid.c, pMove->data.mark.score_1, pMove->data.mark.score_2, pMove->data.mark.score_3, pMove->data.mark.score_4,pMove->data.mark.ave);
				}
			pMove = pMove->next;
		}
	if(junge == 0)
		{
			printf("û���ҵ����ѧԺ��ѧ��");
		}
	printf("\n");
}
//����ҿ�ѧ��
void putbyfail(struct Node* headNode)
{
	struct Node* pMove = headNode->next;
	int junge = 0;
	while (pMove)
		{
			if((pMove->data.mark.score_1 < 60)||(pMove->data.mark.score_2 < 60)||(pMove->data.mark.score_3 < 60)||(pMove->data.mark.score_4 < 60))
				{
					junge++;
					if(junge == 1)
						{
							printf("�ڹҿƵ�ѧ��Ϊ\n",number,pMove->data.cid.c);
							printf("ѧ��\t����\t�Ա����\tѧԺ����\t\t�ҿƿ�Ŀ\n");
						}
					printf("%s\t%s\t%d\t\t%s\t\t", pMove->data.num, pMove->data.name, pMove->data.sid.id, pMove->data.cid.c);
					if(pMove->data.mark.score_1 < 60)
						{
							printf("��Ŀһ ");
						}
					if(pMove->data.mark.score_2 < 60)
						{
							printf("��Ŀ�� ");
						}
					if(pMove->data.mark.score_3 < 60)
						{
							printf("��Ŀ�� ");
						}
					if(pMove->data.mark.score_4 < 60)
						{
							printf("��Ŀ�� ");
						}
					printf("\n");
				}
			pMove = pMove->next;
		}
	if(junge == 0)
		{
			printf("û���ҵ��ҿƵ�ѧ��");
		}
	printf("\n");
}

