#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MINE_COUNT 10

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

//≥ı ºªØ∆Â≈Ã
void InitBoard(char arr[ROWS][COLS], int rows, int cols, char x);
//¥Ú”°∆Â≈Ã
void DisplayBoard(char arr[ROWS][COLS], int row, int col);
//≤º÷√¿◊
void SetMine(char real_mine[ROWS][COLS], int row, int col);
//≈≈≤È¿◊
void FindMine(char real_mine[ROWS][COLS], char show_mine[ROWS][COLS], int row, int col);
