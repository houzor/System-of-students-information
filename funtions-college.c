#include "all.h"
//�����ļ����ѧԺ��Ϣ
void printcollege(struct Nodecollege* headNodecollege)
{
	struct Nodecollege* pMove = headNodecollege->next;
	printf("ѧԺ����\tѧԺ����\n");
	while (pMove)
		{
			printf("%s\t\t%s\n", pMove->college.id, pMove->college.c);
			pMove = pMove->next;
		}
	printf("\n");
}
//ѧԺ¼�빦��
void addcollege(struct Nodecollege* headNodecollege)
{
	COLLEGE college;
	struct Nodecollege* pMove= headNodecollege->next;
	printf("��ֱ�����ѧԺ���ţ�ѧԺ����\n");
	scanf("%s\t%s",college.id,college.c);
	while (pMove != NULL)
		{
			if (strcmp(pMove->college.id,college.id) == 0)
				{
					printf("¼����Ϣ�����ظ���������¼����Ϣ\n");
					return;
				}
			break;
		}
	struct Nodecollege* newNodecollege = createNodecollege(college);
	newNodecollege->next = headNodecollege->next;
	headNodecollege->next = newNodecollege;
}

//ѧԺɾ������
void deleteNodecollege(struct Nodecollege * headNodecollege)
{
	printf("������ɾ����ѧԺ����:\n");
	scanf("%s",number);
	struct Nodecollege* posNode = headNodecollege->next;
	struct Nodecollege* posFrontNode = headNodecollege;

	if (posNode == NULL)
		{
			printf("����Ϊ�գ��޷�ɾ����\n");
			return;
		}
	while (strcmp(posNode->college.id, number))
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
	printf("ѧԺ����Ϊ%sѧУ��Ϣ�Ѿ�ɾ����\n",number);
}

