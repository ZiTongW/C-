#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROW 3
#define COL 3
#define ROWS ROW+1
#define COLS COL+1

//��ʼ������
void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set);
//��ӡ����
void DisplayBoard(char arr[ROWS][COLS], int row, int col);
//����
void Play(char(*arr)[COLS], int row, int col);
void PlayerPlay(char(*arr)[COLS], int row, int col);//�������
void ComputerPlay(char(*arr)[COLS], int row, int col);//��������
//�ж���Ӯorƽ��
char IsWin(char arr[ROWS][COLS], int row, int col);