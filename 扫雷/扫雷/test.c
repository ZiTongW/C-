#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void menu()
{
	printf("****************************\n");
	printf("*********   ɨ��   *********\n");
	printf("*********  1.play  *********\n");
	printf("*********  0.exit  *********\n");
	printf("****************************\n");
}

void game()
{
	char real_mine[ROWS][COLS];		//����׵�����
	char show_mine[ROWS][COLS];		//��ʾ������
	//��ʼ������
	InitBoard(real_mine, ROWS, COLS, '0');
	InitBoard(show_mine, ROWS, COLS, '*');
	//��ӡ����
	DisplayBoard(show_mine, ROW, COL);
	//DisplayBoard(real_mine, ROW, COL);
	//������
	SetMine(real_mine, ROW, COL);
	DisplayBoard(real_mine, ROW, COL);
	//�Ų���
	FindMine(real_mine, show_mine, ROW, COL);
}

void test()
{
	int choice = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("������:>");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			game();
			break;
		case 0:
			printf("*********   �ټ�   *********\n");
			break;
		default:
			printf("�����������������룡\n");
			break;
		}
	} while (choice);
}

int main()
{
	test();
	return 0;
}

