#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void menu()
{
	printf("****************************\n");
	printf("*********   扫雷   *********\n");
	printf("*********  1.play  *********\n");
	printf("*********  0.exit  *********\n");
	printf("****************************\n");
}

void game()
{
	char real_mine[ROWS][COLS];		//存放雷的棋盘
	char show_mine[ROWS][COLS];		//显示的棋盘
	//初始化棋盘
	InitBoard(real_mine, ROWS, COLS, '0');
	InitBoard(show_mine, ROWS, COLS, '*');
	//打印棋盘
	DisplayBoard(show_mine, ROW, COL);
	//DisplayBoard(real_mine, ROW, COL);
	//布置雷
	SetMine(real_mine, ROW, COL);
	DisplayBoard(real_mine, ROW, COL);
	//排查雷
	FindMine(real_mine, show_mine, ROW, COL);
}

void test()
{
	int choice = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入:>");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			game();
			break;
		case 0:
			printf("*********   再见   *********\n");
			break;
		default:
			printf("输入有误，请重新输入！\n");
			break;
		}
	} while (choice);
}

int main()
{
	test();
	return 0;
}

