#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define COUNT 10
#define ROW 10
#define COL 10

#define ROWS ROW+2
#define COLS COL+2




void lnitbrod(char broad[ROWS][COLS], int row, int col); //��ʼ������

void lnitbrod2(char broad[ROWS][COLS], int row, int col); //��ʼ������2

void Layoutbroad(char mine[ROWS][COLS], int row, int col, int count); //�����������

void showbroad(char broad[ROWS][COLS], int row, int col); //չʾ����

void playgame(char broad[ROWS][COLS], char show[ROWS][COLS]); //����Ϸ����



