#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>   //下面Sleep()函数的头文件
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
	printf("请选择：          \n");
}

void game()
{
	system("cls");
	system("color 33"); //设置颜色
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
		printf("请输入你要猜的数字：");
		scanf("%d", &tmp);
		if (tmp > rand_num)
		{
			printf("猜大了！\n");
			flag = 0;
		}
		if (tmp < rand_num)
		{
			printf("猜小了！\n");
			flag = 0;
		}
		if (tmp == rand_num)
		{
			printf("正确！恭喜！\n");
			printf("共用了%d次\n", t + 1);


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

		printf(" 你再猜：\n");
	}
	printf("\n按任意键返回目录");
	getch();

}

void menu2()
{
	system("cls");
	system("color B6"); //设置颜色
	printf("即将登陆系统！！！\n");
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
	system("color E0"); //设置颜色

	int t = 0;
	FILE* fp;
	if ((fp = fopen("D:\\caishuziyou.txt", "r")) == NULL)
	{
		printf("can not to open the file!\n");
		exit(0);
	}
	while (fscanf(fp, "%d", &t) != EOF)//若不到文件结尾则继续
	{
		printf("此玩家共进行了%d次\n", t);
	}
	printf("\n按任意键返回目录");
	getch();
}

void qk()//清空
{
	FILE* fp;
	system("cls");                        //清屏函数,不管下面是否保存数据，每次输入新数据是屏幕上只能有此次的数据
	system("color C0"); //设置颜色
	if ((fp = fopen("D:\\caishuziyou.txt", "w")) == NULL)
	{
		printf("open file error\n");
		return;
	}
	fclose(fp);
	printf("\n按任意键返回！");
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
		//	printf("请选择：");
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
		default:printf("输入错误！请重新输入！");
		}
		//}
	} while (input);
	return 0;
}