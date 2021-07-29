#define _CRT_SECURE_NO_WARNINGS 1
#include"mines.h"

void neum()
{
	printf("-----------------------------------\n");
	printf("------------1.开始游戏-------------\n");
	printf("------------0.退出游戏-------------\n");
	printf("-----------------------------------\n");
}

void game()
{
	srand((unsigned int)time(NULL));
	char broad[ROWS][COLS];
	char show[ROWS][COLS];
	lnitbrod(broad, ROWS, COLS);
	lnitbrod2(show, ROW, COL);
	Layoutbroad(broad, ROW, COL, COUNT);
	showbroad(show, ROW, COL);
	playgame(broad, show);
}

int main(void)
{
	int input = 0;
	do
	{
		neum();
		printf("请输入:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			system("cls");
			game();
			break;
		}
		case 0:
		{
			printf("退出游戏\n");
			break;
		}
		default:
			printf("选择错误请重选\n");
			break;
		}
	} while (input);
	return 0;
}