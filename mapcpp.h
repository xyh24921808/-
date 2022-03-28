#include<iostream>
#include<vector>
#include<random>
#include<windows.h>
using namespace std;
class meua
{
public:
	meua()
	{
		number = 0;
	}
	int meuaPr()
	{
		number = 0;
		cout << "******************************" << endl;
		cout << "******************************" << endl;
		cout << "**1.play**************0.exit**" << endl;
		cout << "******************************" << endl;
		cout << "******************************" << endl;
		cout << "chosse>:";
		cin >> number;
		return number;
	}
private:
	int number;
};
class map
{
	
public:
	map(int row,int col,int boom=10)
	{
		_ROW = row;
		_COL = col;
		_boom = boom;
		_map.resize(_ROW);
		_map2.resize(_ROW);
		for (auto& x : _map)
		{
			x.resize(_COL, '0');
		}
		for (auto& x : _map2)
		{
			x.resize(_COL, '0');
		}
		while (boom--)
		{
			int i = rand() % row;
			int j = rand() % col;
			_map[i][j] = '1';
		}
	}
	int Bcount(int i,int j)
	{
		int dirx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
		int diry[8] = { 0, 1, 1, 1, 0 ,-1, -1 , -1 };
		int count = 0;
		for (int k = 0; k < 8; k++)
		{
			int x = i + dirx[k];
			int y = j + diry[k];
			if (x < 0 || y < 0 || x >= _ROW || y >= _COL)
			{
				continue;
			}
			count = _map[x][y] == '1' ? count + 1 : count;
		}
		return count;
	} 
	void dfs(int i, int j)
	{
		if (i < 0 || j < 0 || i >= _ROW || j >= _COL||vs[i][j]||_map[i][j]=='1')
		{
			return;
		}
		int count = Bcount(i, j);
		vs[i][j] = 1;
		if (count != 0)
		{
			_map2[i][j] = count + '0';
		}
		else
		{
			_map2[i][j] = '*';
			dfs(i + 1, j);
			dfs(i, j - 1);
			dfs(i, j + 1);
			dfs(i - 1, j);
			dfs(i + 1, j + 1);
			dfs(i + 1, j - 1);
			dfs(i - 1, j + 1);
			dfs(i - 1, j - 1);
		}
	}
	int Payergo()
	{
		system("cls");
		int i = 0;
		int j = 0;
		map_pr();
		int input = 0;
		cout << "请输入操作数"<<"ps: 1:插旗子 0:搜寻方块:>";
		cin >> input;
		if (input >= 2)
		{
			cout << "坐标非法请重新输入" << endl;
			return 0;
		}
		cout << "请输入坐标:>";
		cin >> i >> j;
		i--;
		j--;
		if (i >= _ROW || j >= _COL || i < 0 || j < 0 )
		{
			cout << "坐标非法请重新输入" << endl;
			return 0;
		}
		if (input == 0)
		{
			if (_map[i][j] != '0')
			{
				cout << "坐标非法请重新输入" << endl;
				return 0;
			}
			if (_map[i][j] == '1')
			{
				map_pr2();
				cout << "Good game" << endl;
				return 1;
			}
			dfs(i, j);
		}
		else if(input==1)
		{
			if (_map2[i][j] != '0')
			{
				cout << "坐标非法请重新输入asdaw" << endl;
				return 0;
			}
			else
			{
				if (_map2[i][j] == '^')
				{
					_map2[i][j] = '0';
					if (_map[i][j] == '1')
					{
						_winq--;
					}
				}
				else
				{
					if (_map[i][j] == '1')
					{
						_winq++;
					}
					_map2[i][j] = '^';
				}
			}
		}
		system("cls");
		if (_winq == _boom)
		{
			return 2;
		}
		return 0;
	}
	void map_pr()
	{
		for (int j = 0; j < _COL; j++)
		{
			if (j == _COL / 2+1)
			{
				cout << "地雷数:>" << _boom << endl;
				break;
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
		int i = 0;
		for (auto& x : _map2)
		{
			if (i == 0)
			{
				cout <<"0";
				for (size_t j = 0; j < x.size(); j++)
				{
					printf("%2d ", j + 1);
				}
				cout << endl;
			}
			for (size_t j = 0; j < x.size(); j++)
			{
				if (j == 0)
				{
					printf("%-2d", i + 1);
				}
				if (x[j] == '0')
				{
					cout << "■";
				}
				else if (x[j] == '*')
				{
					cout << "□";
				}
				else
				{
					cout << " " << x[j];
				}
				cout << " ";
			}
			i++;
			cout << endl;
		}
	}
	void map_pr2()
	{
		for (auto& x : _map)
		{
			for (size_t j = 0; j < x.size(); j++)
			{
				cout << x[j];
				cout << " ";
			}
			cout << endl;
		}
	}
private:
	bool vs[100][100] = { 0 };
	vector<string>_map;
	vector<string>_map2;
	int _ROW;
	int _COL;
	int _boom;
	int _winq=0;
};