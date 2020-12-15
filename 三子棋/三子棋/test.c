#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void menu()
{
	printf("****************************\n");
	printf("*****   ������С��Ϸ   *****\n");
	printf("*********  1.play  *********\n");
	printf("*********  0.exit  *********\n");
	printf("****************************\n");
}

void game()
{
	//��������
	char show[ROWS][COLS];		
	//��ʼ������
	InitBoard(show, ROWS, COLS, ' ');
	//��ӡ����
	DisplayBoard(show, ROW, COL);
	//����
	Play(show, ROW, COL);

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