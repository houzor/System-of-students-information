#include "all.h"
//ѧ����Ϣ�ļ��Ķ�ȡ
void readFile(struct Node* headNode,char *fileName)
{
                
	 FILE* fp;//�ļ�ָ���� 
	 struct student data;
	 char tg;
	 fp = fopen(fileName, "rt");       //���Զ�����ʽ����Ϣ�ļ�    
 	if (fp == NULL)
 	{
  		fopen(fileName, "wt+");       //�ļ��������򴴽� 
 		memset(&data, 0, sizeof(data));     //��ʼ��/��սṹ������� 
	}
 
 	else
 	{
 	 memset(&data, 0, sizeof(data));     // ��ʼ���ṹ������ 
              //���ļ��ж�ȡ���ݣ����浽�ṹ���� 
 	 	while (fscanf(fp,"%s\t%s\t%d\t%s\t%d\t%d\t%d\t%d\t", data.num, data.name,&data.sid.id, data.cid.id,&data.mark.score_1,&data.mark.score_2,&data.mark.score_3,&data.mark.score_4) != EOF)
	  	{
 	  		data.mark.ave = data.mark.score_1+data.mark.score_2+data.mark.score_3+data.mark.score_4;
 	  		data.mark.ave /= 4;
			struct Nodecollege* pMove= listcollege->next;
 	  		tg = 0;
			while(pMove != NULL){
 	  			if(strcmp(pMove->college.id,data.cid.id) == 0){
 	  				strcpy(data.cid.c,pMove->college.c);
 	  				tg = 1;
				}
				pMove = pMove->next;
			}
			if(tg == 0){
				strcpy(data.cid.c,data.cid.id);
				strcat(data.cid.c,"�Ҳ�����ӦѧԺ") ;
			}
			struct Node* newNode = createNode(data);     //Ϊ����ṹ�崴���½ڵ㣬Ȼ������ 
  			newNode->next = headNode->next;    
 	 		headNode->next = newNode;
		}
 	}
 	fclose(fp);
}

//ѧ����Ϣ�ļ��Ĵ洢
void writeFile(struct Node* headNode, char* fileName)
{
	 FILE* fp;
 	fp = fopen(fileName, "w");        //��д�ķ�ʽ���ļ� 
 	if (fp == NULL)
 	{
 		 printf("�ļ���ʧ�ܣ�\n");
 	}
 	struct Node* pMove = headNode->next;   //����һ�������ƶ���ָ�룬����ָ���˵�һ���ڵ� 
 	while (pMove)
 	{              // ���ṹ��ָ���������д���ļ� 
 		 fprintf(fp,"%s\t%s\t%d\t%s\t%d\t%d\t%d\t%d\n", pMove->data.num, pMove->data.name, pMove->data.sid.id, pMove->data.cid.id, pMove->data.mark.score_1, pMove->data.mark.score_2, pMove->data.mark.score_3, pMove->data.mark.score_4);
 		 pMove = pMove->next;
	 } 
	 fclose(fp);     
}


