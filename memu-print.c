#include"all.h"
void printListmemu()
{	
	printf("*************************************************\n");
	printf("*******��ѡ������Ҫ���ѧ���ɼ��ķ�ʽ************\n");
	printf("*\t\t0.-���ص���һ���˵�-\t\t*\n");
	printf("*\t\t1.-��ԭʼ�ļ����-\t\t*\n");
	printf("*\t\t2.-�������������-\t\t*\n");
	printf("*\t\t3.-��ƽ���ɼ�����-\t\t*\n");
	printf("*\t\t4.-�������ѧԺѧ��-\t\t*\n");
	printf("*\t\t5.-����ҿ�ѧ��-\t\t*\n");
	printf("*                                               *\n");
	printf("*************************************************\n");
}	
void printlistinteract()
{
	int choice_2,i = 0;
	do{
		scanf("%d", &choice_2);
		i = 0;
		switch (choice_2)
		{
		case 0:
			return;
	
		case 1:
			printstu(list);	
			break;
	
		case 2:
			sortbyname(list);
			break;
		
		case 3:
			sortbyave(list);
			break;
			
		case 4:
			putbycollege(list);
			break;
		
		case 5:
			putbyfail(list);
			break;
			
		default:
			printf("\n����������ֲ��ԣ�������ѡ��\n");
			i = 1;
	}}while(i);
	system("pause");
} 

