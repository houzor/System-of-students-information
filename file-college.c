#include "all.h"
//ѧԺ�����ļ��Ķ�ȡ
void readFilecollege(struct Nodecollege* headNodecollege, char *fileName)
{

	FILE* fp;//�ļ�ָ����
	COLLEGE college;
	fp = fopen(fileName, "rt");       //���Զ�����ʽ����Ϣ�ļ�
	if (fp == NULL)
		{
			fopen(fileName, "wt+");       //�ļ��������򴴽�
			memset(&college, 0, sizeof(college));     //��ʼ��/��սṹ�������
		}

	else
		{
			memset(&college, 0, sizeof(college));     // ��ʼ���ṹ������
			//���ļ��ж�ȡ���ݣ����浽�ṹ����
			while (fscanf(fp,"%s\t%s\n",college.id,college.c) != EOF)
				{
					struct Nodecollege* newNodecollege = createNodecollege(college);     //Ϊ����ṹ�崴���½ڵ㣬Ȼ������
					newNodecollege->next = headNodecollege->next;
					headNodecollege->next = newNodecollege;
				}
		}
	fclose(fp);
}

//ѧԺ�����ļ��Ĵ洢
void writeFilecollege(struct Nodecollege * headNodecollege, char* fileName)
{
	FILE* fp;
	fp = fopen(fileName, "w");        //��д�ķ�ʽ���ļ�
	if (fp == NULL)
		{
			printf("�ļ���ʧ�ܣ�\n");
		}
	struct Nodecollege* pMove = headNodecollege->next;   //����һ�������ƶ���ָ�룬����ָ���˵�һ���ڵ�
	while (pMove)
		{
			// ���ṹ��ָ���������д���ļ�
			fprintf(fp,"%s\t%s\n", pMove->college.id, pMove->college.c);
			pMove = pMove->next;
		}
	fclose(fp);
}
