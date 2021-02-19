#include"all.h"
void printListmemu()
{	
	printf("*************************************************\n");
	printf("*******请选择你想要输出学生成绩的方式************\n");
	printf("*\t\t0.-返回到上一个菜单-\t\t*\n");
	printf("*\t\t1.-以原始文件输出-\t\t*\n");
	printf("*\t\t2.-按姓名排序输出-\t\t*\n");
	printf("*\t\t3.-按平均成绩排序-\t\t*\n");
	printf("*\t\t4.-输出给定学院学生-\t\t*\n");
	printf("*\t\t5.-输出挂科学生-\t\t*\n");
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
			printf("\n您输入的数字不对，请重新选择！\n");
			i = 1;
	}}while(i);
	system("pause");
} 

