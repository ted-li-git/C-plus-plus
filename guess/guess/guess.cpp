#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>   //����Sleep()������ͷ�ļ�
#include<mmsystem.h>

void menu()
{
	printf("   *****************************\n");
	printf("   *****************************\n");
	printf("   ************1.play***********\n");
	printf("   ************0.exit***********\n");
	printf("   **********2.chakan***********\n");
	printf("   *********3.qingkong**********\n");
	printf("   *****************************\n");
	printf("��ѡ��          \n");
}

void game()
{
	system("cls");
	system("color 33"); //������ɫ
	FILE* fp;
	if ((fp = fopen("D:\\caishuziyou.txt", "a+")) == NULL)
	{
		printf("open file error\n");
		return;
	}
	int rand_num = rand() % 100;
	int tmp = 0, t = 0;

	while (1)
	{
		int flag = 0;
		printf("��������Ҫ�µ����֣�");
		scanf("%d", &tmp);
		if (tmp > rand_num)
		{
			printf("�´��ˣ�\n");
			flag = 0;
		}
		if (tmp < rand_num)
		{
			printf("��С�ˣ�\n");
			flag = 0;
		}
		if (tmp == rand_num)
		{
			printf("��ȷ����ϲ��\n");
			printf("������%d��\n", t + 1);


			FILE* fp;
			fp = fopen("D:\\caishuziyou.txt", "w");
			if (fp == NULL)
			{
				printf("create file failed\n");
				return;
			}
			fprintf(fp, "%d", t + 1);
			fclose(fp);
			break;
		}
		if (flag == 0) t++;

		printf(" ���ٲ£�\n");
	}
	printf("\n�����������Ŀ¼");
	getch();

}

void menu2()
{
	system("cls");
	system("color B6"); //������ɫ
	printf("������½ϵͳ������\n");
	getch();
	for (int t = 3; t >= 1; t--)
	{
		system("cls");
		printf("%d", t);
		Sleep(700);
		system("cls");
	}
}

void chakan()
{
	system("cls");
	system("color E0"); //������ɫ

	int t = 0;
	FILE* fp;
	if ((fp = fopen("D:\\caishuziyou.txt", "r")) == NULL)
	{
		printf("can not to open the file!\n");
		exit(0);
	}
	while (fscanf(fp, "%d", &t) != EOF)//�������ļ���β�����
	{
		printf("����ҹ�������%d��\n", t);
	}
	printf("\n�����������Ŀ¼");
	getch();
}

void qk()//���
{
	FILE* fp;
	system("cls");                        //��������,���������Ƿ񱣴����ݣ�ÿ����������������Ļ��ֻ���д˴ε�����
	system("color C0"); //������ɫ
	if ((fp = fopen("D:\\caishuziyou.txt", "w")) == NULL)
	{
		printf("open file error\n");
		return;
	}
	fclose(fp);
	printf("\n����������أ�");
	getch();
}

int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do {
		//while(1)
		//{
		system("cls");
		menu();
		//	printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			menu2();
			game();
			break;
		case 2:
			chakan();
			break;
		case 3:
			qk();
			break;
		case 0:
			exit(0);
			break;
		default:printf("����������������룡");
		}
		//}
	} while (input);
	return 0;
}