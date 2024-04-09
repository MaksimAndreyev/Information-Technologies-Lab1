#include "..\..\GameSystem\GameSystem.h"
#include "GameSysTesterModules.h"
#include <stdlib.h>
#include <time.h>


int testShoot()
{
	srand(time(0));
	//���������� �������
	int shipRow = rand() % 9 + 1;
	int shipColumn = rand() % 9 + 1;
	int hit = rand() % 2;	//������ �� ���� ���������
	int full = rand() % 2;	//будет ли потопление корабля целиком или нет
	int ships = rand() % 2 + 1;		//генерация числа живых кораблей
	int res;
	char field[10][10];
	int target[2] = { shipRow-1, shipColumn-1 };	//���������� ��������
	//��������� ����
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			if ((shipRow == i) && (shipColumn == j))
				field[i][j] = '@';
			else
			{
				field[i][j] = '#';
				if (!full)
				{
					if (shipRow-1 == i && shipColumn == j)
						field[i][j] = '@';
				}
			}
		}	
	if (hit)
	{
		target[0] = shipRow;
		target[1] = shipColumn;
	}
	res = Shoot(field, target, ships);		//����� ����������� �������
	switch (res)
	{
	case 0:
		if (hit == 0)
			return 0;
		else
			return -1;
	case 1:
		if (hit == 1 && full == 0)
			return 0;
		else
			return -1;
	case 2:
		if (hit == 1 && full == 1 && ships == 2)
			return 0;
		else
			return -1;
	case 3:
		if (hit == 1 && full == 1 && ships == 1)
			return 0;
		else
			return -1;
	default:
		return -1;
	}
}


int testPlaceShip()
{
	srand(time(0));
	int decks = rand() % 4 + 1;		//���������� �������
	int column = rand() % 10 + 1;	//������� � ������� ����� �������
	int ship[4][2];		//�������
	char field[10][10];
	for (int i = 0; i < decks; i++)
	{
		ship[i][0] = i;
		ship[i][1] = column;
	}
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			field[i][j] = '#';
	PlaceShip(field, ship, decks);	//����� ����������� �������
	int k = 0;	//���������� ����������� �����
	//�������� �������� ������ �������
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (field[i][j] == '@')
			{
				if ((i == ship[k][0]) && (j == ship[k][1]))
					k += 1;
				else
					return -1;
			}
	if (k != decks)
		return -1;
	return 0;
}