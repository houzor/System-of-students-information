#include "all.h"
void menu()
{
	printf("*****************************************\n");
	printf("********��ӭʹ��ѧ���ɼ�����ϵͳ*********\n");
	printf("*****************************************\n\n");
	printf("*****************ϵͳ���˵�**************\n");
	printf("*                                       *\n");
	printf("*\t\t1.���ѧ����Ϣ\t\t*\n");
	printf("*\t\t2.¼��ѧ����Ϣ\t\t*\n");
	printf("*\t\t3.�޸�ѧ����Ϣ\t\t*\n");
	printf("*\t\t4.ɾ��ѧ����Ϣ\t\t*\n");
	printf("*\t\t5.����ѧ����Ϣ\t\t*\n");
	printf("*\t\t6.ѧԺ������Ϣ\t\t*\n");	
	printf("*\t\t7.�˳�ϵͳ\t\t*\n");
	printf("*                                       *\n");
	printf("********Powered by ���ܣ�����ͬѧ********\n\n");
}

void interaction()
{
	int choice_1;
	printf("����������ѡ����Ӧ���ܣ�");
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
		printf("\nϵͳ�ѳɹ��˳���\n");
		system("pause");
		writeFile(list, "Stu_Info.txt");
		exit(0);
		break;
		
	default:
		printf("����������������������룡\n");
		break;
	}
	system("pause");
}


