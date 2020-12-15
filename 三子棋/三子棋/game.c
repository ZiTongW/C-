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
	printf("玩家请下棋:>");
	scanf("%1d%1d", &i, &j);
	if (i >= 1 && i <= row && j >= 1 && j <= col && arr[i][j] == ' ')
	{
		arr[i][j] = 'O';
		DisplayBoard(arr, row, col);
	}
	else
	{
		printf("坐标有误，请重新输入！\n");
		PlayerPlay(arr, row, col);
	}
}

void ComputerPlay(char(*arr)[COLS], int row, int col)
{
	printf("电脑请下棋:>\n");
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

//判断棋盘是否满了，没有空位即为满了
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

//定义赢和平局的规则，横竖斜有三个相同的棋子相连即为赢
char IsWin(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 1; i<=row; i++)//横连
	{
		if (arr[i][1] == arr[i][2] && arr[i][2] == arr[i][3])
			return arr[i][1];
	}
	for (j = 1; j<=col; j++)//竖连
	{
		if (arr[1][j] == arr[2][j] && arr[2][j] == arr[3][j])
			return arr[1][j];
	}
	if ((arr[1][1] == arr[2][2] && arr[2][2] == arr[3][3]) || (arr[1][3] == arr[2][2] && arr[2][2] == arr[3][3]))//斜连
		return arr[1][1];
	else if (IsFull(arr, row, col))  //棋盘满了即为平局
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
		printf("玩家赢！游戏结束！\n");
	else if (IsWin(arr, row, col) == 'X')
		printf("电脑赢！游戏结束！\n");
	else if (IsWin(arr, row, col) == 'P')
		printf("平局！游戏结束！\n");
}

