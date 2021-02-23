#include "hello.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct users //声明用户输入的账户密码结构体
{
	char ac[30];
	char pw[30];
};
struct users use[50]; //定义用户输入的账户密码
//登录界面
void Hello()
{
	int choice_0;
	printf("*************************************************\n");
	printf("************欢迎使用学生成绩管理系统*************\n");
	printf("*************************************************\n");
	printf("*\t\t1.-登录账号-\t\t\t*\n");
	printf("*\t\t2.-注册账号-\t\t\t*\n");
	printf("*\t\t0.-退出界面-\t\t\t*\n");
	printf("**********Powered by 浩哲，三金同学**************\n\n");
	printf("第一次使用请先注册账号，否则无法进入系统！\n");
	printf("请输入数字选择功能：");
	scanf("%d", &choice_0);
	switch (choice_0)
	{
	case 1:
		login();
		break;
	case 2:
		registerid();
		break;
	case 0:
		printf("\n\t\t成功退出系统！\n");
		exit(0);
		system("pause");
		break;
	default:
		printf("\n您输入的数字不对，请重新选择！\n");
		break;
	}
}

//注册账号
void registerid()
{
	char ac[30];
	char pw[6], pd[6];
	int i, a = 0;
	printf("\t\t*******注册帐号界面*********\n");
	FILE *fp = fopen("admin.txt", "ab"); //以二进制写入
	printf("\t请输入要注册的用户名：");
	scanf("%s", ac);
	strcpy(use[a].ac, ac);

	printf("\n\t请你输入密码，且长度必须为6位(无需回车)：");
	for (i = 0; i < 6; i++)
	{
		pw[i] = _getch(); //使用getch函数不显示输入的字符
		printf("*");
		use[a].pw[i] = pw[i];
		if (pw[i] == '\r') //\r才是标准的回车符
		{
			printf("注册失败，请重新注册账号\n");
			return;
		}
	}

	printf("\n\n\t再次确认密码："); //密码比对
	for (i = 0; i < 6; i++)
	{
		pd[i] = _getch();
		printf("*");
		if (use[a].pw[i] != pd[i])
		{
			printf("\n两次输入密码不一致，请重新注册账号\n");
			return;
		}
	}
	fprintf(fp, "账号\t密码\n"); //完成了以上操作开始向文件输入信息，采用格式化输入更为方便
	fprintf(fp, "%s\t%s\n", use[a].ac, use[a].pw);
	printf("\n恭喜你，注册成功!\n");
	fclose(fp);
	system("pause"); //等待用户信号
	system("cls");	 //使用cls清屏
}

//登录账号
void login()
{
	char ac[30];
	char ad[20], pw;
	int i, j, a = 0;
	int flag = 0;

	printf("\t\t*******登录帐号界面*********\n");
	for (i = 0; i < 3; i++) //设置三次密码登录，否则登录失败
	{
		printf("请输入帐号:");
		scanf("%s", ac);
		printf("请输入密码(无需回车):");
		for (j = 0; j < 6; j++)
		{
			pw = _getch();
			printf("*");
			ad[j] = pw;
		}
		FILE *fp;
		fp = fopen("admin.txt", "r"); //读文件操作
		while (!feof(fp))			  //判断文件打开成功
		{
			fscanf(fp, "%s %sn", use[a].ac, use[a].pw);
			if ((strcmp(ac, use[a].ac) == 0) && (strcmp(ad, use[a].pw) == 0)) //同时对比用户名和密码才行
			{
				flag = 1; //成功flag就1
				fclose(fp);
				break;
			}
			a++;
		}

		if (flag == 1)
		{
			printf("\n登录成功!\n");
			printf("欢迎来到学生信息管理系统!");
			system("pause");
			system("cls");
			while (1)
			{
				menu(); //调用菜单函数
				interaction();
				system("cls");
			}
		}
		else
		{
			printf("\n账号或者密码输入错误，你还有%d次机会，请重新输入：\n", 2 - i);
		}
	}

	if (i == 3)
	{
		printf("登录失败!\n");
		return;
	}
}
