#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROW 3
#define COL 3
#define ROWS ROW+1
#define COLS COL+1

//初始化棋盘
void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set);
//打印棋盘
void DisplayBoard(char arr[ROWS][COLS], int row, int col);
//下棋
void Play(char(*arr)[COLS], int row, int col);
void PlayerPlay(char(*arr)[COLS], int row, int col);//玩家下棋
void ComputerPlay(char(*arr)[COLS], int row, int col);//电脑下棋
//判断输赢or平局
char IsWin(char arr[ROWS][COLS], int row, int col);