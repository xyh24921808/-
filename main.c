#define _CRT_SECURE_NO_WARNINGS 1
#include"mines.h"

void neum()
{
	printf("-----------------------------------\n");
	printf("------------1.��ʼ��Ϸ-------------\n");
	printf("------------0.�˳���Ϸ-------------\n");
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
		printf("������:>");
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
			printf("�˳���Ϸ\n");
			break;
		}
		default:
			printf("ѡ���������ѡ\n");
			break;
		}
	} while (input);
	return 0;
}