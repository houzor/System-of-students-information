#include "all.h"
//��¼���� 
void Hello()
{
	int choice_0;
	printf("*************************************************\n");
	printf("************��ӭʹ��ѧ���ɼ�����ϵͳ*************\n");
	printf("*************************************************\n");
	printf("*\t\t1.-��¼�˺�-\t\t\t*\n");
	printf("*\t\t2.-ע���˺�-\t\t\t*\n");
	printf("*\t\t0.-�˳�����-\t\t\t*\n");
	printf("**********Powered by ���ܣ�����ͬѧ**************\n\n");
	printf("��һ��ʹ������ע���˺ţ������޷�����ϵͳ��\n");
	printf("����������ѡ���ܣ�");
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
		printf("\n\t\t�ɹ��˳�ϵͳ��\n");
		exit(0);
		system("pause");
		break;
	default:
		printf("\n����������ֲ��ԣ�������ѡ��\n");
		break;
	}
}

//ע���˺� 
void registerid()
{
	char ac[30];
	char pw[6],pd[6];
	int	i, a = 0;
	printf("\t\t*******ע���ʺŽ���*********\n");
	FILE *fp=fopen("admin.txt", "ab");								    //�Զ�����д�� 
	printf("\t������Ҫע����û�����");										
	scanf("%s", &ac);
	strcpy(use[a].ac, ac);
	
	printf("\n\t�����������룬�ҳ��ȱ���Ϊ6λ(����س�)��");
	for (i = 0; i<6; i++)
	{
		pw[i] = _getch();													//ʹ��getch��������ʾ������ַ� 
		printf("*");
		use[a].pw[i] = pw[i];
		if (pw[i] == '\r')													//\r���Ǳ�׼�Ļس��� 
		{
			printf("ע��ʧ�ܣ�������ע���˺�\n");
			return;
		}
	}
	
	printf("\n\n\t�ٴ�ȷ�����룺");											//����ȶ�	
	for (i = 0; i<6; i++)
	{
		pd[i] = _getch();
		printf("*");
		if (use[a].pw[i] != pd[i])
		{
			printf("\n�����������벻һ�£�������ע���˺�\n");
			return;
		}
	}																			
	fprintf(fp, "�˺�\t����\n");											//��������ϲ�����ʼ���ļ�������Ϣ�����ø�ʽ�������Ϊ���� 
	fprintf(fp, "%s\t%s\n", use[a].ac, use[a].pw);
	printf("\n��ϲ�㣬ע��ɹ�!\n");										
	fclose(fp);																
	system("pause");														//�ȴ��û��ź� 
	system("cls");             												//ʹ��cls���� 
}

//��¼�˺�
void login()
{
	char ac[30];
	char ad[20], pw;
	int	i, j, a = 0;
	int	flag = 0;

	printf("\t\t*******��¼�ʺŽ���*********\n");
	for (i=0; i<3; i++)                                                        //�������������¼�������¼ʧ�� 
	{
		printf("�������ʺ�:");
		scanf("%s", &ac);
		printf("����������(����س�):");
		for (j=0;j<6;j++)
		{
			pw = _getch();
			printf("*");
			ad[j] = pw;
		}
		FILE *fp;
		fp = fopen("admin.txt", "r");											//���ļ�����
		while (!feof(fp))       												//�ж��ļ��򿪳ɹ� 
		{
			fscanf(fp, "%s %sn", &use[a].ac, &use[a].pw);
			if ((strcmp(ac, use[a].ac) == 0) && (strcmp(ad, use[a].pw) == 0))   //ͬʱ�Ա��û������������ 
			{
				flag = 1;														//�ɹ�flag��1 
				fclose(fp);
				break;
			}
			a++;
		}

		if (flag == 1)
		{
			printf("\n��¼�ɹ�!\n");
			printf("��ӭ����ѧ����Ϣ����ϵͳ!");
			system("pause");
			system("cls");
			while (1)
			{
				menu();															//���ò˵����� 
				interaction();
				system("cls");
			}
		}
		else {
			printf("\n�˺Ż���������������㻹��%d�λ��ᣬ���������룺\n", 2-i);
		}
	}
	
	if (i==3)
	{
		printf("��¼ʧ��!\n");
		return;
	}

}

