#include"all.h"

void printcollegememu()
{
	printf("*************************************************\n");
	printf("*******��ѡ���ļ������ķ�ʽ************\n");
	printf("*\t\t0.-���ص���һ���˵�-\t\t*\n");
	printf("*\t\t1.-����ѧԺ�������-\t\t*\n");
	printf("*\t\t2.-����ѧԺ����-\t\t*\n");
	printf("*\t\t3.-ɾ��ѧԺ����-\t\t*\n");
	printf("*                                               *\n");
	printf("*************************************************\n");
}
void memu_college()
{
	int choice_3,i = 0;
	do
		{
			scanf("%d", &choice_3);
			i = 0;
			switch (choice_3)
				{
					case 0:
						return;

					case 1:
						printcollege(listcollege);
						break;

					case 2:
						addcollege(listcollege);
						writeFilecollege(listcollege, "C_Code.txt");
						break;

					case 3:
						deleteNodecollege(listcollege);
						writeFilecollege(listcollege, "C_Code.txt");
						break;

					default:
						printf("\n����������ֲ��ԣ�������ѡ��\n");
						i = 1;
				}
		}
	while(i);
	system("pause");
}

