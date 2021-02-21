#include"all.h"

void printcollegememu()
{
	printf("*************************************************\n");
	printf("*******请选择文件操作的方式************\n");
	printf("*\t\t0.-返回到上一个菜单-\t\t*\n");
	printf("*\t\t1.-所有学院代码输出-\t\t*\n");
	printf("*\t\t2.-增加学院代码-\t\t*\n");
	printf("*\t\t3.-删除学院代码-\t\t*\n");
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
						printf("\n您输入的数字不对，请重新选择！\n");
						i = 1;
				}
		}
	while(i);
	system("pause");
}

