#define _CRT_SECURE_NO_WARNINGS 1
#include"map.h"
void begingame()
{
	meua me;
	int input = 0;
	do
	{
		map m(15, 15,50);
		int ret = 0;
		input = me.meuaPr();
		if (input == 1)
		{
			while (ret==0)
			{
				ret = m.Payergo();
			}
			if (ret == 2)
			{
				system("cls");
				cout << "                      " << "your win!" << endl;
				Sleep(2000);
			}
		}
		else
		{
			cout << "ÊäÈë´íÎóÇëÖØÊÔ" << endl;
		}
	} while (input);
}
int main(void)
{

	begingame();
	return 0;
}