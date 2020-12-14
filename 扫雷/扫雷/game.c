#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char x)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = x;
		}
	}
}

void DisplayBoard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char real_mine[ROWS][COLS], int row, int col)
{
	int count = MINE_COUNT;
	while (count)
	{
		//随机生成雷的下标
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (real_mine[x][y] == '0')
		{
			real_mine[x][y] = '1';
			count--;
		}
	}
}

int GetMineCount(char real_mine[ROWS][COLS], int i, int j)
{
	return  real_mine[i - 1][j - 1] +
		real_mine[i - 1][j] +
		real_mine[i - 1][j + 1] +
		real_mine[i][j - 1] +
		real_mine[i][j + 1] +
		real_mine[i + 1][j - 1] +
		real_mine[i + 1][j] +
		real_mine[i + 1][j + 1] - 8 * '0';
	//将字符转化成数字
}

void FindMine_plus(char real_mine[ROWS][COLS], char show_mine[ROWS][COLS], int i, int j,int* pwin)
{
	while (i > 0 && i<ROWS && j>0 && j< COLS && real_mine[i][j] == '0' && show_mine[i][j] == '*')
	{
		if (GetMineCount(real_mine, i, j) == 0)
		{
			show_mine[i][j] = ' ';
			(*pwin)++;
			FindMine_plus(real_mine, show_mine, i - 1, j, pwin);
			FindMine_plus(real_mine, show_mine, i - 1, j + 1, pwin);
			FindMine_plus(real_mine, show_mine, i, j + 1, pwin);
			FindMine_plus(real_mine, show_mine, i + 1, j + 1, pwin);
			FindMine_plus(real_mine, show_mine, i + 1, j, pwin);
			FindMine_plus(real_mine, show_mine, i, j - 1, pwin);
			FindMine_plus(real_mine, show_mine, i + 1, j - 1, pwin);
			FindMine_plus(real_mine, show_mine, i - 1, j - 1, pwin);
		}
		else
		{
			show_mine[i][j] = GetMineCount(real_mine, i, j) + '0';//将数字转化成字符
			(*pwin)++;
			break;
		}
	}
}

void FindMine(char real_mine[ROWS][COLS], char show_mine[ROWS][COLS], int row, int col)
{
	int i;
	int j;
	int win = 0;
	while (win < row*col - MINE_COUNT)
	{
		printf("请输入坐标:>");
		scanf("%d%d", &i, &j);
		if (i >= 1 && i <= row && j >= 1 && j <= col)
		{
			if (real_mine[i][j] == '1')
			{
				printf("很遗憾，你踩到了雷，游戏结束！\n");
				DisplayBoard(real_mine, row, col);
				break;
			}
			else
			{
				FindMine_plus(real_mine, show_mine, i, j,&win);
				DisplayBoard(show_mine, row, col);
			}
		}
		else
			printf("坐标有误，请重新输入！");
	}
	if (win == row*col - MINE_COUNT)
	{
		printf("恭喜你，排查出了所有雷！");
		DisplayBoard(show_mine, row, col);
	}
}

