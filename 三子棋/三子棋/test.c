#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void menu()
{
	printf("****************************\n");
	printf("*****   三子棋小游戏   *****\n");
	printf("*********  1.play  *********\n");
	printf("*********  0.exit  *********\n");
	printf("****************************\n");
}

void game()
{
	//定义棋盘
	char show[ROWS][COLS];		
	//初始化棋盘
	InitBoard(show, ROWS, COLS, ' ');
	//打印棋盘
	DisplayBoard(show, ROW, COL);
	//下棋
	Play(show, ROW, COL);

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