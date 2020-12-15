#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char (*arr)[COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}
void DisplayBoard(char(*arr)[COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("     1   2   3\n");
	for (i = 1; i <= row; i++)
	{
		printf(" %d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("|");
			printf(" %c ", arr[i][j]);
		}
		printf("|\n");
		printf("   |---|---|---|\n");
	}
}

void PlayerPlay(char(*arr)[COLS], int row, int col)
{
	int i;
	int j;
	printf("���������:>");
	scanf("%1d%1d", &i, &j);
	if (i >= 1 && i <= row && j >= 1 && j <= col && arr[i][j] == ' ')
	{
		arr[i][j] = 'O';
		DisplayBoard(arr, row, col);
	}
	else
	{
		printf("�����������������룡\n");
		PlayerPlay(arr, row, col);
	}
}

void ComputerPlay(char(*arr)[COLS], int row, int col)
{
	printf("����������:>\n");
	int count = 1;
	while (count)
	{
		int i = rand() % row + 1;
		int j = rand() % col + 1;
		if (arr[i][j] == ' ')
		{
			arr[i][j] = 'X';
			DisplayBoard(arr, row, col);
			count--;
		}
	}		
}

//�ж������Ƿ����ˣ�û�п�λ��Ϊ����
int IsFull(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 1; i<=row; i++)
	{
		for (j = 1; j<=col; j++)
		{
			if (arr[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

//����Ӯ��ƽ�ֵĹ��򣬺���б��������ͬ������������ΪӮ
char IsWin(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 1; i<=row; i++)//����
	{
		if (arr[i][1] == arr[i][2] && arr[i][2] == arr[i][3])
			return arr[i][1];
	}
	for (j = 1; j<=col; j++)//����
	{
		if (arr[1][j] == arr[2][j] && arr[2][j] == arr[3][j])
			return arr[1][j];
	}
	if ((arr[1][1] == arr[2][2] && arr[2][2] == arr[3][3]) || (arr[1][3] == arr[2][2] && arr[2][2] == arr[3][3]))//б��
		return arr[1][1];
	else if (IsFull(arr, row, col))  //�������˼�Ϊƽ��
		return 'P';
	else
		return ' ';
}


void Play(char(*arr)[COLS], int row, int col)
{
	int win = 0;
	while (IsWin(arr, row, col) == ' ')
	{
		PlayerPlay(arr, row, col);
		if (IsWin(arr, row, col) != ' ')
			break;
		ComputerPlay(arr, row, col);
		if (IsWin(arr, row, col) != ' ')
			break;
	}
	if (IsWin(arr, row, col) == 'O')
		printf("���Ӯ����Ϸ������\n");
	else if (IsWin(arr, row, col) == 'X')
		printf("����Ӯ����Ϸ������\n");
	else if (IsWin(arr, row, col) == 'P')
		printf("ƽ�֣���Ϸ������\n");
}

