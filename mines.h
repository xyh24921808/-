#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define COUNT 10
#define ROW 10
#define COL 10

#define ROWS ROW+2
#define COLS COL+2




void lnitbrod(char broad[ROWS][COLS], int row, int col); //初始化棋盘

void lnitbrod2(char broad[ROWS][COLS], int row, int col); //初始化棋盘2

void Layoutbroad(char mine[ROWS][COLS], int row, int col, int count); //随机布置雷数

void showbroad(char broad[ROWS][COLS], int row, int col); //展示棋盘

void playgame(char broad[ROWS][COLS], char show[ROWS][COLS]); //主游戏函数



