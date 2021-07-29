#define _CRT_SECURE_NO_WARNINGS 1
#include"mines.h"

void lnitbrod(char broad[ROWS][COLS],int row,int col)
{
	for (int i = 0; i < row;i++)
	{
		for (int j = 0; j < col; j++)
		{
			broad[i][j] = '0';
		}
	}
}

void lnitbrod2(char broad[ROWS][COLS], int row, int col)
{
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			broad[i][j] = '*';
		}
	}
}

void Layoutbroad(char mine[ROWS][COLS], int row, int col,int count)
{
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		mine[x][y] = '1';
		count--;
	}
}

void showbroad(char broad[ROWS][COLS], int row, int col)
{
	printf("   ");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	printf("   ");
	for (int i = 0; i < row; i++)
	{
		printf("--");
	}
	printf("\n");

	for (int i = 1; i <=row; i++)
	{
		printf("%2d|", i);
		for (int j = 1; j <= col; j++)
		{
			printf(" %c", broad[i][j]);
		}
		printf("\n");
	}
}

int getmine(char mine[ROWS][COLS], int i, int j)
{
	return mine[i + 1][j] + mine[i - 1][j] + mine[i][j - 1] +
		mine[i][j + 1] + mine[i + 1][j + 1] + mine[i - 1][j - 1] +
		mine[i - 1][j + 1] + mine[i + 1][j - 1] - 8 * '0';
}

void Expand(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* win)
{
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (i != 0 || j != 0)
			{
				if (x + i >= 1 && x + i <= ROW && y + j >= 1 && y + j <= COL && mine[x + i][y + j] != '1')
				{
					if (show[x + i][y + j] == '*' && mine[x + i][y + j] == '0')
					{
						int count = getmine(mine, x + i, y + j);
						if (count != 0)
						{
							show[x + i][y + j] = count + '0';
							(*win)++;
						}
						else
						{
							show[x + i][y + j] = ' ';
							Expand(mine, show, x + i, y + j, win);
							(*win)++;
						}
					}
				}
			}
		}
	}
}

void gameover(char broad[ROWS][COLS], int row, int col)
{
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (broad[i][j] == '1')
			{
				printf("* ");
			}
			else
			{
				printf("O ");
			}
		}
		printf("\n");
	}
}

void playgame(char broad[ROWS][COLS],char show[ROWS][COLS])
{
	int x = 0;
	int y = 0;
	int count = 0;
	int win = 0;
	while (win<ROW*COL-count)
	{
		printf("����������(����,����):>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if (broad[x][y] == '1')
			{
				printf("˳�ɱ�ը��game over\n");
				gameover(broad, ROW, COL);
				return;
			}
			else
			{
				count = getmine(broad, x, y);
				if (count != 0)
				{
					show[x][y] = count + '0';
				}
				else
				{
					show[x][y] = ' ';
					system("cls");
					Expand(broad, show, x, y, &win);
				}
				showbroad(show, ROW, COL);
			}
		}
		else
		{
			printf("����Ƿ�������\n");
		}
	}
	if (win - ROW * COL - count == 0)
	{
		printf("��ϲ���׳ɹ�\n");
		return;
	}
}



