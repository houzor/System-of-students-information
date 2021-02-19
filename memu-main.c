#include "all.h"
void menu()
{
	printf("*****************************************\n");
	printf("********欢迎使用学生成绩管理系统*********\n");
	printf("*****************************************\n\n");
	printf("*****************系统主菜单**************\n");
	printf("*                                       *\n");
	printf("*\t\t1.浏览学生信息\t\t*\n");
	printf("*\t\t2.录入学生信息\t\t*\n");
	printf("*\t\t3.修改学生信息\t\t*\n");
	printf("*\t\t4.删除学生信息\t\t*\n");
	printf("*\t\t5.查找学生信息\t\t*\n");
	printf("*\t\t6.学院代码信息\t\t*\n");	
	printf("*\t\t7.退出系统\t\t*\n");
	printf("*                                       *\n");
	printf("********Powered by 浩哲，三金同学********\n\n");
}

void interaction()
{
	int choice_1;
	printf("请输入数字选择相应功能：");
	scanf("%d", &choice_1);
	switch (choice_1)
	{
	case 1:
		system("cls");
		printListmemu();
		printlistinteract(); 
		return;
	case 2:
		system("cls");
		insertNodeByHead(list);
		writeFile(list, "Stu_Info.txt");
		break;
	case 3:
		system("cls");
		change(list);
		writeFile(list, "Stu_Info.txt");
		break;
	case 4:
		system("cls");
		deleteNode(list);
		writeFile(list, "Stu_Info.txt");
		break;
	case 5:
		system("cls");
		searchInfoByData(list);
		break;
	case 6:
		system("cls");
		printcollegememu();
		memu_college(); 
		return;
	case 7:
		system("cls");
		printf("\n系统已成功退出！\n");
		system("pause");
		writeFile(list, "Stu_Info.txt");
		exit(0);
		break;
		
	default:
		printf("输入的数字有误，请重新输入！\n");
		break;
	}
	system("pause");
}


